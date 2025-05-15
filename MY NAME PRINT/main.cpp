// Full Code to Draw "LIMON" Using Cubes with Transformations
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float Txval = 0.0, Tyval = 0.0, Rval = 0.0, Sval = 0.0;
int fla = -1, rol = -1, Ry = 0, Rz = 0, Rx = 0, scal = -1;

void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1,
                 GLfloat x2, GLfloat y2, GLfloat z2,
                 GLfloat x3, GLfloat y3, GLfloat z3) {
    GLfloat Ux = x2 - x1, Uy = y2 - y1, Uz = z2 - z1;
    GLfloat Vx = x3 - x1, Vy = y3 - y1, Vz = z3 - z1;
    GLfloat Nx = Uy * Vz - Uz * Vy;
    GLfloat Ny = Uz * Vx - Ux * Vz;
    GLfloat Nz = Ux * Vy - Uy * Vx;
    glNormal3f(Nx, Ny, Nz);
}

void drawcube() {
    static GLfloat v[8][3] = {
        {0,0,0},{1,0,0},{1,1,0},{0,1,0},
        {0,0,-1},{1,0,-1},{1,1,-1},{0,1,-1}
    };
    static GLubyte quads[6][4] = {
        {0,1,2,3},{4,5,6,7},{3,2,6,7},
        {0,1,5,4},{0,3,7,4},{1,5,6,2}
    };
    static GLfloat colors[6][3] = {
        {0.0, 0.7, 1.0},{1.0, 0.2, 0.2},{0.2, 1.0, 0.2},
        {1.0, 1.0, 0.0},{1.0, 0.0, 1.0},{0.0, 1.0, 1.0}
    };

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++) {
        glColor3fv(colors[i]);
        getNormal3p(v[quads[i][0]][0], v[quads[i][0]][1], v[quads[i][0]][2],
                    v[quads[i][1]][0], v[quads[i][1]][1], v[quads[i][1]][2],
                    v[quads[i][2]][0], v[quads[i][2]][1], v[quads[i][2]][2]);
        for (int j = 0; j < 4; j++)
            glVertex3fv(v[quads[i][j]]);
    }
    glEnd();
}

void drawLimonLetter(float xOffset, char letter) {
    glPushMatrix();
    glTranslatef(xOffset, 0, 0);
    switch(letter) {
        case 'L':
            for (int i = 0; i < 5; i++) {
                glPushMatrix();
                glTranslatef(0, i, 0);
                glScalef(1, 1, 1);
                drawcube();
                glPopMatrix();
            }
            for (int i = 1; i <= 2; i++) {
                glPushMatrix();
                glTranslatef(i, 0, 0);
                drawcube();
                glPopMatrix();
            }
            break;
        case 'I':
            for (int i = 0; i < 5; i++) {
                glPushMatrix();
                glTranslatef(0, i, 0);
                drawcube();
                glPopMatrix();
            }
            break;
        case 'M':
            for (int i = 0; i < 5; i++) {
                glPushMatrix(); glTranslatef(0, i, 0); drawcube(); glPopMatrix();
                glPushMatrix(); glTranslatef(4, i, 0); drawcube(); glPopMatrix();
            }
            glPushMatrix(); glTranslatef(1, 3, 0); drawcube(); glPopMatrix();
            glPushMatrix(); glTranslatef(2, 2, 0); drawcube(); glPopMatrix();
            glPushMatrix(); glTranslatef(3, 3, 0); drawcube(); glPopMatrix();
            break;
        case 'O':
            for (int i = 0; i < 4; i++) {
                glPushMatrix(); glTranslatef(0, i, 0); drawcube(); glPopMatrix();
                glPushMatrix(); glTranslatef(3, i, 0); drawcube(); glPopMatrix();
            }
            for (int i = 1; i < 3; i++) {
                glPushMatrix(); glTranslatef(i, 0, 0); drawcube(); glPopMatrix();
                glPushMatrix(); glTranslatef(i, 3, 0); drawcube(); glPopMatrix();
            }
            break;
        case 'N':
            for (int i = 0; i < 5; i++) {
                glPushMatrix(); glTranslatef(0, i, 0); drawcube(); glPopMatrix();
                glPushMatrix(); glTranslatef(4, i, 0); drawcube(); glPopMatrix();
                glPushMatrix(); glTranslatef(i, i, 0); drawcube(); glPopMatrix();
            }
            break;
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20, 20, 40, 0, 0, 0, 0, 1, 0);


    float spacing = 8.0;
    drawLimonLetter(-spacing * 2, 'L');
    drawLimonLetter(-spacing, 'I');
    drawLimonLetter(0, 'M');
    drawLimonLetter(spacing, 'O');
    drawLimonLetter(spacing * 2, 'N');

    glFlush();
    glutSwapBuffers();
}

void animate() {
    if (fla == 0) Txval += 0.02;
    if (fla == 1) Txval -= 0.02;
    if (fla == 2) Tyval += 0.02;
    if (fla == 3) Tyval -= 0.02;
    if (fla == -1) Txval = Tyval = 0.0;
    if (rol == -1) { Rval = 0.0; Rx = Ry = Rz = 0; }
    if (rol == 1) { Rval += 0.2; Rx = 1; Ry = Rz = 0; }
    if (rol == 2) { Rval += 0.2; Ry = 1; Rx = Rz = 0; }
    if (rol == 3) { Rval += 0.2; Rz = 1; Rx = Ry = 0; }
    if (scal == -1) Sval = 0.0;
    if (scal == 1) Sval += 0.002;
    if (scal == 2) Sval -= 0.002;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': fla = 1; break;
        case 'b': fla = 0; break;
        case 'c': fla = -1; break;
        case 'd': fla = 2; break;
        case 'e': fla = 3; break;
        case 'f': rol = -1; break;
        case 'g': rol = 1; break;
        case 'h': rol = 2; break;
        case 'i': rol = 3; break;
        case 'j': scal = -1; break;
        case 'k': scal = 1; break;
        case 'l': scal = 2; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("LIMON in Cubes");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
