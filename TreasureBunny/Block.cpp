#include"DxLib.h"
#include"Block.h"


Block::Block(int basemodel, VECTOR pos,int kindsNumber,COLOR_F color, int parentnumber, int startstepNumber,bool gool)
{
	model = basemodel;
	position = pos;
	createPosition = pos;
	kinds = kindsNumber;
	isGool=gool;
	completeStep=true;
	parentNumber = parentnumber;
	//MV1SetScale(model, VGet(1.0f, 1.0f, 2.0f));
	MV1SetPosition(model, position);
	MV1SetupCollInfo(model, -1, 5, 5, 5);
	MV1SetupReferenceMesh(model, -1, TRUE);
	int tmp=MV1GetMeshNum(model);
	polygonList = MV1GetReferenceMesh(model, -1, TRUE);
	isTransparent = false;
	step = startstepNumber;
	if (parentNumber != BaseParentNumber)
	{
		step += DownStepNoBaseParent;
	}
	nextStep = step;
	startStep = step;

	if (kinds >= 2)
	{
		MV1SetMaterialDifColor(model, 0, color);
	}
}
Block::~Block()
{
	//MV1DeleteModel(model);
}
void Block::UpDate()
{
	MV1RefreshCollInfo(model, -1);
	MV1SetupReferenceMesh(model, -1, TRUE);

}
bool Block::SetMoveCloser(VECTOR moveVector, bool& isCoolDown,float StartPosition, int& moveDirection)
{
	bool isMove=false;
	//移動させ切っていたら次の移動ができる
	if (completeStep)
	{
		if (moveVector.z < 0.0f&&step<MaxStep)
		{
			nextStep++;
			completeStep=false;
			moveDirection = 2;
		}
		else if (moveVector.z > 0.0f&&step>MinStep)
		{
			nextStep--;
			completeStep=false;
			moveDirection = 3;
		}
	}
	//次のステップによって行き過ぎたときの処理を変える
	if (step != nextStep)
	{
		moveVector = VSub(moveVector, VGet(moveVector.x, moveVector.y, 0));
		position = VAdd(position, moveVector);
		float nextSetPosition= StartPosition-CorrectionZ*nextStep;
		if (step < nextStep)
		{
			if (position.z< nextSetPosition)
			{
				step = nextStep;
				position.z= nextSetPosition;
				completeStep=true;
				isCoolDown=true;
				moveDirection = 0;
			}
		}
		else if (step > nextStep)
		{
			if (position.z > nextSetPosition)
			{
				step = nextStep;
				position.z= nextSetPosition;
				completeStep=true;
				isCoolDown=true;
				moveDirection = 0;
			}
		}
		MV1SetPosition(model,position);
		UpDate();
	}
	if (completeStep == false)
	{
		isMove=true;
	}
	return isMove;
}
void Block::SetMoveFarther(VECTOR closerPosition, float correctionZ)
{
	int magnification = kinds + 1;
	position = VGet(closerPosition.x, closerPosition.y, closerPosition.z + correctionZ * magnification);
	MV1SetPosition(model, position);
	UpDate();
}
void Block::SetTransparent(bool Transparent)
{
	isTransparent = Transparent;
	if (isTransparent)
	{
		MV1SetOpacityRate(model, SetCleanness);
	}
	else
	{
		MV1SetOpacityRate(model, setOpacity);
	}

}
void Block::SetMeshTransparent()
{
	
	for (int i = 1; i < MeshNumber; i++)
	{
		float transparent = MV1GetMeshOpacityRate(model, i);
		if (position.z>=14.9f&& transparent== setOpacity)
		{
			MV1SetMeshOpacityRate(model, i, SetCleanness);

		}
		else if(position.z < 14.9f && transparent == SetCleanness||step>1)
		{
			MV1SetMeshOpacityRate(model, i, setOpacity);
		}
	}

}
void Block::ResetBlock()
{
	position = createPosition;
	step = startStep;
	nextStep = startStep;
	MV1SetPosition(model, position);
	MV1SetupCollInfo(model, -1, 1, 1, 1);

}
void Block::Draw()
{
	MV1DrawModel(model);

}