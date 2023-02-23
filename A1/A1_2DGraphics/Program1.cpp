/*
Author: Saif Mahmud
Student ID: 3433058
Date : 1 / 25 / 2023
Course: COMP 390
TME = 1
Program : 1
Description: This program draws 2 houses with a triangle roof 2 times with rotating and 1 house using anti aliasing technique.
*/

#include <iostream>
#include "glut.h"

namespace Program1 {
    

    static double height = 500.0;
    static double width = 500.0;
    static double rect_line_length_half = 100.0 / 2;
    static double triLineLength = 10.0;

    static void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0);   //set display-window color-white
        glMatrixMode(GL_PROJECTION);		//set projection parameters
        gluOrtho2D(0.0, width, 0.0, height);
    }

    static void drawHouse(double centerX, double centerY, double translateX, double translateY, GLdouble theta) {

        centerX = centerX + translateX;
        centerY = centerY + translateY;

        // Save the current state of matrix so we can reset the rotation later
        glPushMatrix();

        // Rotate the by the angle
        glRotated(theta, 0, 0, 1);

        //draw house
        glBegin(GL_LINE_LOOP);
        glVertex2i(centerX - rect_line_length_half, centerY - rect_line_length_half); //bottom Left
        glVertex2i(centerX + rect_line_length_half, centerY - rect_line_length_half); //bottom right
        glVertex2i(centerX + rect_line_length_half, centerY + rect_line_length_half); //top right
        glVertex2i(centerX - rect_line_length_half, centerY + rect_line_length_half); //top left
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(centerX - rect_line_length_half - triLineLength, centerY + rect_line_length_half); //top left
        glVertex2d(centerX + rect_line_length_half + triLineLength, centerY + rect_line_length_half); //top right
        glVertex2d(((centerX - rect_line_length_half - triLineLength) + (centerX + rect_line_length_half + triLineLength)) / 2, centerY + rect_line_length_half + triLineLength * 5); // top middle
        glEnd();

        glPopMatrix(); //reset the angle back to 0


    }

    static void render() {
        glClear(GL_COLOR_BUFFER_BIT);	//clear display window

        glColor3f(0.0, 0.0, 0.0);		//set line color to black

        double house_centerX = width / 2;
        double house_centerY = height / 2;

        double house_1_translateX = 30;
        double house_1_translateY = 0;

        double house_2_translateX = 30;
        double house_2_translateY = -200;


        drawHouse(house_centerX, house_centerY, house_1_translateX, house_1_translateY, 25);


        glEnable(GL_LINE_SMOOTH);  //enable line anti-aliasing
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);  //set the quality of anti-aliasing
        glLineWidth(0.5);
        drawHouse(house_centerX, house_centerY, house_2_translateX, house_2_translateY, 25);

        glutSwapBuffers();
    }


    static int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //set display mode to double buffer
        //glutInitWindowPosition(0, 0); //set top-left display-window position
        glutInitWindowSize(500, 500); //set display-window width and height
        glutCreateWindow("Program 1"); //create display window
        initialize();
        glutDisplayFunc(render); //call drawHouse function
    
	
        glutMainLoop(); //display everything and wait
        return EXIT_SUCCESS;
    }
}