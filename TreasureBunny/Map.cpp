#define _CRT_SECURE_NO_WARNINGS
#include"DxLib.h"
#include"Block.h"
#include"Map.h"

std::vector<Block> Map::block;
COLOR_F	Map::colorBlock[3] = {};//ブロックの前面の色　0：赤　1：緑　2：青
int Map::cell[MaxMap][MapY][MapX] = {0};	//ブロック配置配列
int Map::soilCell[SoilY][SoilX] = {0};	//地面配置配列
int Map::baseModel[BlockKinds + AccessoriesKinds] = {0};	//元にするモデル
int Map::SkyModel = {0};			//スカイドームモデル
int Map::coinModel = {0};			//コインモデル
int Map::coinImg = {0};			//コインイメージ
bool Map::isFirstConstructor = false;

Map::Map()
	:mapNumber(0)
	,blockNumber(0)
	,soilNumber(0)
	,isCoolDown(false)
	,coolDown(0)
	,resetCount(0)
{
	if (isFirstConstructor == false)
	{
		FILE* fp = NULL;
		//ファイルを開く
		fopen_s(&fp, "Map/SoilBase.csv", "r");
		if (fp != 0)
		{
			for (int i = 0; i < SoilY; i++)
			{
				for (int j = 0; j < SoilX; j++)
				{
					fscanf(fp, "%d,", &this->soilCell[i][j]);
					soilCell[i][j] -= 1;
				}
			}
		}
		fclose(fp);
		//マップ読み込み
		LoadMap("Map/TutorialStage.csv");
		LoadMap("Map/FirstStage.csv");
		LoadMap("Map/SecondStage.csv");
		LoadMap("Map/ThirdStage.csv");
		LoadMap("Map/FourStage.csv");

		block.reserve(MapX * MapY * 3 + SoilX * SoilY);
		SkyModel = MV1LoadModel("Model/Sky.mv1");

		baseModel[0] = MV1LoadModel("Model/SecondLevel.mv1");
		baseModel[1] = MV1LoadModel("Model/ThirdLevel.mv1");
		baseModel[2] = MV1LoadModel("Model/BlockFirst.mv1");
		baseModel[3] = MV1LoadModel("Model/BlockRed.mv1");
		baseModel[4] = MV1LoadModel("Model/coin_stack_large.mv1");
		coinModel = MV1DuplicateModel(baseModel[4]);
		coinImg = LoadGraph("Img/coin.png");
		colorBlock[0] = GetColorF(1.0f, 0.4f, 0.4f, 1.0f);
		colorBlock[1] = GetColorF(0.4f, 1.0f, 0.4f, 1.0f);
		colorBlock[2] = GetColorF(0.4f, 0.4f, 1.0f, 1.0f);
		isFirstConstructor = true;
	}

	float z = InitializePositionZ - CorrectionZ;
	for (int i = 0; i < SoilY; i++)
	{
		float x = -4.0f;
		for (int j = 0; j < SoilX; j++)
		{
			int kinds = soilCell[i][j];
			bool putFlag = false;
			int correbase = 0;
			if (kinds >= 0)
			{
				putFlag = true;
				if (kinds > NoBaseBlock)
				{
					correbase = kinds - NoBaseBlock;
				}
			}
			if (putFlag)
			{
				block.push_back(Block(MV1DuplicateModel(baseModel[kinds - correbase]), VGet(x, InitializePositionY, z), kinds, colorBlock[kinds - NoBaseBlock], BaseParentNumber, FirstStepNumber, false));
				soilNumber++;
			}
			x += CorrectionX;
		}
		z -= CorrectionZ;
	}

}
Map::~Map()
{
	block.clear();
}
int Map::GetBlockModel(int i)const
{
	return block[i].GetModel();
}
int Map::GetBlockKinds(int i)const
{
	return block[i].GetKinds();
}
bool Map::GetIsGool(int i)const 
{
	return block[i].GetGool();
}
int Map::GetBlockStep(int i)const
{
	return block[i].GetStep();
}
bool Map::GetIsTransparent(int i)const
{
	return block[i].GetIsTransparent();
}
void Map::Initialize()
{
	//作った場所に戻す
	for (int i = soilNumber; i < soilNumber + blockNumber; i++)
	{
		block[i].ResetBlock();
		resetCount = 0;
	}
}
void Map::LoadMap(const char* fileName)
{
	static int Number = 0;
	FILE* fp = NULL;
	fopen_s(&fp, fileName, "r");
	if (fp != 0)
	{
		for (int i = 0; i < MapY; i++)
		{
			for (int j = 0; j < MapX; j++)
			{
				fscanf(fp, "%d,", &this->cell[Number][i][j]);
				cell[Number][i][j] -= 1;
			}
		}
	}
	fclose(fp);
	Number++;
}
void Map::UpDate()
{
	ResetBlock();
	SetTransparent();
	EndCoolDown();
}
void Map::DrawMap(VECTOR playerPos)
{

	MV1SetPosition(SkyModel, playerPos);
	MV1DrawModel(SkyModel);
	int sumNumber = soilNumber + blockNumber;
	for (int i = 0; i < sumNumber; i++)
	{
		block[i].Draw();
		if (block[i].GetGool() == true)
		{
			if (block[i].GetStep() != 0)
			{
				MV1SetPosition(coinModel, VAdd(block[i].GetPosition(),VGet(0.0f, CoinCorrectionY,0.0f)));
				MV1DrawModel(coinModel);
			}
			DrawBillboard3D(VAdd(block[i].GetPosition(), VGet(0.0f, 0.0f, CoinImgCorrectionZ)), CenterXY, CenterXY, CoinImgSize, CoinImgAngle, coinImg, TRUE);
		}
	}

}
void Map::DrawSky()
{
	MV1SetPosition(SkyModel, VGet(0.0f,0.0f,0.0f));
}
void Map::SetMap()
{
	float y = MapY *CorrectionY;
	//新しいブロックを生成
	for (int i = 0; i < MapY; i++)
	{
		float x = 0.0f;
		for (int j = 0; j < MapX; j++)
		{
			int kinds = cell[mapNumber][i][j];
			bool putFlag = false;
			int correbase = 0;
			int correGool = 0;//ゴールをほかのブロックと同じようにするためのずらし
			bool isGool = false;
			if (kinds >= 0)
			{
				putFlag = true;
				if (kinds > 10)
				{
					isGool = true;
					correGool = 10;
				}
				if (kinds > NoBaseBlock)
				{
					correbase = kinds - NoBaseBlock;
				}
			}
			if (putFlag)
			{
				block.push_back(Block(MV1DuplicateModel(baseModel[kinds - correbase]), VGet(x, y, InitializePositionZ),kinds - correGool,colorBlock[kinds- NoBaseBlock-correGool], BaseParentNumber, FirstStepNumber, isGool));
				blockNumber++;
			}
			x += CorrectionX;
		}
		y -= CorrectionY;
	}
	int maxNumber = soilNumber +blockNumber;
	for (int i = soilNumber; i < maxNumber; i++)
	{
		VECTOR positon = block[i].GetPosition();
		int kinds = 0;
		//黄色ブロック生成
		block.push_back(Block(MV1DuplicateModel(baseModel[0]), VGet(positon.x, positon.y, InitializePositionZ+CorrectionZ), kinds, colorBlock[kinds - NoBaseBlock], i, FirstStepNumber,false));
		blockNumber++;
		kinds = 1;
		//赤ブロック生成
		block.push_back(Block(MV1DuplicateModel(baseModel[1]), VGet(positon.x, positon.y, InitializePositionZ + CorrectionZ*2), kinds, colorBlock[kinds - NoBaseBlock], i, FirstStepNumber,false));
		blockNumber++;
	}
}
bool Map::BlockMove(VECTOR moveVector,int hitNumber,int& moveDirection, int graspDirection)
{
	int kinds = block[hitNumber].GetKinds();
	int number[MapY * MapX*3] = {0};
	int count = 0;
	bool tmpCoolDown=false;
	bool isMove=false;
	number[count] = hitNumber;
	if (kinds == 0 || kinds == 1)
	{
		number[count] = block[hitNumber].GetParentNumber();
		kinds = block[number[count]].GetKinds();
	}
	count++;
	if (isCoolDown==false)
	{
		//つかんだ場所から隣接するブロックを探す
		for (int i = 0; i < count; i++)
		{
			VECTOR pos=	block[number[i]].GetPosition();
			pos =VSub(pos, VGet(-CorrectionX, CorrectionY, 0.0f));
			int xNumber = int(pos.x / CorrectionX);
			int yNumber = int(pos.y / CorrectionY);
			yNumber =abs(yNumber - MapY);
			pos= block[number[i]].GetPosition();
			for (int j = 0; j < 4; j++)
			{
				//左
				if (j == 0&& xNumber !=1)
				{
					SearchBlock(count,number,i,kinds,false,true, xNumber,pos);
				}
				//右
				else if (j == 1 && xNumber != MapX)
				{
					SearchBlock(count, number, i, kinds, true, true, xNumber, pos);
				}
				//上
				else if (j == 2 && yNumber != 1)
				{
					SearchBlock(count, number, i, kinds, false, false, yNumber, pos);
				}
				//下
				else if (j == 3 && yNumber != MapY)
				{
					SearchBlock(count, number, i, kinds, true, false, yNumber, pos);
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			VECTOR closerPosition= block[number[i]].GetPosition();
			//一番手前のブロックを動かす
			isMove=block[number[i]].SetMoveCloser(moveVector, tmpCoolDown,InitializePositionZ,moveDirection);
			//一番前のブロックに後ろのブロックを追従させる
			for (int j = soilNumber; j < soilNumber + blockNumber; j++)
			{
				if (block[j].GetParentNumber() == number[i])
				{
					block[j].SetMoveFarther(closerPosition, CorrectionZ);
				}
			}
		}
		if (tmpCoolDown)
		{
			isCoolDown=true;
		}
	}
	return isMove;
}
void Map::SearchBlock(int& count, int number[], int numberPoint, int kinds, bool isPlus, bool isX, int startPoint,VECTOR pos)
{
	int pointMove=0;
	int endNumber = 0;
	int startNumber = 0;
	float correction = 0;
	int CountBlockY = 1;
	//ブロック番号を足すか引くか
	if (isPlus)
	{
		if (isX)
		{
			pointMove = SearchBlockX;
			endNumber = MapX- startPoint+1;
			correction = CorrectionX;
		}
		else
		{
			pointMove = SearchBlockY;
			endNumber = blockNumber+ soilNumber -number[numberPoint];
			correction = -CorrectionY;
		}
		startNumber = 1 ;
	}
	else
	{
		if (isX)
		{
			pointMove = -SearchBlockX;
			correction = -CorrectionX;
			endNumber = startPoint;
		}
		else
		{
			pointMove = -SearchBlockY;
			correction = CorrectionY;
			endNumber = number[numberPoint]+1-soilNumber;
		}
		startNumber = 1;
	}
	for (int i = startNumber; i < endNumber; i++)
	{
		//同じではないなら即座に次の方向へ
		int tmpNumber = number[numberPoint] + i * pointMove;
		int tmpKinds=block[tmpNumber].GetKinds();
		int parentNumber = block[tmpNumber].GetParentNumber();
		VECTOR searchPosition=block[tmpNumber].GetPosition();
		bool searchX = isX == true && pos.y == searchPosition.y && searchPosition.x == pos.x + correction * i && parentNumber == -1;
		bool searchY = isX == false && pos.x == searchPosition.x && searchPosition.y == pos.y + correction * CountBlockY && parentNumber==-1;
		if (kinds == tmpKinds&&(searchX|| searchY))
		{
			bool checkSame = false;
			for (int j = 0; j < count; j++)
			{
				if (number[j] == tmpNumber)
				{
					checkSame = true;
					break;
				}
			}
			if (checkSame == false)
			{
				number[count] = tmpNumber;
				count++;
				CountBlockY++;
			}
		}
		else if(isX|| isX==false&&((isPlus&&searchPosition.y< pos.y + correction * CountBlockY)||
					  (isPlus==false && searchPosition.y > pos.y + correction * CountBlockY)))
		{
			break;
		}
	}
}
void Map::EndCoolDown()
{
	if (isCoolDown)
	{
		if (coolDown < PullPushBlockCoolDown)
		{
			coolDown++;
		}
		else
		{
			isCoolDown = false;
			coolDown = 0;
		}
	}
}
void Map::SetTransparent()
{
	int sumNumber = soilNumber + blockNumber;
	for (int i = soilNumber; i < sumNumber; i++)
	{
		VECTOR position = block[i].GetPosition();
		bool transparent = false;
		if (position.z > StopTransparent &&block[i].GetIsTransparent()==false)
		{
			transparent = true;
			block[i].SetTransparent(transparent);
		}
		else if (position.z <= StopTransparent &&block[i].GetIsTransparent() == true)
		{
			block[i].SetTransparent(transparent);
		}
	}
}
void Map::ResetBlock()
{
	//コントローラー変更予定
	//右トリガー
	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_6)
	{
		resetCount++;
		if (resetCount >= ResetTiming)
		{
			for (int i = soilNumber; i < soilNumber + blockNumber; i++)
			{
				block[i].ResetBlock();
				resetCount = 0;
			}
		}
	}
	else
	{
		resetCount = 0;
	}
}
void Map::SetMapNumber(int number)
{
	mapNumber = number;
}