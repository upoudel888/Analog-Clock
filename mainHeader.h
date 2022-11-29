#ifndef MAINHEADER_H_INCLUDED
#define MAINHEADER_H_INCLUDED

#include <GL/glut.h> /
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

#include "timer.h"

#define BLUE_COLOR glColor3ub(3,130,211)
#define CLOCK_BACK_COLOR glColor3ub(236,236,236)
#define CLOCK_BACK_COLOR1 glColor4ub(0,0,0,0.01)

#define FONT GLUT_BITMAP_HELVETICA_10
#define DEF_D 5

/*  Macro for sin & cos in degrees */
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

// this structure will be used to pass the color
struct displayColor{
    int r1; int r3;
    int g1; int g3;
    int b1; int b3;
    int r2;
    int g2;
    int b2;
    int a;       //alpha value of CSA

};

extern struct displayColor c;

#endif // MAINHEADER_H_INCLUDED
