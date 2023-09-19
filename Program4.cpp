
/*
	Author: Saif Mahmud
	Date : 3 / 22 / 2023

	Program: 4
	Description: This program draws eight houses with a triangle roofs and a floors using translation, scaling, and rotation to transform 
				 the houses. The houses are drawn using shapes. 
*/

#include <iostream>
#include <GL/glut.h>

namespace Program4 {
	using namespace std;

	typedef GLdouble vertex3[3];

	// defining the vertices of the cube
	static vertex3 wall_pt[8] = {
		{0,0,0}, //0
		{0,1,0}, //1
		{1,0,0}, //2
		{1,1,0}, //3
		{0,0,1}, //4
		{0,1,1}, //5
		{1,0,1}, //6
		{1,1,1}  //7
	};

	// defining the vertices of the floor
	static vertex3 floor_pt[4] = {
		{-0.75, 0, -0.75}, //back left
		{-0.75, 0, 1.75}, //front left
		{1.75, 0, 1.75}, // front right
		{1.75, 0, -0.75} // back right
	};

	// defining the vertices of the top floor which will be used to draw the roof triangles
	static vertex3 top_floor_pt[4] = {
		{-0.2, 1.0, -0.2}, //back left
		{-0.2, 1.0, 1.2}, //front left
		{1.2, 1.0, 1.2}, // front right
		{1.2, 1.0, -0.2} // back right
	};

	/**
	Description: top_hat This function is responsible for drawing the triangular
	roof of the house. It draws four triangles and each triangle has a point where
	all the triangles meet. This point is the top point of the roof.
	*/
	static void top_hat() {
		GLdouble hatTopPoint[3] = { 0.5, 1.5, 0.5 }; // the point where all the triangle's tops will meet

		glColor3f(0.0, 0.0, 1.0); // blue color
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_TRIANGLES);

		// triangle 1
		glVertex3dv(top_floor_pt[0]);
		glVertex3dv(top_floor_pt[1]);
		glVertex3dv(hatTopPoint);

		// triangle 2
		glVertex3dv(top_floor_pt[1]);
		glVertex3dv(top_floor_pt[2]);
		glVertex3dv(hatTopPoint);

		// triangle 3
		glVertex3dv(top_floor_pt[2]);
		glVertex3dv(top_floor_pt[3]);
		glVertex3dv(hatTopPoint);

		// triangle 4
		glVertex3dv(top_floor_pt[3]);
		glVertex3dv(top_floor_pt[0]);
		glVertex3dv(hatTopPoint);

		glEnd();

	}


	/**
	Description: This function takes four vertices as input
	and draws a wall using these vertices.
	It is called by the allWalls() function to draw all the walls of the house.
	*/
	static void wall(GLint n1, GLint n2, GLint n3, GLint n4) {

		glBegin(GL_QUADS);
		glVertex3dv(wall_pt[n1]);
		glVertex3dv(wall_pt[n2]);
		glVertex3dv(wall_pt[n3]);
		glVertex3dv(wall_pt[n4]);
		glEnd();

	}

	/**
	Description:This function is responsible for drawing the floor
	of the house. It takes four vertices as input and uses them
	to draw a floor.
	*/
	static void floor() {
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		glVertex3dv(floor_pt[0]);
		glVertex3dv(floor_pt[1]);
		glVertex3dv(floor_pt[2]);
		glVertex3dv(floor_pt[3]);
		glEnd();
	}

	/**
	Description:This function calls the wall() function with the
	appropriate vertices to draw all the walls of the house.
	*/
	static void allWalls() {
		glColor3f(1.0, 0.0, 0.0);
		wall(6, 2, 3, 7); //rightSideWall
		wall(5, 1, 0, 4); //leftSideWall
		wall(7, 3, 1, 5); //topWall
		wall(4, 0, 2, 6); //bottomWall
		wall(2, 0, 1, 3); //backWall
		wall(7, 5, 4, 6); //frontWall
	}

	/**
	Description:This function draws the ground on which the houses are built.
	It uses the GL_QUADS primitive to draw a surface and fills it with a light gray color.
	*/
	static void drawTownLand() {
		// draw the town land
		glColor3f(0.65, 0.65, 0.65); // light gray
		glBegin(GL_QUADS);
		glVertex3d(-8.0, -0.1, -8.0); // frontLeft
		glVertex3d(-8.0, -0.1, 8.0); // backLeft
		glVertex3d(8.0, -0.1, 8.0); // backRight
		glVertex3d(8.0, -0.1, -8.0); // frontRight
		glEnd();
	}

	/**
	Description: This function calls all the functions responsible
	for drawing the individual parts of 1 house. It includs the
	floor, walls, and roof.
	*/
	static void drawHouse() {

		// draw all the parts of the house
		floor();
		allWalls();
		top_hat();
	}


	/**
	Description:This function is responsible for drawing the entire town.
	It calls the drawTownLand() function to draw the ground and uses
	glPushMatrix() and glPopMatrix() to transform and draw eight instances
	of the drawHouse() function with different positions, rotations, and scales.
	*/
	static void drawTown() {

		// draw the ground
		drawTownLand();

		// draw the first house
		glPushMatrix();
		glTranslated(3.0, 0.0, -4.0);
		drawHouse();
		glPopMatrix();

		// draw the second house using translation
		glPushMatrix();
		glTranslated(0.0, 0.0, -4.0);
		drawHouse();
		glPopMatrix();

		// draw the third house using translation and then scaling
		drawHouse();

		// draw the fourth house using translation and then rotation
		glPushMatrix();
		glTranslated(-3.0, 0.0, 0.0);
		glScaled(0.5, 0.9, 0.9);
		drawHouse();
		glPopMatrix();

		// draw the fifth house using translation, rotation and then scaling
		glPushMatrix();
		glTranslated(3.0, 0.0, 0.0);
		drawHouse();
		glPopMatrix();

		// draw the sixth house using translation, rotation and then scaling
		glPushMatrix();
		glTranslated(3.0, 0.0, 4.0);

		// rotate the house 45 degrees around the y axis
		glRotated(45, 0.0, 1.0, 0.0);
		drawHouse();
		glPopMatrix();


		// draw the seventh house using translation, rotation and then scaling
		glPushMatrix();
		glTranslated(0.0, 0.0, 4.0);

		// rotate the house 45 degrees around the Y axis
		glRotated(45, 0.0, 1.0, 0.0);
		glScaled(0.5, 0.9, 0.9);
		drawHouse();
		glPopMatrix();

		// draw the eighth house
		glPushMatrix();
		glTranslated(-3.0, 0.0, 4.0);

		// rotate the house 45 degrees and scaled around the y, x axis
		glRotated(45, 0.0, 1.0, 0.0);
		glScaled(0.5, 2.0, 0.9);
		drawHouse();
		glPopMatrix();
	}


	// called every time the window is redrawn
	static void render() {
		//set backbround Color
		glColor3f(0.0, 0.0, 0.0);
		drawTown();
	}

	// display registry 
	static void display(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
		glLoadIdentity(); // reset the modelview matrix
		// viewing
		gluLookAt(2.0, 5.5, 13.0, 0.0, 0.0, 3.0, 0.0, 1.0, 0.0); // set the camera position and orientation
		render(); // render the scene
		glutSwapBuffers(); //Swap the front and back buffers

	}



	// reshape registry
	// called when window is resized to change the viewport
	static void reshape(int w, int h) {

		glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the client window area
		glMatrixMode(GL_PROJECTION); // set the projection matrix mode
		glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0); // set the projection frustum
		glMatrixMode(GL_MODELVIEW); // set the modelview matrix mode

	}

	static void initialize() {
		// set background color white
		glClearColor(1.0, 1.0, 1.0, 0.0);
	}

	// main program 
	static int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //set display mode to double buffer
		glutInitWindowPosition(100, 100); //set top-left display-window position
		glutInitWindowSize(500, 500); //set display-window width and height
		glutCreateWindow("Program 1"); //create display window

		glutDisplayFunc(display); //call display function
		glutReshapeFunc(reshape); // call reshape function
		initialize(); // initialize OpenGL

		glutMainLoop(); //display everything and wait

		return EXIT_SUCCESS;
	}
}
