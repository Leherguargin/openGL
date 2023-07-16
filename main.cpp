#include <stdio.h>
#include <cmath>

#include "GL/freeglut.h" 
#include "GL/gl.h"

#include <iostream>

using namespace std;
 
void drawTriangle() 
{ 
    glClearColor(0.4, 0.4, 0.4, 0.4); 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    glColor3f(1.0, 1.0, 1.0); 
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
 
        glBegin(GL_TRIANGLES); 
                glVertex3f(-0.7, 0.7, 0); 
                glVertex3f(0.7, 0.7, 0); 
                glVertex3f(0, -1, 0); 
        glEnd(); 
 
    glFlush(); 


    GLfloat f = 0.45f, g = 0.0f, h = 0.54f;
    for(int i = 0; i < 1000000000; i++)
    {
        g = h * f * 4.5;
    }
    cout << g << endl;
} 
 
// int main(int argc, char **argv)
// { 
//     glutInit(&argc, argv); 
//     glutInitDisplayMode(GLUT_SINGLE); 
//     glutInitWindowSize(500, 500); 
//     glutInitWindowPosition(100, 100); 
//     glutCreateWindow("OpenGL - Creating a triangle"); 
//     glutDisplayFunc(drawTriangle); 
//     glutMainLoop(); 
//     return 0; 
// }

void drawSphere(void)
{
  const int PI = 3.1415;
  const double distance = 20;

  //glEnable(GL_TEXTURE_2D);
  //glBindTexture(GL_TEXTURE_2D, ball);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  ////glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTranslated(0, 0, 5 + 0.6 * (PI * (GLdouble)8 + 0.1) * distance + sin(PI * (GLdouble)2 + 0.1));
  glColor3f(1, 0, 0);
  GLUquadric* quad;
  quad = gluNewQuadric();
  //gluQuadricTexture(quad, 1);
  gluSphere(quad, 4, 136, 136);

  //glDisable(GL_TEXTURE_2D);
}

void DrawCube()
{
  //glTranslated(0,0,100);
  glBegin(GL_QUADS);    
    glColor3f(1, 0, 0);  //red front
    glVertex3d(0, 0, 0);
    glVertex3d(100, 0, 0);
    glVertex3d(100, 100, 0);
    glVertex3d(0, 100, 0);

    glColor3b(0, 0, 1);  //blue top
    glVertex3d(0, 100, 0);
    glVertex3d(100, 100, 0);
    glVertex3d(100, 100, 100);
    glVertex3d(0, 100, 100);  
    
    glColor3b(1, 1, 0);  //yellow right
    glVertex3d(100, 100, 0);
    glVertex3d(100, 0, 0);
    glVertex3d(100, 0, -100);
    glVertex3d(100, 100, -100);

    glColor3b(1, 1, 1);  //white left
    glVertex3d(0, 100, 0);
    glVertex3d(0, 100, -100);
    glVertex3d(0, 0, -100);
    glVertex3d(0, 0, 0);  
    
    glColor3b(0, 1, 0);  //green bottom
    glVertex3d(100, 0, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, -100);
    glVertex3d(100, 0, -100);

    glColor3b(1, 0.5, 0);  //orange back
    glVertex3d(0, 100, -100);
    glVertex3d(100, 100, -100);
    glVertex3d(100, 0, -100);
    glVertex3d(0, 0, -100);

  glEnd();
}

void MyDisplay(void) {
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //drawSphere();
  DrawCube();
  glFlush();
}

void MyInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //kat widzenia w pionie(stopnie), szerokość/wysokość, pierwsza płąszczyzna odcinania, druga płaszczyzna odcinania
  gluPerspective(54.0, 1.0, 0.6, 270.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);//włączamy testowanie głębi
  glLoadIdentity();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 700);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My window");
  MyInit();
  glutDisplayFunc(MyDisplay);
  glutMainLoop();
  return 0;
}