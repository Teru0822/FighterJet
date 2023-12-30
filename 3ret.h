#pragma once
#include "GL/freeglut.h"
#define ARRAY_MAX 10000000

float 3Rvertex[ARRAY_MAX];
int 3Rlines[ARRAY_MAX];
int 3RvertexDataSize = 0, 3RlineDataSize = 0;


void make3Ret()
{
    glPointSize(3);
    glColor3f(0, 1, 1);
    glBegin(GL_TRIANGLES); //–Ê‚Ì•`ŽÊ
    {
        for (int i = 0; i < 3RlineDataSize; i++) {
            glArrayElement(3Rlines[i * 3]);   //0
            glArrayElement(3Rlines[i * 3 + 1]);  //1
            glArrayElement(3Rlines[i * 3 + 2]);  //2
        }
    }
    glEnd();
}
