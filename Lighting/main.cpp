#include <GL/glut.h>

// Light ON
void light1a2() {
    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {2.0, 25.0, 3.0, 1.0};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// Light OFF
void off() {
    glDisable(GL_LIGHT0);
}

// Keyboard function to toggle light
void myKeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 't':  // Turn on light
            light1a2();
            glutPostRedisplay();
            break;
        case 'T':  // Turn off light
            off();
            glutPostRedisplay();
            break;
        case 27:   // ESC key to exit
            exit(0);
    }
}

// Display function (empty for now)
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    glutSwapBuffers();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Light On/Off");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
