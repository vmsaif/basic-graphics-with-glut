#include <iostream>
#include "glut.h"
#include <cmath>

const double PI = atan(1) * 4;
const int houseCount = 5;

//set width and height of the display
double height = 500;
double width = 500;

double rect_line_length_half;
double triLineLength;

double degreeToRadian(double degree) {
	return (degree * PI) / 180;
}
void initialize() {
    glClearColor(1.0, 1.0, 1.0, 0.0); //set display-window color-white
}

void drawHouse(double centerX, double centerY) {

    //draw house
    glBegin(GL_POLYGON);
    glVertex2d(centerX - rect_line_length_half, centerY - rect_line_length_half); //bottom Left
    glVertex2d(centerX + rect_line_length_half, centerY - rect_line_length_half); //bottom right
    glVertex2d(centerX + rect_line_length_half, centerY + rect_line_length_half); //top right
    glVertex2d(centerX - rect_line_length_half, centerY + rect_line_length_half); //top left
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2d(centerX - rect_line_length_half - triLineLength, centerY + rect_line_length_half); //top left
    glVertex2d(centerX + rect_line_length_half + triLineLength, centerY + rect_line_length_half); //top right
    glVertex2d(((centerX - rect_line_length_half - triLineLength) + (centerX + rect_line_length_half + triLineLength)) / 2, centerY + rect_line_length_half + triLineLength * 5); // top middle

    glEnd();
}

void render() {
   
    glColor3f(0.0, 0.0, 0.0);		//set color to black

    rect_line_length_half = 0.5;
    triLineLength = 0.1;
    
    double house_centerX = 0;
    double house_centerY = 0;

    double translateX = -4;
	std::cout << translateX << std::endl;
    double translateY = 0;
    GLdouble theta = 45.0;
    
    double sinTheta = 0;
    
    for (int i = 0; i < houseCount; i++)
    {
        translateY = sin(sinTheta);
        
        glPushMatrix();
        glTranslatef(translateX, translateY, 0.0);
        glRotatef(theta, 0.0, 0.0, 1.0);
        drawHouse(house_centerX, house_centerY);
        glPopMatrix();
		
        theta = theta - 22.5;
        translateX = translateX + 2;
        sinTheta = sinTheta + degreeToRadian(45);
		
    }
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    render();
    glFlush();

    glutSwapBuffers();

}
void reshape(int w, int h) {

    //glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);

    glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //set display mode to double buffer
    
    
    glutInitWindowSize(width, height); //set display-window width and height
    glutInitWindowPosition(10, 10); //set top-left display-window position
    
    glutCreateWindow("Program 1"); //create display window
    
    glutDisplayFunc(display); //call drawHouse function
    glutReshapeFunc(reshape); 

    initialize();
    
    glutMainLoop(); //display everything and wait
}
