#include "drawShapes.h"
#include "mainHeader.h"
struct displayColor c;



// timer class to get hour,minute and second angles
timer timeObj;

int secondAngle = timeObj.getSecondAngle();
int minuteAngle = timeObj.getMinuteAngle();
int hourAngle = timeObj.getHourAngle();


/*Globals*/
double dim = 3.0;/*dimension of orthogonal box*/
char*windowName="Tick-Tikey";
int windowWidth=700;
int windowHeight=650;

/*Various global state*/
/*Toggles*/
int toggleAxes;/*toggle axes on and off*/


/*Display view*/
int th=0;/*azimuth of view angle*/
int ph=0;/*elevation of view angle*/


//to print some strings at a point
void printAt(int x, int y, int z, char *string)
{
  glColor3f( 1,1, 0 );
  glRasterPos3d(x, y,z);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(FONT, string[i]);
  }
}

void drawAxes(){
    if(toggleAxes){
      /*Length of axes*/
      double len = 2.0;
      glColor3f(1.0,0.0,1.0);
      glBegin(GL_LINES);
      glVertex3d(0,0,0);
      glVertex3d(len,0,0);
      glVertex3d(0,0,0);
      glVertex3d(0,len,0);
      glVertex3d(0,0,0);
      glVertex3d(0,0,len);
      glEnd();
      printAt(len,0,0,"X");
      printAt(0,len,0,"Y");
      printAt(0,0,len,"z");
    }
}


void initialize(){
    glClearColor(0.7725,0.7803,0.8627,1.0);

}

//callback for glTimerFunc that is called every 1 second
void spin(int time){
    timeObj.updateLocalTime();
    secondAngle = timeObj.getSecondAngle();
    if(secondAngle == 0){
        minuteAngle = timeObj.getMinuteAngle();
    }
    hourAngle = timeObj.getHourAngle();

    glutPostRedisplay();
    glutTimerFunc(1000,spin,0);

}




void drawClock(){

    //the outer blue ring
    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r2 = 44; c.g2 = 182; c.b2 = 245; c.a = 1;
    drawRing(1.7,1.9,0.15);

    //the nook of the outer ring
    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r2 = 3; c.g2 = 130; c.b2 = 211; c.a = 1;
    drawCylinder(1.9,0.15,0.1,0);


    //the body of the clock
    c.r1 = 44; c.g1 = 182; c.b1 = 245;
    c.r2 = 3; c.g2 = 130; c.b2 = 211; c.a = 1;
    c.r3 = 226; c.g3 = 230; c.b3 = 233;
    drawCylinder(1.7,-0.08,0.2,2);

    //the axle that holds all pins
    c.r1 = 255; c.g1 = 215; c.b1 = 0;
    c.r2 = 255; c.g2 = 215; c.b2 = 0; c.a = 1;
    c.r3 = 206; c.g3 = 226; c.b3 = 209;
    drawCylinder(0.04,0.07,0.2,2);

    //Pin at the top of axle
    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r3 = 3; c.g3 = 130; c.b3 = 211;
    c.r2 = 3; c.g2 = 130; c.b2 = 211;
    drawCylinder(0.12,0.08,0.03,2);  //radius, basePos, length, circleFlag

    //the circle on top of the pin
    glColor3ub(44,182,245);
    drawCircle(0.1,0,0,0.081);


    c.r1 = 44; c.g1 = 182; c.b1 = 245;
    c.r2 = 230; c.g2 = 236; c.b2 = 226; c.a = 1;
    drawRing(0,1.71,-0.282);

    GLfloat batteryComp[8][3] ={
            //front
            {-0.7,-0.7,-0.28},
            {0.7,-0.7,-0.28},
            {0.7,0.7,-0.28}, //top
            {-0.7,0.7,-0.28},   //bottom
            //back
            {-0.7,-0.7,-0.5},
            {0.7,-0.7,-0.5},
            {0.7,0.7,-0.5},
            {-0.7,0.7,-0.5},

            };
    c.r1 = 44; c.g1 = 182; c.b1 = 245;
    c.r2 = 3; c.g2 = 130; c.b2 = 211; c.a = 255;
    drawCube1(batteryComp);



    //drawing the hanger
    //hanger for the clock

    GLfloat hangerComp[8][3]={
            //front
            {-0.15,0.7,-0.28},
            {0.15,0.7,-0.28},
            {0.15,1,-0.28},
            {-0.15,1,-0.28},
            //back
            {-0.15,0.7,-0.5},
            {0.15,0.7,-0.5},
            {0.15,1,-0.5},
            {-0.15,1,-0.5},

    };
    c.r1 = 44; c.g1 = 182; c.b1 = 245;
    c.r2 = 3; c.g2 = 130; c.b2 = 211; c.a = 255;
    drawCube1(hangerComp);


    //two holes where the nail goes
    drawCylinder(0.075,0,0.8,-0.28,0.23,2);
    drawCylinder(0.05,0,0.88,-0.28,0.23,2);

    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r2 = 3; c.g2 = 130; c.b2 = 211;
    //battery compartment
    GLfloat batteryHole[8][3] = {
        {-0.4,-0.3,-0.28},
            {0.55,-0.3,-0.28},
            {0.55,0.4,-0.28}, //top
            {-0.55,0.4,-0.28},//bottom
            {-0.55,-0.3,-0.51},
            {0.55,-0.3,-0.51},
            {0.55,0.4,-0.51}, //top
            {-0.55,0.4,-0.51}   //bottom
    };

    drawCube(batteryHole);

    //the pin at the battery compartement
    //Pin at the back to adjust time
    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r3 = 3; c.g3 = 130; c.b3 = 211;
    c.r2 = 3; c.g2 = 130; c.b2 = 211;
    //drawCylinder(0.12,-0.51,0.03,2);  //radius, basePos, length, circleFlag
    drawCylinder(0.12,-0.45,-0.45,-.50,0.03,2);

    //the circle on top of the pin

    glColor3ub(0,182,245);
    drawCircle(0.1,0,0,-0.56,-0.45,-0.45);


    glBegin(GL_POLYGON);
        glVertex3f(-0.5,0.35,-0.52);
        glVertex3f(0.5,0.35,-0.52);
        glVertex3f(0.5,0.1,-0.52);
        glVertex3f(-0.5,0.1,-0.52);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(0.5,0.0,-0.52);
         glVertex3f(-0.5,0.0,-0.52); //left ko duita
         glVertex3f(-0.5,-0.25,-0.52);
         glVertex3f(0.5,-0.25,-0.52);  //right ko duita
    glEnd();

    //drawing hour, minute, and second pointers
    GLfloat second[8][3] ={
            //front
            {-0.03,-0.25,0.05},
            {0.03,-0.25,0.05},
            {0.03,1.25,0.05},
            {-0.03,1.25,0.05},
            //back
            {-0.03,-0.3,0.03},
            {0.03,-0.3,0.03},
            {0.03,1.3,0.03},
            {-0.03,1.3,0.03},

            };

    GLfloat minute[8][3] = {
            //front
            {0.045,0,0.01}, // top
            {0.045,1.2,0.01},
            {-0.045,1.2,0.01},
            {-0.045,0,0.01},

            //back
            {0.055,0,-0.01},
            {0.045,1.2,-0.01},
            {-0.045,1.2,-0.01},
            {-0.045,0,-0.01},
    };

    GLfloat hour[8][3] = {
            //front
            {0.069,0,-0.03},
            {0.069,1,-0.03},
            {-0.069,1,-0.03},
            {-0.069,0,-0.03},

            //back
            {0.069,0,-0.05},
            {0.069,1,-0.05},
            {-0.069,1,-0.05},
            {-0.069,0,-0.05},
    };

    c.r1 = 3; c.g1 = 130; c.b1 = 211;
    c.r2 = 44; c.g2 = 182; c.b2 = 245; c.a = 1;
    //second pointer
    glPushMatrix();
        glRotatef(-secondAngle,0,0,0.2);
        drawCube(second);
        drawCylinder(0.03,0,1.3,0.05,0.02,2);   //circle at tip
        drawCylinder(0.03,0,-0.3,0.05,0.02,2);  //circle at rare end
    glPopMatrix();
    drawCylinder(0.1,0,0,0.05,0.02,2); //mount to the axle

    glPushMatrix();
        glRotatef(-minuteAngle,0,0,0.2);
        drawCylinder(0.045,0,1.2,0.01,0.02,2);   //circle at tip
        drawCube(minute);
    glPopMatrix();
    drawCylinder(0.1,0,0,0.01,0.02,2); //mount to the axle

    glPushMatrix();
        glRotatef(-hourAngle,0,0,0.2);
        drawCylinder(0.069,0,1,-0.03,0.02,2);
        drawCube(hour);
    glPopMatrix();
    drawCylinder(0.1,0,0,-0.03,0.02,2); //mount to the axle


    c.r1 = 0; c.g1 = 0; c.b1 = 0;
    c.r2 = 23; c.g2 = 14; c.b2 = 105; c.a = 1;
    //drawing the time guide points on the clock

    GLfloat largeSpikes[8][3] ={
            //front
            {-0.02,1.4,-0.07},
            {0.02,1.4,-0.07},
            {0.02,1.6,-0.07},
            {-0.02,1.6,-0.07},
            //back
            {-0.02,1.4,-0.09},
            {0.02,1.4,-0.09},
            {0.02,1.6,-0.09},
            {-0.02,1.6,-0.09},

            };
    GLfloat smallSpikes[8][3] ={
            //front
            {-0.015,1.45,-0.07},
            {0.015,1.45,-0.07},
            {0.015,1.55,-0.07},
            {-0.015,1.55,-0.07},
            //back
            {-0.02,1.45,-0.09},
            {0.02,1.45,-0.09},
            {0.02,1.55,-0.09},
            {-0.02,1.55,-0.09},

            };


    for(int j = 0; j<360; j+=6){
        glPushMatrix();
            glRotated(j,0,0,1);
            if(j % 30 == 0){
                drawCube(largeSpikes);
            }else{

                drawCube(smallSpikes);
            }

        glPopMatrix();
    }




    //the clear part after the nook
    glEnable(GL_BLEND);
        c.r1 = 240; c.g1 = 240; c.b1 = 240;
        c.r2 = 44; c.g2 = 182; c.b2 = 245; c.a = 80;
        drawCylinder(1.7,0,0,0.15,0.23,0);

    glDisable(GL_BLEND);


}

void display()
{
    //clear previous buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glDepthRange(0.0f, 1.0f);

    //resetting previous transforms
    glLoadIdentity();

    //setting viewing angles
    glRotated(ph,1,0,0);
    glRotated(th,0,1,0);

    /*Draw*/
    drawAxes();
    drawClock();

    //flush the buffer and swap
    glFlush();
    glutSwapBuffers();
}

void reshape(int width,int height)
{
    double w2h = (height>0)?(double)width/height :1;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /*orthogonal projection*/
    glOrtho(-dim*w2h,+dim*w2h,-dim,+dim,-dim,+dim);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void windowKey(unsigned char key,int x,int y)
{
    //exit on escape
    if(key ==27) exit(0);
    else if(key=='a' ||  key=='A')toggleAxes = 1-toggleAxes;;

    glutPostRedisplay();
}

void windowSpecial(int key, int x , int y){

    /*Right arrow key increase azimuth by5degrees*/
    if(key==GLUT_KEY_RIGHT)th+=5;
    /*Left arrow key decrease azimuth by5degrees*/
    else if(key==GLUT_KEY_LEFT)th-=5;
    /*Up arrow key increase elevation by5degrees*/
    else if(key==GLUT_KEY_UP)ph+=5;
    /*Down arrow key decrease elevation by5degrees*/
    else if(key == GLUT_KEY_DOWN)ph -=5;
    /*Keep angles to +/- 360 degrees*/
    th%=360;
    ph%=360;

    glutPostRedisplay();

}

void windowMenu(int value)
{
    windowKey((unsigned char)value,0,0);
}



int main(int argc,char**argv)
{

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
  glutInitWindowSize(windowWidth,windowHeight);
  glutCreateWindow(windowName);
  initialize();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(windowKey);
  glutSpecialFunc(windowSpecial);


  glutCreateMenu(windowMenu);
  glutAddMenuEntry("Toggle Axes[a]",'a');
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutTimerFunc(1000,spin,0);



  glutMainLoop();
  return 0;
}
