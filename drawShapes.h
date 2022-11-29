#ifndef DRAWSHAPES_H_INCLUDED
#define DRAWSHAPES_H_INCLUDED

#include "mainHeader.h"

void quad(GLfloat,GLfloat,GLfloat,GLfloat);
void quad1(GLfloat,GLfloat,GLfloat,GLfloat);
void drawCube(GLfloat vertex[8][3]);
void drawCube1(GLfloat vertex[8][3]);

void drawCircle(float r, float x, float y,float z, float h = 0, float k = 0);
//circle flag to draw circle at top and bottom of the cylinder
void drawCylinder(float r, float basePos, float length,int circleFlag = 0);
void drawCylinder(float r, float x, float y, float z, float length, int circleFlag = 0);
void drawRing(float r2, float r1,float basePos);
void drawTrianglePrism(GLfloat vertex[6][3]);


#endif // DRAWSHAPES_H_INCLUDED
