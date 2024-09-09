#include"DxLib.h"
#include"Collision.h"
#include"Player.h"
#include"Map.h"
#include"Block.h"
Collision::Collision()
{
    //処理なし
}
Collision::~Collision()
{
    //処理なし
}
VECTOR Collision::HitBlockPlayer(Map& map, Player& player, VECTOR& moveVector,bool &isHitGool)
{
    bool isFall = true;
    VECTOR endPosition = player.GetPosition();
    int sumNumber = map.GetSoilNumber() + map.GetBlockNuber();
    bool move = false;
    if (player.GetGraspMove()&&moveVector.z!=0.0f)
    {
        move = true;
    }
    for (int i = 0; i < sumNumber; i++)
    {
        int modelHandle = map.GetBlockModel(i);
        float positionY = MV1GetPosition(modelHandle).y;
        //透明であれば処理しない
        if (map.GetIsTransparent(i) == false)
        {
            if (i>=map.GetSoilNumber()&&map.GetBlockStep(i)==0)
            {
                //処理なし
            }
            else
            {
                OnCollision(player, modelHandle, moveVector, map.GetIsGool(i), isFall, isHitGool);
            }
        }
    }
    if (isFall)
    {
        player.NoHitFloor();
    }
    //ブロックを移動させ始めた方向にしか移動出来ないようにする
    if (player.GetGraspMove())
    {
        moveVector.y = 0;
        if (moveVector.z < 0.0f && player.GetGraspMoveDirection() == 2)
        {
            moveVector.z = -player.GetMoveSpeed();
        }
        else if (moveVector.z < 0.0f && player.GetGraspMoveDirection() == 3)
        {
            moveVector.z = player.GetMoveSpeed();
        }
        else if (move&& player.GetGraspMoveDirection() == 2)
        {
            moveVector.z= -player.GetMoveSpeed();
        }
        else if (move&& player.GetGraspMoveDirection() == 3)
        {
            moveVector.z = player.GetMoveSpeed();
        }
    }
    endPosition = VAdd(endPosition,moveVector);
    return endPosition;

}
///// <summary>
///// 検出されたポリゴンが壁ポリゴン( ＸＺ平面に垂直なポリゴン )か床ポリゴン( ＸＺ平面に垂直ではないポリゴン )かを判断し、保存する
///// </summary>
//void Collision::AnalyzeWallAndFloor(MV1_COLL_RESULT_POLY_DIM hitDim, const VECTOR& checkPosition)
//{
//    // 壁ポリゴンと床ポリゴンの数を初期化する
//    wallNum = 0;
//    floorNum = 0;
//
//    // 検出されたポリゴンの数だけ繰り返し
//    for (int i = 0; i < hitDim.HitNum; i++)
//    {
//        // ＸＺ平面に垂直かどうかはポリゴンの法線のＹ成分が０に限りなく近いかどうかで判断する
//        if (hitDim.Dim[i].Normal.y < 0.000001f && hitDim.Dim[i].Normal.y > -0.000001f)
//        {
//            // 壁ポリゴンと判断された場合でも、プレイヤーのＹ座標＋１．０ｆより高いポリゴンのみ当たり判定を行う
//            if (hitDim.Dim[i].Position[0].y > checkPosition.y + 1.0f ||
//                hitDim.Dim[i].Position[1].y > checkPosition.y + 1.0f ||
//                hitDim.Dim[i].Position[2].y > checkPosition.y + 1.0f)
//            {
//                // ポリゴンの数が列挙できる限界数に達していなかったらポリゴンを配列に追加
//                if (wallNum < MaxHitColl)
//                {
//                    // ポリゴンの構造体のアドレスを壁ポリゴンポインタ配列に保存する
//                    wall[wallNum] = &hitDim.Dim[i];
//                    wallNum++;
//                }
//            }
//        }
//        else
//        {
//            // ポリゴンの数が列挙できる限界数に達していなかったらポリゴンを配列に追加
//            if (floorNum < MaxHitColl)
//            {
//                // ポリゴンの構造体のアドレスを床ポリゴンポインタ配列に保存する
//                floor[floorNum] = &hitDim.Dim[i];
//                floorNum++;
//            }
//        }
//    }
//}
//
///// <summary>
///// 壁ポリゴンとの当たりをチェックし、補正すべき移動ベクトルを返す
///// </summary>
//VECTOR Collision::CheckHitWithWall(Player& player, const VECTOR& checkPosition)
//{
//    VECTOR fixedPos = checkPosition;
//
//    // 壁の数が無かったら早期リターン
//    if (wallNum == 0)
//    {
//        return fixedPos;
//    }
//
//    // 壁からの押し出し処理を試みる最大数だけ繰り返し
//    for (int k = 0; k < HitTryNum; k++)
//    {
//        // 当たる可能性のある壁ポリゴンを全て見る
//        bool isHitWall = false;
//        for (int i = 0; i < wallNum; i++)
//        {
//            // i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
//            auto poly = wall[i];
//
//            // プレイヤーと当たっているなら
//            if (HitCheck_Capsule_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), HitWidth, poly->Position[0], poly->Position[1], poly->Position[2]) == TRUE)
//            {
//                // 規定距離分プレイヤーを壁の法線方向に移動させる
//                // 移動後の位置を更新（移動後の場所を補正）
//                fixedPos = VAdd(fixedPos, VScale(poly->Normal, HitSlideLength));
//
//                // 移動した壁ポリゴンと接触しているかどうかを判定
//                for (int j = 0; j < wallNum; j++)
//                {
//                    // 当たっていたらループを抜ける
//                    poly = wall[j];
//                    if (HitCheck_Capsule_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), HitWidth, poly->Position[0], poly->Position[1], poly->Position[2]) == TRUE)
//                    {
//                        isHitWall = true;
//                        break;
//                    }
//                }
//
//                // 全てのポリゴンと当たっていなかったらここでループ終了
//                if (isHitWall == false)
//                {
//                    break;
//                }
//            }
//        }
//
//        // 全部のポリゴンで押し出しを試みる前に
//        // 全ての壁ポリゴンと接触しなくなったらループから抜ける
//        if (isHitWall == false)
//        {
//            break;
//        }
//    }
//
//    return fixedPos;
//}
//
///// <summary>
///// 床ポリゴンとの当たりをチェックし、補正すべき移動ベクトルを返す
///// </summary>
//VECTOR Collision::CheckHitWithFloor(Player& player, const VECTOR& checkPosition)
//{
//    VECTOR fixedPos = checkPosition;
//
//    // 床の数が無かったら早期リターン
//    if (floorNum == 0)
//    {
//        return fixedPos;
//    }
//
//    // ジャンプ中且つ上昇中の場合は処理を分岐
//    if (player.GetStatus() == Player::Status::JAMP && player.GetJumpPower() > 0.0f)
//    {
//        // 天井に頭をぶつける処理を行う
//        // 一番低い天井にぶつける為の判定用変数を初期化
//        bool isHitRoof = false;
//        float minY = 0.0f;
//
//        // 床ポリゴンの数だけ繰り返し
//        for (int i = 0; i < floorNum; i++)
//        {
//            auto poly = floor[i];	// i番目の床ポリゴンのアドレス
//
//            // 足先から頭の高さまでの間でポリゴンと接触しているかどうかを判定
//            HITRESULT_LINE lineResult;	// 線分とポリゴンとの当たり判定の結果を代入する構造体
//            lineResult = HitCheck_Line_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//
//            // 接触していなかったら何もしない
//            if (lineResult.HitFlag == TRUE)
//            {
//                // 既にポリゴンに当たっていて、且つ今まで検出した天井ポリゴンより高い場合は何もしない
//                if (!(isHitRoof == true && minY < lineResult.Position.y))
//                {
//                    // ポリゴンに当たったフラグを立てる
//                    isHitRoof = true;
//
//                    // 接触したＹ座標を保存する
//                    minY = lineResult.Position.y;
//                }
//            }
//        }
//
//        // 接触したポリゴンがあれば
//        if (isHitRoof == true)
//        {
//            // 接触した場合はプレイヤーのＹ座標を接触座標を元に更新
//            fixedPos.y = minY - HitHeight;
//            player.OnHitCeiling();
//        }
//    }
//    // 下降中かジャンプ中ではない場合の処理
//    else
//    {
//        bool isHitFloor = false;
//        float maxY = 0.0f;
//
//        // 床ポリゴンの数だけ繰り返し
//        for (int i = 0; i < floorNum; i++)
//        {
//            auto poly = floor[i];	// i番目の床ポリゴンのアドレス
//
//            // ジャンプ中かどうかで処理を分岐
//            HITRESULT_LINE lineResult;	// 線分とポリゴンとの当たり判定の結果を代入する構造体
//            if (player.GetStatus() == Player::Status::JAMP)
//            {
//                // ジャンプ中の場合は頭の先から足先より少し低い位置の間で当たっているかを判定
//                lineResult = HitCheck_Line_Triangle(VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), VAdd(fixedPos, VGet(0.0f, -1.0f, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//            }
//            else
//            {
//                // 走っている場合は頭の先からそこそこ低い位置の間で当たっているかを判定( 傾斜で落下状態に移行してしまわない為 )
//                lineResult = HitCheck_Line_Triangle(VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), VAdd(fixedPos, VGet(0.0f, -40.0f, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//            }
//
//            // 既に当たったポリゴンがあり、且つ今まで検出した床ポリゴンより低い場合は何もしない
//            if (lineResult.HitFlag == TRUE)
//            {
//                if (!(isHitFloor == true && maxY > lineResult.Position.y))
//                {
//                    // 接触したＹ座標を保存する
//                    isHitFloor = true;
//                    maxY = lineResult.Position.y;
//                }
//            }
//        }
//
//        // 床ポリゴンに当たった
//        if (isHitFloor == true)
//        {
//            // 接触したポリゴンで一番高いＹ座標をプレイヤーのＹ座標にする
//            fixedPos.y = maxY;
//
//            // 床に当たった時
//            player.OnHitFloor();
//        }
//        else
//        {
//            // 床コリジョンに当たっていなくて且つジャンプ状態ではなかった場合は落下状態
//            player.OnFall();
//        }
//    }
//
//    return fixedPos;
//}

void Collision::OnCollision(Player& player, int model, VECTOR& moveVector, bool isGool, bool& isFall,bool& isHitGool)
{
    MV1_COLL_RESULT_POLY_DIM hitFlag;
    VECTOR calcEndPositionTmp = VAdd(player.GetPosition(), moveVector);
    calcEndPositionTmp.y += CorrectionY;
    float moveVectorY = moveVector.y;
    for (int i = 0; i < MaxTry; i++)
    {
        hitFlag = MV1CollCheck_Sphere(model, -1, calcEndPositionTmp, radius);
        if (hitFlag.HitNum != 0)
        {
            for (int j = 0; j < hitFlag.HitNum; j++)
            {
                bool wall = hitFlag.Dim[j].Normal.y < 0.000001f && hitFlag.Dim[j].Normal.y > -0.000001f;
                if (hitFlag.Dim[j].Normal.x == 1.0f || hitFlag.Dim[j].Normal.x == -1.0f)
                {
                    wall = true;
                }
                else if(hitFlag.Dim[j].Normal.z == 1.0f || hitFlag.Dim[j].Normal.z == -1.0f)
                {
                    wall = true;
                }
                
                VECTOR tmp = VSub(calcEndPositionTmp, hitFlag.Dim[j].Position[0]);
                //内積
;                float  dot = VDot(hitFlag.Dim[j].Normal, tmp);

                // 衝突点
                VECTOR hitPos = VSub(calcEndPositionTmp,VScale(hitFlag.Dim[j].Normal, dot));
                //calcEndPositionTmpとhitPosの差
                VECTOR tmp2 = VSub(calcEndPositionTmp,hitPos);
                float len=VSize(tmp2);
                if (HitCheck_Sphere_Triangle(calcEndPositionTmp, radius,
                    hitFlag.Dim[j].Position[0], hitFlag.Dim[j].Position[1], hitFlag.Dim[j].Position[2]) == TRUE&&len!=0.0f)
                {
                    //天井にぶつかったとき
                    if (hitFlag.Dim[j].Normal.y < 0.0f && wall == false)
                    {
                        player.OnHitCeiling();
                    }
                    //床にぶつかったとき
                    else if (hitFlag.Dim[j].Normal.y > 0.0f && wall == false)
                    {
                        isFall = false;
                        player.OnHitFloor();
                        if (isGool == true)
                        {
                            //ゴールした時の処理
                            isHitGool = true;
                        }
                    }
                    //行きたいpositionと当たった場所を引きその分戻す
                    {
                        len = radius - len;
                        VECTOR correctionValue = VScale(hitFlag.Dim[j].Normal,len);
                        if (correctionValue.z > 1.0f || correctionValue.z < -1.0f)
                        {
                            //処理なし
                        }
                        else
                        {
                            calcEndPositionTmp =VAdd(calcEndPositionTmp, correctionValue);
                        }
                    }
                }
            }
        }
        
    }
    moveVector = VSub(calcEndPositionTmp, VAdd(player.GetPosition(),VGet(0, CorrectionY,0)));


}
int Collision::HitHand(Player& player, Map& map)
{
    static VECTOR pulsXPos = VGet(DirectionLine, 0.0f, 0.0f);
    static VECTOR pulsZPos = VGet(0.0f, 0.0f, DirectionLine);

    VECTOR startPosition = VAdd(player.GetPosition(), VGet(0.0f, CorrectionY, 0.0f));
    VECTOR endPosition=startPosition;
    MV1_COLL_RESULT_POLY hitFlag;
    bool noHit=true;
    int direction = player.GetGraspDrection();
    int sumNumber = map.GetSoilNumber() + map.GetBlockNuber();
    int result = -1;
    //線分の終点決定
    {
        //左
        if (direction == 1)
        {
            endPosition = VSub(endPosition, pulsXPos);
        }
        //右
        else if (direction == 2)
        {
            endPosition = VAdd(endPosition, pulsXPos);
        }
        //奥
        else if (direction == 3)
        {
            endPosition = VAdd(endPosition, pulsZPos);
        }
    }
    for (int i = map.GetSoilNumber(); i < sumNumber; i++)
    {
        int modelHandle = map.GetBlockModel(i);
        //向いている方向から延びる線分とブロック
        hitFlag = MV1CollCheck_Line(modelHandle, -1, startPosition, endPosition);
        if (hitFlag.HitFlag == 1)
        {
            noHit=false;
            result = i;
            return result;
        }
    }
    if (noHit)
    {
        player.SetNoHit();
    }
    return result;
}
void Collision::HitDepthBlock(Player& player, Map& map, VECTOR moveVector, const int blockNumber)
{
    VECTOR startPosition = VAdd(player.GetPosition(), VGet(0.0f, CorrectionY, 0.0f));
    VECTOR endPosition = startPosition;
    int direction = player.GetGraspDrection();
    int sumNumber = map.GetSoilNumber() + map.GetBlockNuber();
    int modelHandle=0;
    bool noHitDepth=true;

    //つかんだ方向が左か右の時奥にぶつかるブロックがある場合移動処理させない
    if ((direction == 1||direction==2)&&moveVector.z>0.0f)
    {
        MV1_COLL_RESULT_POLY hitDepth;
        endPosition = VAdd(startPosition, VGet(0.0f,0.0f,CheckDepthRange));

        for (int j = map.GetSoilNumber(); j < sumNumber; j++)
        {
            if (blockNumber != j)
            {
                modelHandle = map.GetBlockModel(j);
                hitDepth = MV1CollCheck_Line(modelHandle, -1, startPosition, endPosition);
                if (hitDepth.HitFlag == 1&&map.GetBlockStep(blockNumber)-1==map.GetBlockStep(j))
                {
                    noHitDepth = false;
                    break;
                }
            }
        }
    }

    //移動処理
    if (moveVector.z != 0.0f&& noHitDepth==true)
    {
        int moveDirection=player.GetGraspMoveDirection();
        bool isMove = map.BlockMove(moveVector, blockNumber, moveDirection,direction);
        player.SetBlockMove(isMove, moveDirection);
    }

}
