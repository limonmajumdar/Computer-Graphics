#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

///triangle in 3d
static GLfloat v_pyramid[5][3] = {
    {0.0, 0.0, 0.0},  // point index 0 (base)
    {0.0, 0.0, 2.0},  // point index 1 (top)
    {2.0, 0.0, 2.0},  // point index 2 (base)
    {2.0, 0.0, 0.0},  // point index 3 (base)
    {1.0, 4.0, 1.0}   // point index 4 (top of the pyramid)
};

static GLubyte p_Indices[4][3] = {
    {4, 1, 2}, // indices for drawing the triangle plane 1
    {4, 2, 3}, // indices for drawing the triangle plane 2
    {4, 3, 0}, // indices for drawing the triangle plane 3
    {4, 0, 1}  // indices for drawing the triangle plane 4
};

static GLubyte quadIndices[1][4] = {
    {0, 3, 2, 1} // indices for drawing the quad base
};

static GLfloat colors[5][3] = {
    {0.0, 0.0, 1.0},  // color for point index 0
    {0.5, 0.0, 1.0},  // color for point index 1
    {0.0, 1.0, 0.0},  // color for point index 2
    {0.0, 1.0, 1.0},  // color for point index 3
    {0.8, 0.0, 0.0}   // color for point index 4
};
///        triangular plane 3 coordinates (x1,x2,x3), (y1,y2,y3), (z1,z2,z3)
static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3) {
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1;
    Uy = y2 - y1;
    Uz = z2 - z1;

    Vx = x3 - x1;
    Vy = y3 - y1;
    Vz = z3 - z1;

    Nx = Uy * Vz - Uz * Vy;
    Ny = Uz * Vx - Ux * Vz;
    Nz = Ux * Vy - Uy * Vx;

    glNormal3f(Nx, Ny, Nz);
}

void drawpyramid() {
    // Draw the four triangular faces of the pyramid
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i < 5; i++) {
        // Set the color for each face
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);

        // Calculate and apply the normal for this face
        getNormal3p(
             ///       index 4 (x),          index 4 (y),                      index 4 (z), //i=0
            v_pyramid[p_Indices[i][0]][0], v_pyramid[p_Indices[i][0]][1], v_pyramid[p_Indices[i][0]][2],
            ///       index 1 (x),          index 1 (y),                      index 1 (z), //i=0
            v_pyramid[p_Indices[i][1]][0], v_pyramid[p_Indices[i][1]][1], v_pyramid[p_Indices[i][1]][2],
            ///       index 2 (x),          index 2 (y),                      index 2 (y), //i=0
            v_pyramid[p_Indices[i][2]][0], v_pyramid[p_Indices[i][2]][1], v_pyramid[p_Indices[i][2]][2]
        );

        // Draw the triangle vertices
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    // Draw the base (quad) of the pyramid
    glBegin(GL_QUADS);
    glColor3f(colors[4][0], colors[4][1], colors[4][2]); // Set color for base
    for (GLint i = 0; i < 1; i++) {
        // Calculate and apply the normal for the base
        getNormal3p(

            v_pyramid[quadIndices[i][0]][0], v_pyramid[quadIndices[i][0]][1], v_pyramid[quadIndices[i][0]][2],
            v_pyramid[quadIndices[i][1]][0], v_pyramid[quadIndices[i][1]][1], v_pyramid[quadIndices[i][1]][2],
            v_pyramid[quadIndices[i][2]][0], v_pyramid[quadIndices[i][2]][1], v_pyramid[quadIndices[i][2]][2]
        );

        // Draw the quad vertices
        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10, 10, -10, 10, 5, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.7, 0.7, 10, 0.7, 0.7, 0.7, 0, 1, 0);


    glPushMatrix();
    glRotatef(-35,1,0,0);//glRotatef(-35,0,1,0);//glRotatef(-35,0,0,1);
    drawpyramid();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Pyramid");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
