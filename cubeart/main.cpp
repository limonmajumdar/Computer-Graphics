#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

///rectangle in 3d
static GLfloat v_pyramid[8][3] = {
    {0.0, 0.0, 0.0},//0
    {2.0, 0.0, 0.0},//1
    {2.0, 2.0, 0.0},//2
    {0.0, 2.0, 0.0},//3
    {0.0, 0.0, -2.0},//4
    {2.0, 0.0, -2.0},//5
    {2.0, 2.0, -2.0},//6
    {0.0, 2.0, -2.0}//7
};

static GLubyte p_Indices[4][3] = {
    {4, 1, 2}, // indices for drawing the triangle plane 1
    {4, 2, 3}, // indices for drawing the triangle plane 2
    {4, 3, 0}, // indices for drawing the triangle plane 3
    {4, 0, 1}  // indices for drawing the triangle plane 4
};

static GLubyte quadIndices[6][4] = {
    {0,1,2,3},//front
    {4,5,6,7},//back
    {3,2,6,7},//top
    {0,1,5,4},//bottom
    {0,3,7,4},//left
    {1,5,6,2},//right
};

static GLfloat colors[8][3] = {
    {0.0, 0.0, 1.0},  // color for point index 0
    {0.5, 0.0, 1.0},  // color for point index 1
    {0.0, 1.0, 0.0},  // color for point index 2
    {0.0, 1.0, 1.0},  // color for point index 3
    {0.8, 0.0, 0.0},   // color for point index 4

    {0.0, 1.0, 0.5},  // color for point index 2
    {0.5, 0.3, 0.0},  // color for point index 3
    {0.5, 0.4, 0.5}   // color for point index 4
};

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

void drawcube() {


    // Draw the base (quad) of the pyramid
    glBegin(GL_QUADS);

    for (GLint i = 0; i < 6; i++) {
            glColor3f(colors[i][0], colors[i][1], colors[i][2]); // Set color for base
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


float Txval=0.0,Tyval=0.0, Rval=0.0,Sval=0.0; int fla=-1, rol=-1,Ry=0,Rz=0, Rx=0, scal=-1;

void myKeyboardFunc( unsigned char key, int x, int y)
{
	switch ( key )
	{
		case 'a':
		    fla=1;
			glutPostRedisplay();
			break;
		case 'b':
			fla=0;
			glutPostRedisplay();
			break;
		case 'c':
			fla=-1;//Txval=0;Tyval=0; return to 1st position
			glutPostRedisplay();
			break;
		case 'd':
			fla=2;
			glutPostRedisplay();
			break;
		case 'e':
			fla=3;
			glutPostRedisplay();
			break;

        case 'f':
			rol=-1;
			glutPostRedisplay();
			break;
        case 'g':
			rol=1;
			glutPostRedisplay();
			break;
        case 'h':
			rol=2;
			glutPostRedisplay();
			break;
        case 'i':
			rol=3;
			glutPostRedisplay();
			break;
        case 'j':
			scal=-1;
			glutPostRedisplay();
			break;
        case 'k':
			scal=1;
			glutPostRedisplay();
			break;
        case 'l':
			scal=2;
			glutPostRedisplay();
			break;
		case 27:	// Escape key
			exit(1);
	}

}

void animate()
{
    /// for translation
	if (fla == 0)
	{
		Txval+=0.02;
		//fla=-1;
	}
	if(fla == 1)
    {Txval-=0.02;
       // fla=-1;
    }
	if (fla == 2)
	{
		Tyval+=0.02;
		//fla=-1;
	}
	if(fla == 3)
    {Tyval-=0.02;
       // fla=-1;
    }
    if(fla == -1)
    {
    Txval=0.0;Tyval=0.0;}

  /// for rotation
    if(rol == -1)
    {
    Rval=0.0;Rx=0; Ry=0;Rz=0;}
    if(rol == 1)
    {
    Rval+=0.02;Rx=1; Ry=0;Rz=0;}
    if(rol == 2)
    {
    Rval+=0.02;Rx=0; Ry=1;Rz=0;}
    if(rol == 3)
    {
    Rval+=0.02;Rx=0; Ry=0;Rz=1;}
    /// for scaling

    if(scal == -1)
    {
    Sval=0.0;}
    if(scal == 1)
    {
    Sval+=0.002;}
    if(scal == 2)
    {
    Sval-=0.002;}

	glutPostRedisplay();
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
   // glRotatef(-35,1,0,0);//glRotatef(-35,0,1,0);//glRotatef(-35,0,0,1);
    glScalef(5.0+Sval,0.1+Sval, 0.1+Sval);
    drawcube();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(10+Txval,4.0+Tyval,0.0);
    glPushMatrix();
    glRotatef(-1+Rval,Rx,Ry,Rz);//glRotatef(-35,0,1,0);//glRotatef(-35,0,0,1);
    //glTranslatef(-1.5,2.7,0.0);
    drawcube();
    glPopMatrix();
glPopMatrix();

 glPushMatrix();
 //glTranslatef(-10,4.0,0.0);
 drawcube();
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


    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutIdleFunc(animate);

    glutMainLoop();
    return 0;
}
