/*
Author: Saif Mahmud
Date : 1 / 25 / 2023
Description: This program draws a rectangle with four vertices set to red, green, blue, and yellow, color respectively.
*/

#include <iostream>
#include "glut.h"

namespace Program3 {

    //set width and height of the display
    static double height = 500;
    static double width = 500;


    static void initialize() {
        glClearColor(1.0, 1.0, 1.0, 0.0); //set display-window color-white
        glEnable(GL_BLEND); //enable blending
    }



    static void render() {

        glColor3f(0.0, 0.0, 0.0); //set color to black

        // set the color array
        GLfloat red[] = { 1,0,0 };
        GLfloat green[] = { 0,1,0 };
        GLfloat blue[] = { 0,0,1 };
        GLfloat yellow[] = { 1,1,0 };

        GLfloat* colorArray[4] = { red, green, blue, yellow };

        // set the points array
        double lineSize = 2.5;
        GLdouble points[4][2] = {
            { -lineSize, -lineSize },
            { -lineSize, lineSize },
            { lineSize, lineSize },
            { lineSize, -lineSize }
        };

        // draw the rectangle and set the color
        glBegin(GL_QUADS);
        for (int i = 0; i < (sizeof(points) / sizeof(points[0])); i++)
        {
            glColor3fv(colorArray[i]);
            glVertex2dv(points[i]);
        }
        glEnd();
    }


    static void display() {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear display window
        glLoadIdentity();
        gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        render(); //draw the scene
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
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //set display mode to double buffer and RGB color 


        glutInitWindowSize(width, height); //set display-window width and height
        glutInitWindowPosition(10, 10); //set top-left display-window position

        glutCreateWindow("Program 2"); //create display window

        glutDisplayFunc(display);
        glutReshapeFunc(reshape);

        initialize();

        glutMainLoop(); //display everything and wait
        return EXIT_SUCCESS;
    }

}