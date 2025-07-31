/*
 * Drawing a House with a Rotating Windmill
 *
 * Objective:
 * To apply basic OpenGL concepts by drawing a 2D house model and attaching a rotating
 * windmill to it. This task will reinforce understanding of 2D shapes, transformations (translate,
 * rotate), viewing, and animation basics.
 *
 * Task Description:
 *
 * Write an OpenGL program to:
 * 1. Draw a house using:
 *    - A square or rectangle for the base.
 *    - A triangle for the roof.
 *    - Add a door or windows using smaller quads.
 * 2. Attach a windmill to the house consisting of:
 *    - Four blades created using triangles.
 *    - Make the windmill blades rotate continuously to simulate wind motion.
 *
 * Set up a proper 2D perspective view so the output looks realistic. Add color to different
 * components (e.g., brown for house, gray for windmill pole, red/blue/green/yellow for blades).
 */

#include <GL/glut.h>

float angle = 0.0f;

/**
 * Draws a 2D representation of a house using OpenGL primitives.
 * The house consists of:
 * - A brown rectangular base.
 * - A brown triangular roof.
 * - A dark grey rectangular door.
 * - A dark grey rectangular window.
 * Colors and coordinates are specified to create these shapes.
 */
void drawHouse()
{
    // House base
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(150.0f, 150.0f);
    glVertex2f(350.0f, 150.0f);
    glVertex2f(350.0f, 300.0f);
    glVertex2f(150.0f, 300.0f);
    glEnd();

    // Roof
    glColor3f(0.6f, 0.4f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(150.0f, 300.0f);
    glVertex2f(350.0f, 300.0f);
    glVertex2f(250.0f, 400.0f);
    glEnd();

    // Door
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(230.0f, 150.0f);
    glVertex2f(270.0f, 150.0f);
    glVertex2f(270.0f, 230.0f);
    glVertex2f(230.0f, 230.0f);
    glEnd();

    // Window
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(200.0f, 180.0f);
    glVertex2f(180.0f, 180.0f);
    glVertex2f(180.0f, 210.0f);
    glVertex2f(200.0f, 210.0f);
    glEnd();
}

/**
 * Draws a windmill with a rotating blades.
 * The windmill consists of a gray pole and four colored blades (red, green, blue, and yellow).
 * The blades are positioned at the center of the windmill and are rotated using the angle parameter.
 * The angle parameter is updated in the idle callback to simulate wind motion.
 */
void drawWindmill()
{
    // Pole
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(400.0f, 150.0f);
    glVertex2f(410.0f, 150.0f);
    glVertex2f(410.0f, 350.0f);
    glVertex2f(400.0f, 350.0f);
    glEnd();

    // Blades
    glPushMatrix();
    glTranslatef(405.0f, 350.0f, 0.0f); // center of rotation
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate blades

    // Blade 1 – red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 40.0f);
    glVertex2f(10.0f, 20.0f);
    glEnd();

    // Blade 2 – green
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -40.0f);
    glVertex2f(10.0f, -20.0f);
    glEnd();

    // Blade 3 – blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(40.0f, 0.0f);
    glVertex2f(20.0f, 10.0f);
    glEnd();

    // Blade 4 – yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-40.0f, 0.0f);
    glVertex2f(-20.0f, 10.0f);
    glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouse();
    drawWindmill();
    glFlush();
}

void update(int value)
{
    angle += 5.0f;
    if (angle > 360.0f)
        angle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // roughly 60 FPS
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0f, 600.0f, 0.0f, 500.0f); // 2D projection
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("House with Rotating Windmill");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}