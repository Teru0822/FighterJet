#include <unordered_map>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "warship_3d.h"
#include "ret.h"
#include "fire1.h"
#include "fire2.h"
#include "makefloor.h"
#include "misile.h"
#include "wing.h"
#include "ammo.h"
#include "cockPit.h"
#include "tailWing.h"
#include "missileRightRight.h"
#include "missileRightLeft.h"
#include "missileLeftRight.h"
#include "missileLeftLeft.h"
#include "enemy.h"
#include "bullet.h"
#include "3ret.h"
#include "field.h"
#include "config_ImportFiles.h"


void InitialProc(const std::unordered_map<std::string, std::string>& maps)
{

    FILE* fpVData, * fpFData, * fpretVData, * fpretFData, * fpFire1VData, * fpFire1FData, * fpFire2VData, * fpFire2FData, * fpWingVData, * fpWingFData, * fpTailWingVData, * fpTailWingFData, * fpCockPitVData, * fpCockPitFData, * fpRightRightMissileVData, * fpRightRightMissileFData, * fpRightLeftMissileVData, * fpRightLeftMissileFData, * fpLeftRightMissileVData, * fpLeftRightMissileFData, * fpLeftLeftMissileVData, * fpLeftLeftMissileFData;
    FILE* fpEnemyVData, * fpEnemyFData, * fpBulletVData, * fpBulletFData, * fp3retVData, * fp3retFData, * fpFieldVData, * fpFieldFData;

    fopen_s(&fpVData, maps.at("mainShipV").c_str(), "r");//vData.txt‚ðargs[0]‚É“ü‚ê‚Ä‚¢‚é
    fopen_s(&fpFData, maps.at("mainShipF").c_str(), "r");
    fopen_s(&fpretVData, maps.at("retV").c_str(), "r");
    fopen_s(&fpretFData, maps.at("retF").c_str(), "r");
    fopen_s(&fpFire1VData, maps.at("fire1V").c_str(), "r");
    fopen_s(&fpFire1FData, maps.at("fire1F").c_str(), "r");
    fopen_s(&fpFire2VData, maps.at("fire2V").c_str(), "r");
    fopen_s(&fpFire2FData, maps.at("fire2F").c_str(), "r");
    fopen_s(&fpWingVData, maps.at("wingV").c_str(), "r");
    fopen_s(&fpWingFData, maps.at("wingF").c_str(), "r");
    fopen_s(&fpTailWingVData, maps.at("tailWingV").c_str(), "r");
    fopen_s(&fpTailWingFData, maps.at("tailWingF").c_str(), "r");
    fopen_s(&fpCockPitVData, maps.at("cockPitV").c_str(), "r");
    fopen_s(&fpCockPitFData, maps.at("cockPitF").c_str(), "r");
    fopen_s(&fpRightRightMissileVData, maps.at("RRMissileV").c_str(), "r");
    fopen_s(&fpRightRightMissileFData, maps.at("RRMissileF").c_str(), "r");
    fopen_s(&fpRightLeftMissileVData, maps.at("RLMissileV").c_str(), "r");
    fopen_s(&fpRightLeftMissileFData, maps.at("RLMissileF").c_str(), "r");
    fopen_s(&fpLeftRightMissileVData, maps.at("LRMissileV").c_str(), "r");
    fopen_s(&fpLeftRightMissileFData, maps.at("LRMissileF").c_str(), "r");
    fopen_s(&fpLeftLeftMissileVData, maps.at("LLMissileV").c_str(), "r");
    fopen_s(&fpLeftLeftMissileFData, maps.at("LLMissileF").c_str(), "r");
    fopen_s(&fpEnemyVData, maps.at("enemyV").c_str(), "r");
    fopen_s(&fpEnemyFData, maps.at("enemyF").c_str(), "r");
    fopen_s(&fpBulletVData, maps.at("bulletV").c_str(), "r");
    fopen_s(&fpBulletFData, maps.at("bulletF").c_str(), "r");
    fopen_s(&fp3retVData, maps.at("3retV").c_str(), "r");
    fopen_s(&fp3retFData, maps.at("3retF").c_str(), "r");
    fopen_s(&fpFieldVData, maps.at("fieldV").c_str(), "r");
    fopen_s(&fpFieldFData, maps.at("fieldF").c_str(), "r");



    if ((fpVData == NULL) || (fpFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpVData, "%f, %f, %f", &vertex[vertexDataSize * 3], &vertex[vertexDataSize * 3 + 1], &vertex[vertexDataSize * 3 + 2]) != EOF)
            vertexDataSize++;

        while (fscanf_s(fpFData, "%d, %d, %d", &lines[lineDataSize * 3], &lines[lineDataSize * 3 + 1], &lines[lineDataSize * 3 + 2]) != EOF)
            lineDataSize++;
    }
    if ((fpretVData == NULL) || (fpretFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpretVData, "%f, %f, %f", &Rvertex[RvertexDataSize * 3], &Rvertex[RvertexDataSize * 3 + 1], &Rvertex[RvertexDataSize * 3 + 2]) != EOF)
            RvertexDataSize++;

        while (fscanf_s(fpretFData, "%d, %d, %d", &Rlines[RlineDataSize * 3], &Rlines[RlineDataSize * 3 + 1], &Rlines[RlineDataSize * 3 + 2]) != EOF)
            RlineDataSize++;
    }
    if ((fp3retVData == NULL) || (fp3retFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fp3retVData, "%f, %f, %f", &ThirdRvertex[ThirdRvertexDataSize * 3], &ThirdRvertex[ThirdRvertexDataSize * 3 + 1], &ThirdRvertex[ThirdRvertexDataSize * 3 + 2]) != EOF)
            ThirdRvertexDataSize++;

        while (fscanf_s(fp3retFData, "%d, %d, %d", &ThirdRlines[ThirdRlineDataSize * 3], &ThirdRlines[ThirdRlineDataSize * 3 + 1], &ThirdRlines[ThirdRlineDataSize * 3 + 2]) != EOF)
            ThirdRlineDataSize++;
    }

    if ((fpFire1VData == NULL) || (fpFire1FData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFire1VData, "%f, %f, %f", &Fire1vertex[Fire1vertexDataSize * 3], &Fire1vertex[Fire1vertexDataSize * 3 + 1], &Fire1vertex[Fire1vertexDataSize * 3 + 2]) != EOF)
            Fire1vertexDataSize++;

        while (fscanf_s(fpFire1FData, "%d, %d, %d", &Fire1lines[Fire1lineDataSize * 3], &Fire1lines[Fire1lineDataSize * 3 + 1], &Fire1lines[Fire1lineDataSize * 3 + 2]) != EOF)
            Fire1lineDataSize++;
    }
    if ((fpFire2VData == NULL) || (fpFire2FData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFire2VData, "%f, %f, %f", &Fire2vertex[Fire2vertexDataSize * 3], &Fire2vertex[Fire2vertexDataSize * 3 + 1], &Fire2vertex[Fire2vertexDataSize * 3 + 2]) != EOF)
            Fire2vertexDataSize++;

        while (fscanf_s(fpFire2FData, "%d, %d, %d", &Fire2lines[Fire2lineDataSize * 3], &Fire2lines[Fire2lineDataSize * 3 + 1], &Fire2lines[Fire2lineDataSize * 3 + 2]) != EOF)
            Fire2lineDataSize++;
    }
    if ((fpWingVData == NULL) || (fpWingFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpWingVData, "%f, %f, %f", &Wingvertex[WingvertexDataSize * 3], &Wingvertex[WingvertexDataSize * 3 + 1], &Wingvertex[WingvertexDataSize * 3 + 2]) != EOF)
            WingvertexDataSize++;

        while (fscanf_s(fpWingFData, "%d, %d, %d", &Winglines[WinglineDataSize * 3], &Winglines[WinglineDataSize * 3 + 1], &Winglines[WinglineDataSize * 3 + 2]) != EOF)
            WinglineDataSize++;
    }


    if ((fpTailWingVData == NULL) || (fpTailWingFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpTailWingVData, "%f, %f, %f", &tailWingvertex[tailWingvertexDataSize * 3], &tailWingvertex[tailWingvertexDataSize * 3 + 1], &tailWingvertex[tailWingvertexDataSize * 3 + 2]) != EOF)
            tailWingvertexDataSize++;

        while (fscanf_s(fpTailWingFData, "%d, %d, %d", &tailWinglines[tailWinglineDataSize * 3], &tailWinglines[tailWinglineDataSize * 3 + 1], &tailWinglines[tailWinglineDataSize * 3 + 2]) != EOF)
            tailWinglineDataSize++;
    }
    if ((fpCockPitVData == NULL) || (fpCockPitFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpCockPitVData, "%f, %f, %f", &cockPitvertex[cockPitvertexDataSize * 3], &cockPitvertex[cockPitvertexDataSize * 3 + 1], &cockPitvertex[cockPitvertexDataSize * 3 + 2]) != EOF)
            cockPitvertexDataSize++;

        while (fscanf_s(fpCockPitFData, "%d, %d, %d", &cockPitlines[cockPitlineDataSize * 3], &cockPitlines[cockPitlineDataSize * 3 + 1], &cockPitlines[cockPitlineDataSize * 3 + 2]) != EOF)
            cockPitlineDataSize++;
    }
    if ((fpRightRightMissileVData == NULL) || (fpRightRightMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpRightRightMissileVData, "%f, %f, %f", &RightRightMissilevertex[RightRightMissilevertexDataSize * 3], &RightRightMissilevertex[RightRightMissilevertexDataSize * 3 + 1], &RightRightMissilevertex[RightRightMissilevertexDataSize * 3 + 2]) != EOF)
            RightRightMissilevertexDataSize++;

        while (fscanf_s(fpRightRightMissileFData, "%d, %d, %d", &RightRightMissilelines[RightRightMissilelineDataSize * 3], &RightRightMissilelines[RightRightMissilelineDataSize * 3 + 1], &RightRightMissilelines[RightRightMissilelineDataSize * 3 + 2]) != EOF)
            RightRightMissilelineDataSize++;
    }
    if ((fpRightLeftMissileVData == NULL) || (fpRightLeftMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpRightLeftMissileVData, "%f, %f, %f", &RightLeftMissilevertex[RightLeftMissilevertexDataSize * 3], &RightLeftMissilevertex[RightLeftMissilevertexDataSize * 3 + 1], &RightLeftMissilevertex[RightLeftMissilevertexDataSize * 3 + 2]) != EOF)
            RightLeftMissilevertexDataSize++;

        while (fscanf_s(fpRightLeftMissileFData, "%d, %d, %d", &RightLeftMissilelines[RightLeftMissilelineDataSize * 3], &RightLeftMissilelines[RightLeftMissilelineDataSize * 3 + 1], &RightLeftMissilelines[RightLeftMissilelineDataSize * 3 + 2]) != EOF)
            RightLeftMissilelineDataSize++;
    }
    if ((fpLeftRightMissileVData == NULL) || (fpLeftRightMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpLeftRightMissileVData, "%f, %f, %f", &LeftRightMissilevertex[LeftRightMissilevertexDataSize * 3], &LeftRightMissilevertex[LeftRightMissilevertexDataSize * 3 + 1], &LeftRightMissilevertex[LeftRightMissilevertexDataSize * 3 + 2]) != EOF)
            LeftRightMissilevertexDataSize++;

        while (fscanf_s(fpLeftRightMissileFData, "%d, %d, %d", &LeftRightMissilelines[LeftRightMissilelineDataSize * 3], &LeftRightMissilelines[LeftRightMissilelineDataSize * 3 + 1], &LeftRightMissilelines[LeftRightMissilelineDataSize * 3 + 2]) != EOF)
            LeftRightMissilelineDataSize++;
    }
    if ((fpLeftLeftMissileVData == NULL) || (fpLeftLeftMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpLeftLeftMissileVData, "%f, %f, %f", &LeftLeftMissilevertex[LeftLeftMissilevertexDataSize * 3], &LeftLeftMissilevertex[LeftLeftMissilevertexDataSize * 3 + 1], &LeftLeftMissilevertex[LeftLeftMissilevertexDataSize * 3 + 2]) != EOF)
            LeftLeftMissilevertexDataSize++;

        while (fscanf_s(fpLeftLeftMissileFData, "%d, %d, %d", &LeftLeftMissilelines[LeftLeftMissilelineDataSize * 3], &LeftLeftMissilelines[LeftLeftMissilelineDataSize * 3 + 1], &LeftLeftMissilelines[LeftLeftMissilelineDataSize * 3 + 2]) != EOF)
            LeftLeftMissilelineDataSize++;
    }
    if ((fpEnemyVData == NULL) || (fpEnemyFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpEnemyVData, "%f, %f, %f", &Enemyvertex[EnemyvertexDataSize * 3], &Enemyvertex[EnemyvertexDataSize * 3 + 1], &Enemyvertex[EnemyvertexDataSize * 3 + 2]) != EOF)
            EnemyvertexDataSize++;

        while (fscanf_s(fpEnemyFData, "%d, %d, %d", &Enemylines[EnemylineDataSize * 3], &Enemylines[EnemylineDataSize * 3 + 1], &Enemylines[EnemylineDataSize * 3 + 2]) != EOF)
            EnemylineDataSize++;
    }
    if ((fpBulletVData == NULL) || (fpBulletFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpBulletVData, "%f, %f, %f", &Bulletvertex[BulletvertexDataSize * 3], &Bulletvertex[BulletvertexDataSize * 3 + 1], &Bulletvertex[BulletvertexDataSize * 3 + 2]) != EOF)
            BulletvertexDataSize++;

        while (fscanf_s(fpBulletFData, "%d, %d, %d", &Bulletlines[BulletlineDataSize * 3], &Bulletlines[BulletlineDataSize * 3 + 1], &Bulletlines[BulletlineDataSize * 3 + 2]) != EOF)
            BulletlineDataSize++;
    }
    if ((fpFieldVData == NULL) || (fpFieldFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFieldVData, "%f, %f, %f", &Fieldvertex[FieldvertexDataSize * 3], &Fieldvertex[FieldvertexDataSize * 3 + 1], &Fieldvertex[FieldvertexDataSize * 3 + 2]) != EOF)
            FieldvertexDataSize++;

        while (fscanf_s(fpFieldFData, "%d, %d, %d", &Fieldlines[FieldlineDataSize * 3], &Fieldlines[FieldlineDataSize * 3 + 1], &Fieldlines[FieldlineDataSize * 3 + 2]) != EOF)
            FieldlineDataSize++;
    }

}
