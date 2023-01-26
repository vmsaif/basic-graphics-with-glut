//#include <iostream>
//#include "glut.h"
//
//double height = 500.0;
//double width = 500.0;
//double rect_line_length_half = 100.0 / 2 ;
//double triLineLength = 10.0;
//
//void initialize() {
//    glClearColor(1.0, 1.0, 1.0, 0.0); //set display-window color-white
//    glMatrixMode(GL_PROJECTION);		//set projection parameters
//    gluOrtho2D(0.0, width, 0.0, height);
//}
//
//void drawHouse(double centerX, double centerY, double translateX, double translateY, GLdouble theta) {
//
//    centerX = centerX + translateX;
//	centerY = centerX + translateY;
//    
//    // Save the current state of matrix so we can reset the rotation later
//    glPushMatrix();
//
//    ////rotation will be centered on the house
//    //glTranslated(centerX, centerY, 0); 
//
//    // Rotate the by the angle
//    glRotated(theta, 0, 0, 1); 
//
//    //// Translate the house back so that it is in the correct position
//    //glTranslated(-centerX, -centerY, 0); 
//
//    //draw house
//    glBegin(GL_POLYGON);			
//    glVertex2i(centerX - rect_line_length_half, centerY - rect_line_length_half); //bottom Left
//    glVertex2i(centerX + rect_line_length_half, centerY - rect_line_length_half); //bottom right
//    glVertex2i(centerX + rect_line_length_half, centerY + rect_line_length_half); //top right
//    glVertex2i(centerX - rect_line_length_half, centerY + rect_line_length_half); //top left
//    glEnd();
//
//    glBegin(GL_TRIANGLES);
//    glVertex2d(centerX - rect_line_length_half - triLineLength, centerY + rect_line_length_half); //top left
//    glVertex2d(centerX + rect_line_length_half + triLineLength, centerY + rect_line_length_half); //top right
//    glVertex2d(((centerX - rect_line_length_half - triLineLength) + (centerX + rect_line_length_half + triLineLength)) / 2, centerY + rect_line_length_half + triLineLength * 5); // top middle
//
//    glVertex2d(200, 150);
//
//    glEnd();
//
//	glPopMatrix(); //reset the angle back to 0
//    
//
//}
//
//void render() {
//    glClear(GL_COLOR_BUFFER_BIT);	//clear display window
//    
//    glColor3f(0.0, 0.0, 0.0);		//set line color to black
//    
//	double house_centerX = width / 2;
//	double house_centerY = height / 2;
//    
//    double house_1_translateX = 30;
//    double house_1_translateY = 0;
//    
//    double house_2_translateX = 30;
//    double house_2_translateY = -200;
//    
//    drawHouse(house_centerX, house_centerY, house_1_translateX, house_1_translateY, 25);
//    drawHouse(house_centerX, house_centerY, house_2_translateX, house_2_translateY, 25);
//
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //set display mode to double buffer
//    //glutInitWindowPosition(0, 0); //set top-left display-window position
//    glutInitWindowSize(500, 500); //set display-window width and height
//    glutCreateWindow("Program 1"); //create display window
//    initialize();
//    glutDisplayFunc(render); //call drawHouse function
//    glutMainLoop(); //display everything and wait
//}
