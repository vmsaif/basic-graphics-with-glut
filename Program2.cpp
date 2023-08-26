/*
Author: Saif Mahmud
Student ID: 3433058
Date : 1 / 25 / 2023
Course: COMP 390
TME = 1
Program : 2
Description: This program draws a house with a triangle roof 5 times with translating and rotating.
*/

#include <iostream>
#include "glut.h"
#include <cmath>

namespace Program2 {

    static const double PI = atan(1) * 4;
    static const int houseCount = 5;

    //set width and height of the display
    static double height = 500;
    static double width = 500;

    static double rect_line_length_half;
    static double triLineLength;

    static double degreeToRadian(double degree) {
        return (degree * PI) / 180;
    }
    static void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0); //set display-window color-white
    }

    static void drawHouse(double centerX, double centerY) {

        //draw house
        glBegin(GL_LINE_LOOP);
        glVertex2d(centerX - rect_line_length_half, centerY - rect_line_length_half); //bottom Left
        glVertex2d(centerX + rect_line_length_half, centerY - rect_line_length_half); //bottom right
        glVertex2d(centerX + rect_line_length_half, centerY + rect_line_length_half); //top right
        glVertex2d(centerX - rect_line_length_half, centerY + rect_line_length_half); //top left
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(centerX - rect_line_length_half - triLineLength, centerY + rect_line_length_half); //top left
        glVertex2d(centerX + rect_line_length_half + triLineLength, centerY + rect_line_length_half); //top right
        glVertex2d(((centerX - rect_line_length_half - triLineLength) + (centerX + rect_line_length_half + triLineLength)) / 2, centerY + rect_line_length_half + triLineLength * 5); // top middle

        glEnd();
    }

    static void render() {

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


    static void display() {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        render();
        glFlush();

        glutSwapBuffers();

    }
    static void reshape(int w, int h) {

        glViewport(0, 0, (GLsizei)w, (GLsizei)h); //area of the window where the renderer will be drawn
        glMatrixMode(GL_PROJECTION); //any matrix operations that follow will affect the projection matrix.
        glLoadIdentity(); //initialize the projection matrix
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0); //map the 3D scene onto the 2D viewport
        glMatrixMode(GL_MODELVIEW); //any matrix operations that follow will affect the modelview matrix.

    }

    static int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //set display mode to double buffer


        glutInitWindowSize(width, height); //set display-window width and height
        glutInitWindowPosition(10, 10); //set top-left display-window position

        glutCreateWindow("Program 2"); //create display window

        glutDisplayFunc(display); //call drawHouse function
        glutReshapeFunc(reshape);

        initialize();

        glutMainLoop(); //display everything and wait
        return EXIT_SUCCESS;
    }
}