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
    double rd = 0.0;
    int ri = 0;
    for(int i = 0; i < 1000'000; i++)
    {
        rd = 543.435 * 3234.342;
        ri = 343 * 4232;
    }
    cout << rd << ri << endl;
} 
 
int main(int argc, char **argv)
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("OpenGL - Creating a triangle"); 
    glutDisplayFunc(drawTriangle); 
    glutMainLoop(); 
    return 0; 
}