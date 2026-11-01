#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


void rectangle(float x1, float y1, float x2, float y2,
               float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}


void polygon(float points[][2], int n,
             float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2f(points[i][0], points[i][1]);
    glEnd();
}

void line(float x1, float y1, float x2, float y2,
          float r, float g, float b, float width)
{
    glColor3f(r, g, b);
    glLineWidth(width);

    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}


void circle(float cx, float cy, float radius,
            float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1415926f * i / 100;

            glVertex2f(cx + radius * cos(angle),
                       cy + radius * sin(angle));
        }
    glEnd();
}

void window(float x, float y)
{

    rectangle(x, y, x + 35, y + 30,
              0.0f, 0.0f, 0.0f);


    rectangle(x + 3, y + 3, x + 32, y + 27,
              1.0f, 0.75f, 0.75f);


    line(x + 17.5f, y + 3, x + 17.5f, y + 27,
         0.0f, 0.0f, 0.0f, 2);


    line(x + 3, y + 15, x + 32, y + 15,
         0.0f, 0.0f, 0.0f, 2);
}


void door()
{

    rectangle(310, 200, 365, 265,
              0.20f, 0.08f, 0.03f);


    rectangle(312, 200, 337, 263,
              0.42f, 0.20f, 0.08f);


    rectangle(338, 200, 363, 263,
              0.48f, 0.24f, 0.10f);

    rectangle(315, 244, 334, 257,
              0.30f, 0.12f, 0.04f);

    rectangle(341, 244, 360, 257,
              0.30f, 0.12f, 0.04f);

8    rectangle(315, 207, 334, 220,
              0.30f, 0.12f, 0.04f);

    rectangle(341, 207, 360, 220,
              0.30f, 0.12f, 0.04f);


    line(315, 244, 334, 244, 0.75f, 0.48f, 0.20f, 2);
    line(315, 257, 334, 257, 0.75f, 0.48f, 0.20f, 2);
    line(341, 244, 360, 244, 0.75f, 0.48f, 0.20f, 2);
    line(341, 257, 360, 257, 0.75f, 0.48f, 0.20f, 2);

    line(315, 207, 334, 207, 0.75f, 0.48f, 0.20f, 2);
    line(315, 220, 334, 220, 0.75f, 0.48f, 0.20f, 2);
    line(341, 207, 360, 207, 0.75f, 0.48f, 0.20f, 2);
    line(341, 220, 360, 220, 0.75f, 0.48f, 0.20f, 2);


    line(319, 250, 325, 255, 0.90f, 0.65f, 0.30f, 2);
    line(325, 255, 331, 250, 0.90f, 0.65f, 0.30f, 2);

    line(345, 250, 351, 255, 0.90f, 0.65f, 0.30f, 2);
    line(351, 255, 357, 250, 0.90f, 0.65f, 0.30f, 2);


    line(319, 210, 325, 216, 0.90f, 0.65f, 0.30f, 2);
    line(325, 216, 331, 210, 0.90f, 0.65f, 0.30f, 2);

    line(345, 210, 351, 216, 0.90f, 0.65f, 0.30f, 2);
    line(351, 216, 357, 210, 0.90f, 0.65f, 0.30f, 2);


    rectangle(333, 226, 335, 239,
              0.75f, 0.65f, 0.30f);

    rectangle(338, 226, 340, 239,
              0.75f, 0.65f, 0.30f);

    circle(334, 239, 2, 0.95f, 0.80f, 0.35f);
    circle(339, 239, 2, 0.95f, 0.80f, 0.35f);

    line(337.5f, 200, 337.5f, 263,
         0.15f, 0.05f, 0.02f, 2);
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    rectangle(0, 0, 640, 480,
              0.48f, 0.75f, 0.92f);


    circle(90, 400, 23,
           1.0f, 0.85f, 0.0f);


    for (int i = 0; i < 360; i += 45)
    {
        float angle = i * 3.1415926f / 180.0f;

        float x1 = 90 + 27 * cos(angle);
        float y1 = 400 + 27 * sin(angle);

        float x2 = 90 + 39 * cos(angle);
        float y2 = 400 + 39 * sin(angle);

        line(x1, y1, x2, y2,
             1.0f, 0.85f, 0.0f, 2);
    }

    rectangle(0, 100, 640, 200,
              0.0f, 0.35f, 0.0f);

    line(0, 200, 640, 200, 0, 0, 0, 2);

    float side[][2] = {
        {190, 200},
        {245, 200},
        {245, 300},
        {190, 300}
    };

    polygon(side, 4, 1.0f, 0.60f, 0.0f);


    rectangle(245, 200, 435, 300,
              1.0f, 0.60f, 0.0f);


    float roof[][2] = {
        {190, 300},
        {215, 340},
        {410, 340},
        {435, 300}
    };

    polygon(roof, 4, 0.72f, 0.22f, 0.12f);


    line(190, 200, 190, 300, 0, 0, 0, 3);
    line(190, 300, 215, 340, 0, 0, 0, 3);
    line(215, 340, 410, 340, 0, 0, 0, 3);
    line(410, 340, 435, 300, 0, 0, 0, 3);

    line(190, 300, 245, 300, 0, 0, 0, 3);
    line(245, 200, 245, 300, 0, 0, 0, 3);
    line(215, 340, 245, 300, 0, 0, 0, 3);

    line(435, 300, 435, 200, 0, 0, 0, 3);
    line(245, 200, 435, 200, 0, 0, 0, 3);


    window(270, 250);
    window(375, 250);

    door();

    glutSwapBuffers();
}

// Initialization
void init()
{
    glClearColor(0.48f, 0.75f, 0.92f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 640, 0, 480);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 27 || key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("2D House with Windows and Wooden Double Door");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
