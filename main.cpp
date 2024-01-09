#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include <omp.h>
#include <unordered_map>
#include <string>


#include "func.h"
//#pragma comment (lib, "lib\x86\freeglut.lib")
//bool
bool keys[256];
bool onKeyPress = false;
bool boolBullet = false;
bool dead = false;
bool retry = false;
bool GUI = true;
bool weaponChange = false;
bool checkRightRightFire = false;
bool checkRightLeftFire = false;
bool checkLeftRightFire = false;
bool checkLeftLeftFire = false;
bool twobyone=false,rightButton=false,leftButton = false;
bool enemycreate = false;
bool pause = false;
bool thirdSpec = true;
bool pauseBool = true;
bool timeOver = false;
bool goStraight = false;


//int
int bulletNUM = 0;
int frameCount = 0;
int lastSec = 0;
int score = 0;
int damage = 0;
int bulletCount = 0;
int keyNum = NULL;
int randXNUM, randYNUM, randX,randY,randXnum,randYnum;
int HitCheck;
int list;

//double
double x,y;
double movingBulletX[300];
double movingBulletY[300];
double movingBulletZ[300];
double _movingXPoint;
double _movingYPoint;
double _movingZPoint;
double enemyPosCheck[3];
double RRPosCheck[3];
double RLPosCheck[3];
double LRPosCheck[3];
double LLPosCheck[3];
double firstClickXPos=0,firstClickYPos=0,saveXPos=0,saveYPos = 0;
double LLMissileCont = 0.0, LRMissileCont = 0.0, RLMissileCont = 0.0, RRMissileCont = 0.0;

//float
float movingRRXPoint = 0, movingRRYPoint = 0, movingRLXPoint = 0, movingRLYPoint = 0, movingLRXPoint = 0, movingLRYPoint = 0, movingLLXPoint = 0, movingLLYPoint = 0;
GLfloat red[] = { 1.0, 0.4, 0.3, 1.0 };  //赤
GLfloat blue[] = { 0.4, 0.6, 1.0, 1.0 };  //青
GLfloat green[] = { 0.2,1.0,0.4 };     //緑
GLfloat white[] = { 1,1,1};    //白
float shininess = 128.0;
float rightrightPos = 0,rightleftPos = 0,leftrightPos= 0,leftleftPos = 0;
float diffuse[] = { 1,1,1,1 };
float specular[] = { 1,1,1,1 };
float ambient[] = { 0.1,0.1,0.1,1.0 };
float light[] = { 1.0,1.0,1.0,0.0 };
float enemyPos;

//char
char t_char[20];
char t_char2[20];
char t_char3[20];
char t_char4[60];
char t_char5[20];
char t_char6[30];
char t_char7[40];

//vector
std::pair<std::vector<double>, std::vector<double>> CoordinateXY;

//関数の宣言
void DISPLAY_TEXT(int x, int y, char* string);
void DRAW_STRING(int x, int y, char* string, void* font);
void Bullet(int num);
void disp()
{
    /*
    今後の追加予定
    ・OpenMPを用いたGPUによる並列処理(これはfor分の中身が大きすぎて抜け出せなくなるような場所に使用するべき)
    ・機銃の追加
    ・機銃とミサイルにそれぞれ攻撃力を設定し、それぞれを切り替えるキーバインドの追加
    ・オンライン対戦機能の追加
    ・NPCオブジェクトの追加
    ・追加ミサイルオブジェクトや追加パーツオブジェクトの追加
    ・敵オブジェクトを倒した際にお金をドロップ、そのお金を使って機体のアップグレードできるようにしたい
    ・テクスチャマッピングを用いて青空の描写
    ・移動時の機体の方向ベクトル、ミサイルと機銃の発射方向ベクトルは常にディスプレイ座標Z軸向きになるようにする
    ・ディスプレイ座標軸に発射・移動するものをワールド座標系に変換してdisp()内で描画する
    ・分割コンパイル
    */



        GLfloat light0pos[] = { 10.0 - _movingXPoint, 10.0 - _movingYPoint, 7.0, 0.5 };

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (dead == true)
        {
            sprintf_s(t_char5, "You are dead!");
            DISPLAY_TEXT(46, 55, t_char5);
            sprintf_s(t_char6, "Your score is %d",score);
            DISPLAY_TEXT(46, 50, t_char6);
            sprintf_s(t_char7, "Play Again? --> Y/N");
            DISPLAY_TEXT(44, 42, t_char7);


        }
        if (GUI == true)
        {
            sprintf_s(t_char, "Time: %d", 40 - lastSec);
            DISPLAY_TEXT(0, 95, t_char);
            sprintf_s(t_char2, "Score: %d", score);
            DISPLAY_TEXT(95, 95, t_char2);
            sprintf_s(t_char3, "HP: %d", 10 - damage);
            DISPLAY_TEXT(2, 2, t_char3);
        }
        if(pauseBool == true)
        {
            sprintf_s(t_char4, "Please Press SHIFT_R and start game!");
            DISPLAY_TEXT(40, 55, t_char4);
        }
        if (timeOver == true)
        {
            sprintf_s(t_char5, "Finish!");
            DISPLAY_TEXT(48, 55, t_char5);
            sprintf_s(t_char6, "Your score is %d", score);
            DISPLAY_TEXT(45, 50, t_char6);
            sprintf_s(t_char7, "Play Again? --> Y/N");
            DISPLAY_TEXT(44, 42, t_char7);

        }
        glShadeModel(GL_SMOOTH);
        glLoadIdentity();

        if (thirdSpec == true)
        {
            glRotatef(-_movingXPoint, 0, 0, 1);
            glRotatef(-_movingYPoint, 1, 0, 1);
            gluLookAt(0 , 1 , 10 , 0 , 1 , 0, 0, 1, 1);
            glTranslatef(0, 0, _movingZPoint);
        }

        else
        {
            glRotatef(_movingXPoint, 1, 0, 1);
            glRotatef(_movingYPoint, 0, 1, 1);

            gluLookAt(0 - _movingXPoint, 1 - _movingYPoint, -3, 0 - _movingXPoint, 1 - _movingYPoint, -5, 0, 1, 0);

        }
        glLightfv(GL_LIGHT0, GL_POSITION, light0pos);

        makeField(0.3, 0.3, 0.3);
        //if (pauseBool == false && dead == false && timeOver == false)
        //{
        //    if (enemycreate == false)
        //    {
        //        randX = rand() % 2;
        //        randY = rand() % 2;

        //        randXnum = rand() % 10;
        //        randYnum = rand() % 4;

        //        enemyPos = 0;
        //        if (randX == 1)
        //        {
        //            randXNUM = -randXnum;
        //        }
        //        else
        //        {
        //            randXNUM = randXnum;
        //        }
        //        if (randY == 1)
        //        {
        //            randYNUM = -randYnum;
        //        }
        //        else
        //        {
        //            randYNUM = randYnum;
        //        }
        //        enemycreate = true;
        //    }
        //    else
        //    {
        //        if (enemyPos > 68.0)
        //        {
        //            enemycreate = false;
        //            damage++;
        //        }
        //        glPushMatrix();
        //        glTranslatef(randXNUM, randYNUM, -70 + enemyPos);
        //        glVertexPointer(3, GL_FLOAT, 0, Enemyvertex);
        //        makeEnemy(1, 1, 1);
        //        glPopMatrix();
        //        enemyPos += 0.03;
        //    }
        //}

        glEnableClientState(GL_VERTEX_ARRAY);


        if (checkRightRightFire == true)
        {
            if (rightrightPos < -150.0)
            {
                checkRightRightFire = false;
                rightrightPos = 0;
                RRMissileCont = 0.0;
            }
            glPushMatrix();

            glTranslatef(movingRRXPoint + RRMissileCont, movingRRYPoint, rightrightPos - _movingZPoint);
            makeRightRightMissile(0.3, 0.3, 0.3);
            glPopMatrix();
            rightrightPos -= 0.1;
            RRMissileCont -= 0.5 / 300.0;
        }

        if (checkRightLeftFire == true)
        {
            if (rightleftPos < -150.0)
            {
                checkRightLeftFire = false;
                rightleftPos = 0;
                RLMissileCont = 0.0;
            }
            glPushMatrix();
            glTranslatef(movingRLXPoint + RLMissileCont, movingRLYPoint, rightleftPos - _movingZPoint);
            makeRightLeftMissile(0.3, 0.3, 0.3);
            glPopMatrix();
            rightleftPos -= 0.1;
            RLMissileCont -= 0.2 / 300.0;
        }
        
        if (checkLeftRightFire == true)
        {
            if (leftrightPos < -150.0)
            {
                checkLeftRightFire = false;
                leftrightPos = 0;
                LRMissileCont = 0.0;
            }
            glPushMatrix();
            glTranslatef(movingLRXPoint + LRMissileCont, movingLRYPoint, leftrightPos - _movingZPoint);
            makeLeftRightMissile(0.3, 0.3, 0.3);
            glPopMatrix();
            leftrightPos -= 0.1;
            LRMissileCont += 0.2 / 300.0;
        }

        if (checkLeftLeftFire == true)
        {
            if (leftleftPos < -150.0)
            {
                checkLeftLeftFire = false;
                leftleftPos = 0;
                LLMissileCont = 0.0;
            }
            glPushMatrix();
            glTranslatef(movingLLXPoint + LLMissileCont, movingLLYPoint, leftleftPos - _movingZPoint);
            makeLeftLeftMissile(0.3, 0.3, 0.3);
            glPopMatrix();
            leftleftPos -= 0.1;
            LLMissileCont += 0.5 / 300.0;
        }
        
        //boolBulletがtrueの時for分を作成し続ける

        //if (boolBullet == true)
        //{
        //    glPushMatrix();
        //    glTranslatef(movingBulletX[bulletNUM], movingBulletY[bulletNUM], movingBulletZ[bulletNUM]);
        //    glVertexPointer(3, GL_FLOAT, 0, Bulletvertex);
        //    makeBullet(0.3, 0.3, 0.3);
        //    glPopMatrix();
        //}
        

        if (goStraight == true)
        {
            _movingZPoint += 0.016;
        }

        glPushMatrix();
        glRotatef(_movingXPoint, 0, 0, 1);
        glRotatef(_movingYPoint, 1, 0, 0);
        glTranslatef(0, 0, -_movingZPoint);


        if (checkRightRightFire == false)
        {
            makeRightRightMissile(0.3, 0.3, 0.3);
        }
        if (checkRightLeftFire == false)
        {
            makeRightLeftMissile(0.3, 0.3, 0.3);
        }
        if (checkLeftRightFire == false)
        {
            makeLeftRightMissile(0.3, 0.3, 0.3);
        }
        if (checkLeftLeftFire == false)
        {
            makeLeftLeftMissile(0.3, 0.3, 0.3);
        }

        makeShip(0.3, 0.3, 0.3);

        if (thirdSpec == true)
        {
            makeThirdRet();

        }
        else
        {
            makeRet();
        }
        makeWing(0.4, 0.4, 0.4);

        makeFire1(0.44, 0.4, 0.4);

        makeFire2(0.4, 0.4, 0.44);

        makeTailWing(0.3, 0.3, 0.3);

        makeCockPit(0.8, 0.8, 0.8);



        glPopMatrix();
        if (pauseBool == false && dead == false && timeOver == false)
        {

            if (boolBullet == true)
            {
                frameCount++;
                if (frameCount > 100)
                {
                    frameCount = 0;
                    movingBulletX[bulletNUM] = -_movingXPoint;
                    movingBulletY[bulletNUM] = -_movingYPoint;
                    bulletNUM++;
                    if (bulletNUM == 300)
                    {
                        bulletNUM = 0;
                    }
                }
            }
#pragma omp parallel for
            for (int i = 0; i < bulletNUM; i++)
            {
                if (movingBulletZ[i] > -100)
                {
                    glPushMatrix();
                    glTranslatef(movingBulletX[i], movingBulletY[i], movingBulletZ[i] - _movingZPoint);
                    makeBullet(1, 1, 1);
                    glPopMatrix();
                    movingBulletZ[i] -= 0.2;
                }
            }
        }
        glutSwapBuffers();
        glFlush();
}


void reshape(int width, int height) 
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);					// 射影行列を操作する
    glLoadIdentity();						// 行列を初期化
    gluPerspective(60.0, (double)width / height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    y = 0;
}


void InitialProc()
{

    readPoints();
    _movingXPoint = 0;
    _movingYPoint = 0;
    _movingZPoint = 0;
    memset(movingBulletX, 0.0, sizeof(movingBulletX));
    memset(movingBulletY, 0.0, sizeof(movingBulletY));
    memset(movingBulletZ, 0.0, sizeof(movingBulletZ));    

    


}
void keyUp(unsigned char key, int x, int y)
{
    if (key == 'w')
    {
        goStraight = false;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 0x1b)
        exit(0);

    if (key == 'w')
    {
        goStraight = true;
    }
    if (key == 'v')
    {
        if (thirdSpec == true)
        {
            thirdSpec = false;
        }
        else
        {
            thirdSpec = true;
        }
    }
    if (key == 'c')
    {
        if (weaponChange == false)
        {
            weaponChange = true;
        }
        else
        {
            weaponChange = false;
        }
    }
    if (retry == true)
    {
        if (key == 'y')
        {
            dead = false;
            retry = false;
            GUI = true;
            weaponChange = false;
            checkRightRightFire = false;
            checkRightLeftFire = false;
            checkLeftRightFire = false;
            checkLeftLeftFire = false;
            twobyone = false, rightButton = false, leftButton = false;
            enemycreate = false;
            pause = false;
            thirdSpec = true;
            pauseBool = true;
            timeOver = false;
            boolBullet = false;


            memset(movingBulletX, 0.0, sizeof(movingBulletX));
            memset(movingBulletY, 0.0, sizeof(movingBulletY));
            memset(movingBulletZ, 0.0, sizeof(movingBulletZ));

            score = 0;
            damage = 0;
            bulletNUM = 0;
            lastSec = 0;
            bulletCount = 0;


        }
        else if (key == 'n')
        {
            exit(0);
        }
    }
}
void spe(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        keyNum = GLUT_KEY_UP;
        break;
    case GLUT_KEY_DOWN:
        keyNum = GLUT_KEY_DOWN;
        break;
    case GLUT_KEY_LEFT:
        keyNum = GLUT_KEY_LEFT;
        break;
    case GLUT_KEY_RIGHT:
        keyNum = GLUT_KEY_RIGHT;
        break;
    case GLUT_KEY_HOME:
        if (checkRightRightFire == true && checkLeftLeftFire == true && checkLeftRightFire == true)
        {
            checkRightLeftFire = true;
            movingRLXPoint = -_movingXPoint;
            movingRLYPoint = -_movingYPoint;
        }
        if (checkRightRightFire == true && checkLeftRightFire == true)
        {
            checkLeftLeftFire = true;
            movingLLXPoint = -_movingXPoint;
            movingLLYPoint = -_movingYPoint;
        }
        else if (checkLeftRightFire == true)
        {
            checkRightRightFire = true;
            movingRRXPoint = -_movingXPoint;
            movingRRYPoint = -_movingYPoint;
        }
        else if (checkRightLeftFire == true)
        {
            checkLeftRightFire = true;
            movingLRXPoint = -_movingXPoint;
            movingLRYPoint = -_movingYPoint;
        }
        else if (checkLeftLeftFire == true)
        {
            checkRightLeftFire = true;
            movingRLXPoint = -_movingXPoint;
            movingRLYPoint = -_movingYPoint;
        }
        else if (checkRightRightFire == true)
        {
            checkLeftLeftFire = true;
            movingLLXPoint = -_movingXPoint;
            movingLLYPoint = -_movingYPoint;
        }
        else if (checkLeftLeftFire == false && checkLeftRightFire == false && checkRightLeftFire == false && checkRightRightFire == false)
        {
            checkRightRightFire = true;
            movingRRXPoint = -_movingXPoint;
            movingRRYPoint = -_movingYPoint;
        }
        break;
    case GLUT_KEY_SHIFT_R:
        if (pauseBool == true)
        {
            pauseBool = false;
            GUI = true;
        }
        else
        {
            pauseBool = true;
            GUI = false;
        }
        break;
    case GLUT_KEY_SHIFT_L:
        break;
    }
    onKeyPress = true;
}
void speUP(int key, int x, int y)
{
    onKeyPress = false;
    keyNum = NULL;
}

void idle(void)
{
    if (damage == 10)
    {
        dead = true;
        retry = true;
        GUI = false;
    }
    HitCheck = 0;

    enemyPosCheck[0] = randXNUM;
    enemyPosCheck[1] = randYNUM;
    enemyPosCheck[2] = enemyPos - 70;
    if (checkRightRightFire == true)
    {
        RRPosCheck[0] = movingRRXPoint;
        RRPosCheck[1] = movingRRYPoint;
        RRPosCheck[2] = rightrightPos;
    }
    else
    {
        RRPosCheck[0] = -_movingXPoint;
        RRPosCheck[1] = -_movingYPoint;
        RRPosCheck[2] = 0;
    }
    if (checkRightLeftFire == true)
    {
        RLPosCheck[0] = movingRLXPoint;
        RLPosCheck[1] = movingRLYPoint;
        RLPosCheck[2] = rightleftPos;
    }
    else
    {
        RLPosCheck[0] = -_movingXPoint;
        RLPosCheck[1] = -_movingYPoint;
        RLPosCheck[2] = 0;
    }
    if (checkLeftRightFire == true)
    {
        LRPosCheck[0] = movingLRXPoint;
        LRPosCheck[1] = movingLRYPoint;
        LRPosCheck[2] = leftrightPos;
    }
    else
    {
        LRPosCheck[0] = -_movingXPoint;
        LRPosCheck[1] = -_movingYPoint;
        LRPosCheck[2] = 0;
    }
    if (checkLeftLeftFire == true)
    {
        LLPosCheck[0] = movingLLXPoint;
        LLPosCheck[1] = movingLLYPoint;
        LLPosCheck[2] = leftleftPos;
    }
    else
    {
        LLPosCheck[0] = -_movingXPoint;
        LLPosCheck[1] = -_movingYPoint;
        LLPosCheck[2] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        if (enemyPosCheck[i] + 0.62 > RRPosCheck[i] && RRPosCheck[i] > enemyPosCheck[i] - 0.62)
        {
            HitCheck++;
        }
        if (HitCheck == 3)
        {
            enemycreate = false;
            movingRRYPoint += 50;
            score++;
            HitCheck = 0;
        }

    }
    HitCheck = 0;
    for (int i = 0; i < 3; i++)
    {
        if (enemyPosCheck[i] + 0.62 > RLPosCheck[i] && RLPosCheck[i] > enemyPosCheck[i] - 0.62)
        {
            HitCheck++;
        }
        if (HitCheck == 3)
        {
            enemycreate = false;
            movingRLYPoint += 50;
            score++;
            HitCheck = 0;
        }
    }
    HitCheck = 0;
    for (int i = 0; i < 3; i++)
    {
        if (enemyPosCheck[i] + 0.62 > LRPosCheck[i] && LRPosCheck[i] > enemyPosCheck[i] - 0.62)
        {
            HitCheck++;
        }
        if (HitCheck == 3)
        {
            enemycreate = false;
            movingLRYPoint += 50;
            score++;
            HitCheck = 0;
        }
    }
    HitCheck = 0;
    for (int i = 0; i < 3; i++)
    {
        if (enemyPosCheck[i] + 0.62 > LLPosCheck[i] && LLPosCheck[i] > enemyPosCheck[i] - 0.62)
        {
            HitCheck++;
        }
        if (HitCheck == 3)
        {
            enemycreate = false;
            movingLLYPoint += 50;
            score++;
            HitCheck = 0;
        }
    }
    
    //if (_movingXPoint > 20)
    //    _movingXPoint = -20;
    //if (_movingXPoint < -20)
    //    _movingXPoint = 20;
    //if (_movingYPoint > 8)
    //    _movingYPoint = -10;
    //if (_movingYPoint < -10)
    //    _movingYPoint = 8;

    if (onKeyPress)
    {
        if (keyNum == GLUT_KEY_UP)
        {
            _movingYPoint -= 0.05;

        }
        if (keyNum == GLUT_KEY_DOWN)
        {
            _movingYPoint += 0.05;


        }
        if (keyNum == GLUT_KEY_LEFT)
        {
            _movingXPoint += 0.05;


        }
        if (keyNum == GLUT_KEY_RIGHT)
        {
            _movingXPoint -= 0.05;


        }

    }
    glutPostRedisplay();


}

void mouse(int button, int state, int x, int y)//マウスをクリックする瞬間しか読まない
{
    if (pauseBool == false && dead == false && timeOver == false)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            if (weaponChange == false)
            {
                if (twobyone == false)
                {
                    if (checkRightRightFire == true && checkLeftLeftFire == true && checkLeftRightFire == true)
                    {
                        checkRightLeftFire = true;
                        movingRLXPoint = -_movingXPoint;
                        movingRLYPoint = -_movingYPoint;
                    }
                    if (checkRightRightFire == true && checkLeftRightFire == true)
                    {
                        checkLeftLeftFire = true;
                        movingLLXPoint = -_movingXPoint;
                        movingLLYPoint = -_movingYPoint;
                    }
                    else if (checkLeftRightFire == true)
                    {
                        checkRightRightFire = true;
                        movingRRXPoint = -_movingXPoint;
                        movingRRYPoint = -_movingYPoint;
                    }
                    else if (checkRightLeftFire == true)
                    {
                        checkLeftRightFire = true;
                        movingLRXPoint = -_movingXPoint;
                        movingLRYPoint = -_movingYPoint;
                    }
                    else if (checkLeftLeftFire == true)
                    {
                        checkRightLeftFire = true;
                        movingRLXPoint = -_movingXPoint;
                        movingRLYPoint = -_movingYPoint;
                    }
                    else if (checkRightRightFire == true)
                    {
                        checkLeftLeftFire = true;
                        movingLLXPoint = -_movingXPoint;
                        movingLLYPoint = -_movingYPoint;
                    }
                    else if (checkLeftLeftFire == false && checkLeftRightFire == false && checkRightLeftFire == false && checkRightRightFire == false)
                    {
                        checkRightRightFire = true;
                        movingRRXPoint = -_movingXPoint;
                        movingRRYPoint = -_movingYPoint;
                    }
                    twobyone = true;
                }
                else
                {
                    twobyone = false;
                }
            }
            else
            {
                //ここに弾丸
                if (boolBullet == true)
                {
                    boolBullet = false;

                }
                else
                {
                    boolBullet = true;

                }

            }
        }
    }
}
void passiveMotion(int x, int y)
{
    if (pauseBool == false && dead == false && timeOver == false)
    {
        _movingXPoint -= (x - 900) / 50.0;//dx
        _movingYPoint += (y - 500) / 50.0;//dy
        glutWarpPointer(900, 500);
        glutMouseFunc(mouse);
    }
}
void clickingMotion(int x, int y)//クリックしながら動かさないと読まない
{
    if (pauseBool == false && dead == false && timeOver == false)
    {
        _movingXPoint -= (x - 900) / 50.0;
        _movingYPoint += (y - 500) / 50.0;
        glutWarpPointer(900, 500);
        glutMouseFunc(mouse);
    }

}
void DISPLAY_TEXT(int x, int y, char* string) {
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPushAttrib(GL_ENABLE_BIT);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glCallList(list);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();
    glMatrixMode(GL_MODELVIEW);
    list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    DRAW_STRING(x, y, string, GLUT_BITMAP_HELVETICA_18);
    glEndList();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void DRAW_STRING(int x, int y, char* string, void* font) {
    int len, i;
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {

        glutBitmapCharacter(font, string[i]);
    }
}
void timerCallback(int x)
{
    if (pauseBool == false && dead == false && timeOver == false)
    {
        lastSec += 1;
        if (lastSec == 40)
        {
            retry = true;
            GUI = false;
            timeOver = true;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000, timerCallback, 0);
}
int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitWindowSize(1980, 1080);
    glutCreateWindow("Ace combat");
    glutWarpPointer(900, 500);

    _movingXPoint = 0;
    _movingYPoint = 0;
    _movingZPoint = 0;
    memset(movingBulletX, 0.0, sizeof(movingBulletX));
    memset(movingBulletY, 0.0, sizeof(movingBulletY));
    memset(movingBulletZ, 0.0, sizeof(movingBulletZ));

    glutGameModeString("1920x1080:1@60");  // 解像度とビット深度を適切に指定
    glutEnterGameMode();
    glutSetCursor(GLUT_CURSOR_NONE);
    InitialProc();
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(spe);
    glutSpecialUpFunc(speUP);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    glutMotionFunc(clickingMotion);
    glutMouseFunc(mouse);

    glutIdleFunc(idle);
    glutReshapeFunc(reshape);   
    glutDisplayFunc(disp);
    glutTimerFunc(1000, timerCallback, 0);
    glutIgnoreKeyRepeat(GL_TRUE);
    glutKeyboardFunc(keyboard);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);        //ライティングON
    glEnable(GL_LIGHT0);

    glutMainLoop();

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);        //ライティングOFF
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);


    return 0;
}