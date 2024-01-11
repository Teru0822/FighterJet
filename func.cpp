#include "GL/freeglut.h"
#include "func.h"
#include <stdio.h>

namespace mainShip
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace ret
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace fire1
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace fire2
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace thirdRet
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace wing
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}

namespace tail
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace cockPit
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace RR
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace RL
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace LR
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace LL
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace enemy
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace bullet
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
namespace field
{
    float vertex[ARRAY_MAX];
    int lines[ARRAY_MAX];
    int vertexDataSize = 0;
    int lineDataSize = 0;
}
void makeEnemy(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, enemy::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < enemy::lineDataSize; i++) {
            glArrayElement(enemy::lines[i * 3]);   //0
            glArrayElement(enemy::lines[i * 3 + 1]);  //1
            glArrayElement(enemy::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeShip(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, mainShip::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < mainShip::lineDataSize; i++) {
            glArrayElement(mainShip::lines[i * 3]);   //0
            glArrayElement(mainShip::lines[i * 3 + 1]);  //1
            glArrayElement(mainShip::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeTailWing(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, tail::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < tail::lineDataSize; i++) {
            glArrayElement(tail::lines[i * 3]);   //0
            glArrayElement(tail::lines[i * 3 + 1]);  //1
            glArrayElement(tail::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeBullet(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, bullet::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < bullet::lineDataSize; i++) {
            glArrayElement(bullet::lines[i * 3]);   //0
            glArrayElement(bullet::lines[i * 3 + 1]);  //1
            glArrayElement(bullet::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeCockPit(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, cockPit::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < cockPit::lineDataSize; i++) {
            glArrayElement(cockPit::lines[i * 3]);   //0
            glArrayElement(cockPit::lines[i * 3 + 1]);  //1
            glArrayElement(cockPit::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeWing(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, wing::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {

        for (int i = 0; i < wing::lineDataSize; i++) {
            glArrayElement(wing::lines[i * 3]);   //0
            glArrayElement(wing::lines[i * 3 + 1]);  //1
            glArrayElement(wing::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeFire1(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, fire1::vertex);

    glPointSize(3);

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < fire1::lineDataSize; i++) {
            glArrayElement(fire1::lines[i * 3]);   //0
            glArrayElement(fire1::lines[i * 3 + 1]);  //1
            glArrayElement(fire1::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeRet()
{
    glVertexPointer(3, GL_FLOAT, 0, ret::vertex);

    glPointSize(3);
    glColor3f(0, 1, 1);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < ret::lineDataSize; i++) {
            glArrayElement(ret::lines[i * 3]);   //0
            glArrayElement(ret::lines[i * 3 + 1]);  //1
            glArrayElement(ret::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeFire2(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, fire2::vertex);

    glPointSize(3);

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < fire2::lineDataSize; i++) {
            glArrayElement(fire2::lines[i * 3]);   //0
            glArrayElement(fire2::lines[i * 3 + 1]);  //1
            glArrayElement(fire2::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeRightRightMissile(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, RR::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < RR::lineDataSize; i++) {
            glArrayElement(RR::lines[i * 3]);   //0
            glArrayElement(RR::lines[i * 3 + 1]);  //1
            glArrayElement(RR::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeRightLeftMissile(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, RL::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < RL::lineDataSize; i++) {
            glArrayElement(RL::lines[i * 3]);   //0
            glArrayElement(RL::lines[i * 3 + 1]);  //1
            glArrayElement(RL::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeLeftRightMissile(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, LR::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < LR::lineDataSize; i++) {
            glArrayElement(LR::lines[i * 3]);   //0
            glArrayElement(LR::lines[i * 3 + 1]);  //1
            glArrayElement(LR::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeLeftLeftMissile(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, LL::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < LL::lineDataSize; i++) {
            glArrayElement(LL::lines[i * 3]);   //0
            glArrayElement(LL::lines[i * 3 + 1]);  //1
            glArrayElement(LL::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void makeField(float r, float g, float b)
{
    glVertexPointer(3, GL_FLOAT, 0, field::vertex);

    glPointSize(3);
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < field::lineDataSize; i++) {
            glArrayElement(field::lines[i * 3]);   //0
            glArrayElement(field::lines[i * 3 + 1]);  //1
            glArrayElement(field::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();

}
void makeThirdRet()
{

    glVertexPointer(3, GL_FLOAT, 0, thirdRet::vertex);

    glPointSize(3);
    glColor3f(0, 1, 1);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < thirdRet::lineDataSize; i++) {
            glArrayElement(thirdRet::lines[i * 3]);   //0
            glArrayElement(thirdRet::lines[i * 3 + 1]);  //1
            glArrayElement(thirdRet::lines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
void readPoints()
{
    FILE* fpVData, * fpFData, * fpretVData, * fpretFData, * fpFire1VData, * fpFire1FData, * fpFire2VData, * fpFire2FData, * fpWingVData, * fpWingFData, * fpTailWingVData, * fpTailWingFData, * fpCockPitVData, * fpCockPitFData, * fpRightRightMissileVData, * fpRightRightMissileFData, * fpRightLeftMissileVData, * fpRightLeftMissileFData, * fpLeftRightMissileVData, * fpLeftRightMissileFData, * fpLeftLeftMissileVData, * fpLeftLeftMissileFData;
    FILE* fpEnemyVData, * fpEnemyFData,* fp3retVData, * fp3retFData, * fpBulletVData, * fpBulletFData, * fpFieldVData, * fpFieldFData;

    fopen_s(&fp3retVData, "config/3retVData.txt", "r");
    fopen_s(&fp3retFData, "config/3retFData.txt", "r");
    fopen_s(&fpVData, "config/vData.txt", "r");//vData::txt‚ðargs[0]‚É“ü‚ê‚Ä‚¢‚é
    fopen_s(&fpFData, "config/fData.txt", "r");
    fopen_s(&fpretVData, "config/retVData.txt", "r");
    fopen_s(&fpretFData, "config/retFData.txt", "r");
    fopen_s(&fpFire1VData, "config/fire1VData.txt", "r");
    fopen_s(&fpFire1FData, "config/fire1FData.txt", "r");
    fopen_s(&fpFieldVData, "config/fieldVData.txt", "r");
    fopen_s(&fpFieldFData, "config/fieldFData.txt", "r");
    fopen_s(&fpFire2VData, "config/fire2VData.txt", "r");
    fopen_s(&fpFire2FData, "config/fire2FData.txt", "r");
    fopen_s(&fpWingVData, "config/wingVData.txt", "r");
    fopen_s(&fpWingFData, "config/wingFData.txt", "r");
    fopen_s(&fpTailWingVData, "config/tailWingVData.txt", "r");
    fopen_s(&fpTailWingFData, "config/tailWingFData.txt", "r");
    fopen_s(&fpCockPitVData, "config/cockPitVData.txt", "r");
    fopen_s(&fpCockPitFData, "config/cockPitFData.txt", "r");
    fopen_s(&fpRightRightMissileVData, "config/missileRightRightVData.txt", "r");
    fopen_s(&fpRightRightMissileFData, "config/missileRightRightFData.txt", "r");
    fopen_s(&fpRightLeftMissileVData, "config/missileRightLeftVData.txt", "r");
    fopen_s(&fpRightLeftMissileFData, "config/missileRightLeftFData.txt", "r");
    fopen_s(&fpLeftRightMissileVData, "config/missileLeftRightVData.txt", "r");
    fopen_s(&fpLeftRightMissileFData, "config/missileLeftRightFData.txt", "r");
    fopen_s(&fpLeftLeftMissileVData, "config/missileLeftLeftVData.txt", "r");
    fopen_s(&fpLeftLeftMissileFData, "config/missileLeftLeftFData.txt", "r");
    fopen_s(&fpEnemyVData, "config/enemyVData.txt", "r");
    fopen_s(&fpEnemyFData, "config/enemyFData.txt", "r");
    fopen_s(&fpBulletVData, "config/bulletVData.txt", "r");
    fopen_s(&fpBulletFData, "config/bulletFData.txt", "r");

    if ((fpVData == NULL) || (fpFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpVData, "%f, %f, %f", &mainShip::vertex[mainShip::vertexDataSize * 3], &mainShip::vertex[mainShip::vertexDataSize * 3 + 1], &mainShip::vertex[mainShip::vertexDataSize * 3 + 2]) != EOF)
            mainShip::vertexDataSize++;

        while (fscanf_s(fpFData, "%d, %d, %d", &mainShip::lines[mainShip::lineDataSize * 3], &mainShip::lines[mainShip::lineDataSize * 3 + 1], &mainShip::lines[mainShip::lineDataSize * 3 + 2]) != EOF)
            mainShip::lineDataSize++;
    }
    if ((fpretVData == NULL) || (fpretFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpretVData, "%f, %f, %f", &ret::vertex[ret::vertexDataSize * 3], &ret::vertex[ret::vertexDataSize * 3 + 1], &ret::vertex[ret::vertexDataSize * 3 + 2]) != EOF)
            ret::vertexDataSize++;

        while (fscanf_s(fpretFData, "%d, %d, %d", &ret::lines[ret::lineDataSize * 3], &ret::lines[ret::lineDataSize * 3 + 1], &ret::lines[ret::lineDataSize * 3 + 2]) != EOF)
            ret::lineDataSize++;
    }

    if ((fpFire1VData == NULL) || (fpFire1FData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFire1VData, "%f, %f, %f", &fire1::vertex[fire1::vertexDataSize * 3], &fire1::vertex[fire1::vertexDataSize * 3 + 1], &fire1::vertex[fire1::vertexDataSize * 3 + 2]) != EOF)
            fire1::vertexDataSize++;

        while (fscanf_s(fpFire1FData, "%d, %d, %d", &fire1::lines[fire1::lineDataSize * 3], &fire1::lines[fire1::lineDataSize * 3 + 1], &fire1::lines[fire1::lineDataSize * 3 + 2]) != EOF)
            fire1::lineDataSize++;
    }
    if ((fpFire2VData == NULL) || (fpFire2FData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFire2VData, "%f, %f, %f", &fire2::vertex[fire2::vertexDataSize * 3], &fire2::vertex[fire2::vertexDataSize * 3 + 1], &fire2::vertex[fire2::vertexDataSize * 3 + 2]) != EOF)
            fire2::vertexDataSize++;

        while (fscanf_s(fpFire2FData, "%d, %d, %d", &fire2::lines[fire2::lineDataSize * 3], &fire2::lines[fire2::lineDataSize * 3 + 1], &fire2::lines[fire2::lineDataSize * 3 + 2]) != EOF)
            fire2::lineDataSize++;
    }
    if ((fpWingVData == NULL) || (fpWingFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpWingVData, "%f, %f, %f", &wing::vertex[wing::vertexDataSize * 3], &wing::vertex[wing::vertexDataSize * 3 + 1], &wing::vertex[wing::vertexDataSize * 3 + 2]) != EOF)
            wing::vertexDataSize++;

        while (fscanf_s(fpWingFData, "%d, %d, %d", &wing::lines[wing::lineDataSize * 3], &wing::lines[wing::lineDataSize * 3 + 1], &wing::lines[wing::lineDataSize * 3 + 2]) != EOF)
            wing::lineDataSize++;
    }


    if ((fpTailWingVData == NULL) || (fpTailWingFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpTailWingVData, "%f, %f, %f", &tail::vertex[tail::vertexDataSize * 3], &tail::vertex[tail::vertexDataSize * 3 + 1], &tail::vertex[tail::vertexDataSize * 3 + 2]) != EOF)
            tail::vertexDataSize++;

        while (fscanf_s(fpTailWingFData, "%d, %d, %d", &tail::lines[tail::lineDataSize * 3], &tail::lines[tail::lineDataSize * 3 + 1], &tail::lines[tail::lineDataSize * 3 + 2]) != EOF)
            tail::lineDataSize++;
    }
    if ((fpCockPitVData == NULL) || (fpCockPitFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpCockPitVData, "%f, %f, %f", &cockPit::vertex[cockPit::vertexDataSize * 3], &cockPit::vertex[cockPit::vertexDataSize * 3 + 1], &cockPit::vertex[cockPit::vertexDataSize * 3 + 2]) != EOF)
            cockPit::vertexDataSize++;

        while (fscanf_s(fpCockPitFData, "%d, %d, %d", &cockPit::lines[cockPit::lineDataSize * 3], &cockPit::lines[cockPit::lineDataSize * 3 + 1], &cockPit::lines[cockPit::lineDataSize * 3 + 2]) != EOF)
            cockPit::lineDataSize++;
    }
    if ((fpRightRightMissileVData == NULL) || (fpRightRightMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpRightRightMissileVData, "%f, %f, %f", &RR::vertex[RR::vertexDataSize * 3], &RR::vertex[RR::vertexDataSize * 3 + 1], &RR::vertex[RR::vertexDataSize * 3 + 2]) != EOF)
            RR::vertexDataSize++;

        while (fscanf_s(fpRightRightMissileFData, "%d, %d, %d", &RR::lines[RR::lineDataSize * 3], &RR::lines[RR::lineDataSize * 3 + 1], &RR::lines[RR::lineDataSize * 3 + 2]) != EOF)
            RR::lineDataSize++;
    }
    if ((fpRightLeftMissileVData == NULL) || (fpRightLeftMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpRightLeftMissileVData, "%f, %f, %f", &RL::vertex[RL::vertexDataSize * 3], &RL::vertex[RL::vertexDataSize * 3 + 1], &RL::vertex[RL::vertexDataSize * 3 + 2]) != EOF)
            RL::vertexDataSize++;

        while (fscanf_s(fpRightLeftMissileFData, "%d, %d, %d", &RL::lines[RL::lineDataSize * 3], &RL::lines[RL::lineDataSize * 3 + 1], &RL::lines[RL::lineDataSize * 3 + 2]) != EOF)
            RL::lineDataSize++;
    }
    if ((fpLeftRightMissileVData == NULL) || (fpLeftRightMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpLeftRightMissileVData, "%f, %f, %f", &LR::vertex[LR::vertexDataSize * 3], &LR::vertex[LR::vertexDataSize * 3 + 1], &LR::vertex[LR::vertexDataSize * 3 + 2]) != EOF)
            LR::vertexDataSize++;

        while (fscanf_s(fpLeftRightMissileFData, "%d, %d, %d", &LR::lines[LR::lineDataSize * 3], &LR::lines[LR::lineDataSize * 3 + 1], &LR::lines[LR::lineDataSize * 3 + 2]) != EOF)
            LR::lineDataSize++;
    }
    if ((fpLeftLeftMissileVData == NULL) || (fpLeftLeftMissileFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpLeftLeftMissileVData, "%f, %f, %f", &LL::vertex[LL::vertexDataSize * 3], &LL::vertex[LL::vertexDataSize * 3 + 1], &LL::vertex[LL::vertexDataSize * 3 + 2]) != EOF)
            LL::vertexDataSize++;

        while (fscanf_s(fpLeftLeftMissileFData, "%d, %d, %d", &LL::lines[LL::lineDataSize * 3], &LL::lines[LL::lineDataSize * 3 + 1], &LL::lines[LL::lineDataSize * 3 + 2]) != EOF)
            LL::lineDataSize++;
    }
    if ((fpEnemyVData == NULL) || (fpEnemyFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpEnemyVData, "%f, %f, %f", &enemy::vertex[enemy::vertexDataSize * 3], &enemy::vertex[enemy::vertexDataSize * 3 + 1], &enemy::vertex[enemy::vertexDataSize * 3 + 2]) != EOF)
            enemy::vertexDataSize++;

        while (fscanf_s(fpEnemyFData, "%d, %d, %d", &enemy::lines[enemy::lineDataSize * 3], &enemy::lines[enemy::lineDataSize * 3 + 1], &enemy::lines[enemy::lineDataSize * 3 + 2]) != EOF)
            enemy::lineDataSize++;
    }
    if ((fpBulletVData == NULL) || (fpBulletFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpBulletVData, "%f, %f, %f", &bullet::vertex[bullet::vertexDataSize * 3], &bullet::vertex[bullet::vertexDataSize * 3 + 1], &bullet::vertex[bullet::vertexDataSize * 3 + 2]) != EOF)
            bullet::vertexDataSize++;

        while (fscanf_s(fpBulletFData, "%d, %d, %d", &bullet::lines[bullet::lineDataSize * 3], &bullet::lines[bullet::lineDataSize * 3 + 1], &bullet::lines[bullet::lineDataSize * 3 + 2]) != EOF)
            bullet::lineDataSize++;
    }
    if ((fpFieldVData == NULL) || (fpFieldFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fpFieldVData, "%f, %f, %f", &field::vertex[field::vertexDataSize * 3], &field::vertex[field::vertexDataSize * 3 + 1], &field::vertex[field::vertexDataSize * 3 + 2]) != EOF)
            field::vertexDataSize++;

        while (fscanf_s(fpFieldFData, "%d, %d, %d", &field::lines[field::lineDataSize * 3], &field::lines[field::lineDataSize * 3 + 1], &field::lines[field::lineDataSize * 3 + 2]) != EOF)
            field::lineDataSize++;
    }


    if ((fp3retVData == NULL) || (fp3retFData == NULL)) {
        printf("file error!!\n");
        return;
    }
    else
    {
        while (fscanf_s(fp3retVData, "%f, %f, %f", &thirdRet::vertex[thirdRet::vertexDataSize * 3], &thirdRet::vertex[thirdRet::vertexDataSize * 3 + 1], &thirdRet::vertex[thirdRet::vertexDataSize * 3 + 2]) != EOF)
            thirdRet::vertexDataSize++;

        while (fscanf_s(fp3retFData, "%d, %d, %d", &thirdRet::lines[thirdRet::lineDataSize * 3], &thirdRet::lines[thirdRet::lineDataSize * 3 + 1], &thirdRet::lines[thirdRet::lineDataSize * 3 + 2]) != EOF)
            thirdRet::lineDataSize++;
    }

}

