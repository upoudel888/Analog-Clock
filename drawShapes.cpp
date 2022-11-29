#include "drawShapes.h"
#include "mainHeader.h"


void quad(GLfloat ver0[3], GLfloat ver1[3], GLfloat ver2[3], GLfloat ver3[3])
{
    glBegin(GL_QUADS);
    glColor3ub(c.r2,c.g2,c.b2);
    glVertex3fv(ver0);

    glColor3ub(c.r2,c.g2,c.b2);
    glVertex3fv(ver1);

    glColor3ub(c.r1,c.g1,c.b1);
    glVertex3fv(ver2);

    glColor3ub(c.r1,c.g1,c.b1);
    glVertex3fv(ver3);
    glEnd();
}

void quad1(GLfloat ver0[3], GLfloat ver1[3], GLfloat ver2[3], GLfloat ver3[3])
{
    glBegin(GL_QUADS);

    glColor3ub(c.r2,c.g2,c.b2);
    glVertex3fv(ver0);
    glColor3ub(c.r2,c.g2,c.b2);
    glVertex3fv(ver1);
    glColor3ub(c.r1,c.g1,c.b1);
    glVertex3fv(ver2);
    glColor3ub(c.r1,c.g1,c.b1);
    glVertex3fv(ver3);
    glEnd();
}

void drawCube1(GLfloat vertex[8][3]){
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        quad1(vertex[0],vertex[3],vertex[2],vertex[1]); //top
        quad1(vertex[2],vertex[3],vertex[7],vertex[6]);  //bottom
        quad1(vertex[3],vertex[0],vertex[4],vertex[7]);
        quad1(vertex[1],vertex[2],vertex[6],vertex[5]);
        quad1(vertex[0],vertex[1],vertex[5],vertex[4]);
        c.r1 = c.r2 = 44; c.g1 = c.g2 =182 ; c.b1 = c.b2 = 245;
        quad1(vertex[4],vertex[5],vertex[6],vertex[7]);
    glDisable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);
}

void drawCube(GLfloat vertex[8][3]){
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        quad(vertex[0],vertex[3],vertex[2],vertex[1]); //top
        quad(vertex[2],vertex[3],vertex[7],vertex[6]);  //bottom
        quad(vertex[0],vertex[4],vertex[7],vertex[3]);
        quad(vertex[1],vertex[2],vertex[6],vertex[5]);
        quad(vertex[4],vertex[5],vertex[6],vertex[7]);
        quad(vertex[0],vertex[1],vertex[5],vertex[4]);
    glDisable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);
}

void drawTrianglePrism(GLfloat vertex[6][3]){
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
        //triangle(vertex[0],vertex[1],vertex[2]); //front
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(vertex[0][0],vertex[0][1],vertex[0][2]);
            glVertex3f(vertex[1][0],vertex[1][1],vertex[1][2]);
            glVertex3f(vertex[2][0],vertex[2][1],vertex[2][2]);
        glEnd();

        //triangle(vertex[3],vertex[4],vertex[5]);  //back

        glBegin(GL_TRIANGLE_FAN);
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(vertex[3][0],vertex[3][1],vertex[3][2]);
            glVertex3f(vertex[4][0],vertex[4][1],vertex[4][2]);
            glVertex3f(vertex[5][0],vertex[5][1],vertex[5][2]);
        glEnd();

        quad(vertex[0],vertex[2],vertex[4],vertex[5]); //slant side
        quad(vertex[1],vertex[3],vertex[4],vertex[2]);  //slant side
        quad(vertex[0],vertex[1],vertex[3],vertex[5]);  //bottom
    glDisable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);
}


void drawCircle(float r, float x, float y,float z,float h, float k) {
        float i = 0.0f;
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(x+h, y+k,z); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex3f(r*cos(M_PI * i / 180.0) + x + h, r*sin(M_PI * i / 180.0) + y + k,z);


        glEnd();
}

void drawRing(float r2, float r1,float basePos){
    glBegin(GL_QUAD_STRIP);
    for(int j = 0; j<= 360; j+= DEF_D){
        glColor3ub(c.r1,c.g1, c.b1);
        glVertex3f(r1*Sin(j),r1*Cos(j),basePos);
        glColor3ub(c.r2,c.g2, c.b2);
        glVertex3f(r2*Sin(j),r2*Cos(j),basePos);
    }
    glEnd();
}

//circleFlag = 1 // draw circle at front
//circleFlag = -1 //draw circle at back
//circleFlag = 2 // draw circle at front and back
void drawCylinder(float r, float basePos, float length,int circleFlag){
    glBegin(GL_QUAD_STRIP);
    for(int j = 0; j<= 360; j+=DEF_D){
        glColor3ub(c.r1,c.g1, c.b1);
        glVertex3f(r*Sin(j),r*Cos(j),basePos);
        glColor3ub(c.r2,c.g2, c.b2);
        //glVertex3f ver1[3] = { r*Sin(j),r*Cos(j),basePos-length}
        glVertex3f(r*Sin(j),r*Cos(j),basePos-length);

    }
    glEnd();

    glColor4ub(c.r3,c.g3,c.b3,c.a);
    if(circleFlag == -1){
        drawCircle(r,0,0,basePos-length); //draws top circle at the rare end only
    }else if(circleFlag == 1){              //draws top at the front end only
        drawCircle(r,0,0,basePos);
    }else if(circleFlag == 2){              //draws top circle both ends
        drawCircle(r,0,0,basePos);
        drawCircle(r,0,0,basePos-length);
    }
}

void drawCylinder(float r, float x, float y, float z, float length, int circleFlag){

    glBegin(GL_QUAD_STRIP);
    for(int j = 0; j<= 360; j+=DEF_D){
        glColor3ub(c.r1,c.g1, c.b1);
        glVertex3f(x+r*Sin(j),y+r*Cos(j),z);
        glColor4ub(c.r2,c.g2, c.b2,c.a);
        glVertex3f(x+r*Sin(j),y+r*Cos(j),z-length);
    }
    glEnd();

    BLUE_COLOR;
    if(circleFlag == -1){
        drawCircle(r,x,y,z-length);
    }else if(circleFlag == 1){
        drawCircle(r,x,y,z);
    }else if(circleFlag == 2){
        drawCircle(r,x,y,z);
        drawCircle(r,x,y,z-length);
    }
}


