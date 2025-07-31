#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display()
{
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.f);
    //
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.f);
    //
    glEnd();
    // dot
    glPointSize(5.0);
    glBegin(GL_POINTS);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.0f);
    //
    glEnd();

    glPushMatrix(); // Save the current transformation matrix
    glScalef(2, 2, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(-.5f, 0.5f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.2f, 0.5f);
    glEnd();
    glPopMatrix();

    // glPushMatrix(); // Save the current transformation matrix
    //  original polygon
    glTranslatef(-0.3, +0.4, 0.0f); // Translate the polygon by (tx, ty)
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.95f, -0.5f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.5f);
    glEnd();

    glTranslatef(-0.2, -0.3, 0.0f); // Translate the polygon by (tx, ty)
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.95f, -0.5f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.5f);
    glEnd();

    glTranslatef(+0.2, -0.3, 0.4f); // Translate the polygon by (tx, ty)
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.95f, -0.5f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.5f);
    glEnd();

    glTranslatef(+0.2, +0.3, 0.4f); // Translate the polygon by (tx, ty)
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.95f, -0.5f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.5f);
    glEnd();
    // glPopMatrix(); // Restore the previous transformation matrix
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("GLUT Shapes");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);

    // glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
