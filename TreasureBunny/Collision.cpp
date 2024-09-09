#include"DxLib.h"
#include"Collision.h"
#include"Player.h"
#include"Map.h"
#include"Block.h"
Collision::Collision()
{
    //�����Ȃ�
}
Collision::~Collision()
{
    //�����Ȃ�
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
        //�����ł���Ώ������Ȃ�
        if (map.GetIsTransparent(i) == false)
        {
            if (i>=map.GetSoilNumber()&&map.GetBlockStep(i)==0)
            {
                //�����Ȃ�
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
    //�u���b�N���ړ������n�߂������ɂ����ړ��o���Ȃ��悤�ɂ���
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
///// ���o���ꂽ�|���S�����ǃ|���S��( �w�y���ʂɐ����ȃ|���S�� )�����|���S��( �w�y���ʂɐ����ł͂Ȃ��|���S�� )���𔻒f���A�ۑ�����
///// </summary>
//void Collision::AnalyzeWallAndFloor(MV1_COLL_RESULT_POLY_DIM hitDim, const VECTOR& checkPosition)
//{
//    // �ǃ|���S���Ə��|���S���̐�������������
//    wallNum = 0;
//    floorNum = 0;
//
//    // ���o���ꂽ�|���S���̐������J��Ԃ�
//    for (int i = 0; i < hitDim.HitNum; i++)
//    {
//        // �w�y���ʂɐ������ǂ����̓|���S���̖@���̂x�������O�Ɍ���Ȃ��߂����ǂ����Ŕ��f����
//        if (hitDim.Dim[i].Normal.y < 0.000001f && hitDim.Dim[i].Normal.y > -0.000001f)
//        {
//            // �ǃ|���S���Ɣ��f���ꂽ�ꍇ�ł��A�v���C���[�̂x���W�{�P�D�O����荂���|���S���̂ݓ����蔻����s��
//            if (hitDim.Dim[i].Position[0].y > checkPosition.y + 1.0f ||
//                hitDim.Dim[i].Position[1].y > checkPosition.y + 1.0f ||
//                hitDim.Dim[i].Position[2].y > checkPosition.y + 1.0f)
//            {
//                // �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
//                if (wallNum < MaxHitColl)
//                {
//                    // �|���S���̍\���̂̃A�h���X��ǃ|���S���|�C���^�z��ɕۑ�����
//                    wall[wallNum] = &hitDim.Dim[i];
//                    wallNum++;
//                }
//            }
//        }
//        else
//        {
//            // �|���S���̐����񋓂ł�����E���ɒB���Ă��Ȃ�������|���S����z��ɒǉ�
//            if (floorNum < MaxHitColl)
//            {
//                // �|���S���̍\���̂̃A�h���X�����|���S���|�C���^�z��ɕۑ�����
//                floor[floorNum] = &hitDim.Dim[i];
//                floorNum++;
//            }
//        }
//    }
//}
//
///// <summary>
///// �ǃ|���S���Ƃ̓�������`�F�b�N���A�␳���ׂ��ړ��x�N�g����Ԃ�
///// </summary>
//VECTOR Collision::CheckHitWithWall(Player& player, const VECTOR& checkPosition)
//{
//    VECTOR fixedPos = checkPosition;
//
//    // �ǂ̐������������瑁�����^�[��
//    if (wallNum == 0)
//    {
//        return fixedPos;
//    }
//
//    // �ǂ���̉����o�����������݂�ő吔�����J��Ԃ�
//    for (int k = 0; k < HitTryNum; k++)
//    {
//        // ������\���̂���ǃ|���S����S�Č���
//        bool isHitWall = false;
//        for (int i = 0; i < wallNum; i++)
//        {
//            // i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
//            auto poly = wall[i];
//
//            // �v���C���[�Ɠ������Ă���Ȃ�
//            if (HitCheck_Capsule_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), HitWidth, poly->Position[0], poly->Position[1], poly->Position[2]) == TRUE)
//            {
//                // �K�苗�����v���C���[��ǂ̖@�������Ɉړ�������
//                // �ړ���̈ʒu���X�V�i�ړ���̏ꏊ��␳�j
//                fixedPos = VAdd(fixedPos, VScale(poly->Normal, HitSlideLength));
//
//                // �ړ������ǃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
//                for (int j = 0; j < wallNum; j++)
//                {
//                    // �������Ă����烋�[�v�𔲂���
//                    poly = wall[j];
//                    if (HitCheck_Capsule_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), HitWidth, poly->Position[0], poly->Position[1], poly->Position[2]) == TRUE)
//                    {
//                        isHitWall = true;
//                        break;
//                    }
//                }
//
//                // �S�Ẵ|���S���Ɠ������Ă��Ȃ������炱���Ń��[�v�I��
//                if (isHitWall == false)
//                {
//                    break;
//                }
//            }
//        }
//
//        // �S���̃|���S���ŉ����o�������݂�O��
//        // �S�Ă̕ǃ|���S���ƐڐG���Ȃ��Ȃ����烋�[�v���甲����
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
///// ���|���S���Ƃ̓�������`�F�b�N���A�␳���ׂ��ړ��x�N�g����Ԃ�
///// </summary>
//VECTOR Collision::CheckHitWithFloor(Player& player, const VECTOR& checkPosition)
//{
//    VECTOR fixedPos = checkPosition;
//
//    // ���̐������������瑁�����^�[��
//    if (floorNum == 0)
//    {
//        return fixedPos;
//    }
//
//    // �W�����v�����㏸���̏ꍇ�͏����𕪊�
//    if (player.GetStatus() == Player::Status::JAMP && player.GetJumpPower() > 0.0f)
//    {
//        // �V��ɓ����Ԃ��鏈�����s��
//        // ��ԒႢ�V��ɂԂ���ׂ̔���p�ϐ���������
//        bool isHitRoof = false;
//        float minY = 0.0f;
//
//        // ���|���S���̐������J��Ԃ�
//        for (int i = 0; i < floorNum; i++)
//        {
//            auto poly = floor[i];	// i�Ԗڂ̏��|���S���̃A�h���X
//
//            // ���悩�瓪�̍����܂ł̊ԂŃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
//            HITRESULT_LINE lineResult;	// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
//            lineResult = HitCheck_Line_Triangle(fixedPos, VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//
//            // �ڐG���Ă��Ȃ������牽�����Ȃ�
//            if (lineResult.HitFlag == TRUE)
//            {
//                // ���Ƀ|���S���ɓ������Ă��āA�����܂Ō��o�����V��|���S����荂���ꍇ�͉������Ȃ�
//                if (!(isHitRoof == true && minY < lineResult.Position.y))
//                {
//                    // �|���S���ɓ��������t���O�𗧂Ă�
//                    isHitRoof = true;
//
//                    // �ڐG�����x���W��ۑ�����
//                    minY = lineResult.Position.y;
//                }
//            }
//        }
//
//        // �ڐG�����|���S���������
//        if (isHitRoof == true)
//        {
//            // �ڐG�����ꍇ�̓v���C���[�̂x���W��ڐG���W�����ɍX�V
//            fixedPos.y = minY - HitHeight;
//            player.OnHitCeiling();
//        }
//    }
//    // ���~�����W�����v���ł͂Ȃ��ꍇ�̏���
//    else
//    {
//        bool isHitFloor = false;
//        float maxY = 0.0f;
//
//        // ���|���S���̐������J��Ԃ�
//        for (int i = 0; i < floorNum; i++)
//        {
//            auto poly = floor[i];	// i�Ԗڂ̏��|���S���̃A�h���X
//
//            // �W�����v�����ǂ����ŏ����𕪊�
//            HITRESULT_LINE lineResult;	// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
//            if (player.GetStatus() == Player::Status::JAMP)
//            {
//                // �W�����v���̏ꍇ�͓��̐悩�瑫���菭���Ⴂ�ʒu�̊Ԃœ������Ă��邩�𔻒�
//                lineResult = HitCheck_Line_Triangle(VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), VAdd(fixedPos, VGet(0.0f, -1.0f, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//            }
//            else
//            {
//                // �����Ă���ꍇ�͓��̐悩�炻�������Ⴂ�ʒu�̊Ԃœ������Ă��邩�𔻒�( �X�΂ŗ�����ԂɈڍs���Ă��܂�Ȃ��� )
//                lineResult = HitCheck_Line_Triangle(VAdd(fixedPos, VGet(0.0f, HitHeight, 0.0f)), VAdd(fixedPos, VGet(0.0f, -40.0f, 0.0f)), poly->Position[0], poly->Position[1], poly->Position[2]);
//            }
//
//            // ���ɓ��������|���S��������A�����܂Ō��o�������|���S�����Ⴂ�ꍇ�͉������Ȃ�
//            if (lineResult.HitFlag == TRUE)
//            {
//                if (!(isHitFloor == true && maxY > lineResult.Position.y))
//                {
//                    // �ڐG�����x���W��ۑ�����
//                    isHitFloor = true;
//                    maxY = lineResult.Position.y;
//                }
//            }
//        }
//
//        // ���|���S���ɓ�������
//        if (isHitFloor == true)
//        {
//            // �ڐG�����|���S���ň�ԍ����x���W���v���C���[�̂x���W�ɂ���
//            fixedPos.y = maxY;
//
//            // ���ɓ���������
//            player.OnHitFloor();
//        }
//        else
//        {
//            // ���R���W�����ɓ������Ă��Ȃ��Ċ��W�����v��Ԃł͂Ȃ������ꍇ�͗������
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
                //����
;                float  dot = VDot(hitFlag.Dim[j].Normal, tmp);

                // �Փ˓_
                VECTOR hitPos = VSub(calcEndPositionTmp,VScale(hitFlag.Dim[j].Normal, dot));
                //calcEndPositionTmp��hitPos�̍�
                VECTOR tmp2 = VSub(calcEndPositionTmp,hitPos);
                float len=VSize(tmp2);
                if (HitCheck_Sphere_Triangle(calcEndPositionTmp, radius,
                    hitFlag.Dim[j].Position[0], hitFlag.Dim[j].Position[1], hitFlag.Dim[j].Position[2]) == TRUE&&len!=0.0f)
                {
                    //�V��ɂԂ������Ƃ�
                    if (hitFlag.Dim[j].Normal.y < 0.0f && wall == false)
                    {
                        player.OnHitCeiling();
                    }
                    //���ɂԂ������Ƃ�
                    else if (hitFlag.Dim[j].Normal.y > 0.0f && wall == false)
                    {
                        isFall = false;
                        player.OnHitFloor();
                        if (isGool == true)
                        {
                            //�S�[���������̏���
                            isHitGool = true;
                        }
                    }
                    //�s������position�Ɠ��������ꏊ���������̕��߂�
                    {
                        len = radius - len;
                        VECTOR correctionValue = VScale(hitFlag.Dim[j].Normal,len);
                        if (correctionValue.z > 1.0f || correctionValue.z < -1.0f)
                        {
                            //�����Ȃ�
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
    //�����̏I�_����
    {
        //��
        if (direction == 1)
        {
            endPosition = VSub(endPosition, pulsXPos);
        }
        //�E
        else if (direction == 2)
        {
            endPosition = VAdd(endPosition, pulsXPos);
        }
        //��
        else if (direction == 3)
        {
            endPosition = VAdd(endPosition, pulsZPos);
        }
    }
    for (int i = map.GetSoilNumber(); i < sumNumber; i++)
    {
        int modelHandle = map.GetBlockModel(i);
        //�����Ă���������牄�т�����ƃu���b�N
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

    //���񂾕����������E�̎����ɂԂ���u���b�N������ꍇ�ړ����������Ȃ�
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

    //�ړ�����
    if (moveVector.z != 0.0f&& noHitDepth==true)
    {
        int moveDirection=player.GetGraspMoveDirection();
        bool isMove = map.BlockMove(moveVector, blockNumber, moveDirection,direction);
        player.SetBlockMove(isMove, moveDirection);
    }

}
