/*Required Header Files*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <math.h>
#define PI 3.1416

/*Required Variables*/
/*For Opengl i use GLfloat Data Type*/
GLfloat riverLinePos = 0.0f;

GLfloat shipPos = 0.0f;
GLfloat shipPos2 = 0.0f;

GLfloat boat = 0.0f;
GLfloat boat2 = 0.0f;

GLfloat pos = 0.0f;
GLfloat i = 0;

GLfloat cloudMov = 0.0f;
GLfloat cloudMov2 = 0.0f;

GLfloat planeMov = 0.0f;
GLfloat trainPos = 0.0f;
GLfloat angle = 0.0;

GLfloat cowMovX = 0.0f;
GLfloat cowMovY = 0.0f;

GLfloat chickenMovX = 0.0f;
GLfloat chickenMovY = 0.0f;

GLfloat humanMovX = 0.0f;
GLfloat humanMovY = 0.0f;

GLfloat rainMovX = 0.0f;
GLfloat rainMovY = 0.0f;

GLfloat car1pos = 0.0f;
GLfloat car2pos = 0.0f;
GLfloat car3MovX = 0.0f;
GLfloat car3MovY = 0.0f;

/*For Condition Type Variable*/
bool day = true;
bool night = false;
bool isRain = false;
bool isStop = false;
bool isSound = false;

void soundShip() {
    PlaySound("shipSound.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void soundCar() {
    PlaySound("car.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void soundTrain() {
    PlaySound("train.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void soundRain() {
    PlaySound("rain.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void soundNull() {
    PlaySound(NULL, 0, 0);
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'n':
        night = true;
        PlaySound("night.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        day = false;
        break;
    case 'N':
        night = true;
        day = false;
        break;
    case 'd':
        night = false;
        PlaySound(NULL, 0, 0);
        day = true;
        break;
    case 'D':
        night = false;
        day = true;
        break;
    case 'r':
        if (isRain) {
            if (!isSound) {
                soundNull();
            }
            else {
                soundShip();
                soundCar();
                soundTrain();
            }
            isRain = false;
        }
        else {
            isRain = true;
            soundRain();
        }
        break;
    case 'R':
        if (isRain) {
            if (!isSound) {
                soundNull();
            }
            else {
                soundShip();
                soundCar();
                soundTrain();
            }
            isRain = false;
        }
        else {
            isRain = true;
            soundRain();
        }
        break;
    case 's':
        isSound = true;
        if (!isRain) {
            soundShip();
        }
        break;
    case 'S':
        isSound = true;
        if (!isRain) {
            soundShip();
        }
        break;
    case 'c':
        isSound = true;
        if (!isRain) {
            soundCar();
        }
        break;
    case 'C':
        isSound = true;
        if (!isRain) {
            soundCar();
        }
        break;
    case 't':
        isSound = true;
        if (!isRain) {
            soundTrain();
        }
        break;
    case 'T':
        isSound = true;
        if (!isRain) {
            soundTrain();
        }
        break;
    case 'p':
        isSound = false;
        soundNull();
        break;
    case 'P':
        isSound = false;
        soundNull();
        break;
    case 'a':/*For Car Rotation*/
        angle += 2.0;
        if (angle > 200) {
            angle -= 180;
        }
    case 'A':
        angle += 2.0;
        if (angle > 200) {
            angle -= 180;
        }
        glutPostRedisplay();
    }
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        isStop = false;
    }
    if (button == GLUT_RIGHT_BUTTON) {
        isStop = true;
    }
    if (button == GLUT_MIDDLE_BUTTON) {
        exit(0);
    }
    glutPostRedisplay();
}

void SpecialInput(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        cowMovX -= .1;
        chickenMovX -= .2;
        humanMovX -= .3;
        car3MovX -= .2;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        cowMovX += .1;
        chickenMovX += .2;
        humanMovX += .3;
        car3MovX += .2;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        cowMovY += .1;
        chickenMovY += .2;
        humanMovY += .3;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        cowMovY -= .1;
        chickenMovY -= .2;
        humanMovY -= .3;
        glutPostRedisplay();
        break;
    }
    glutPostRedisplay();
}

void update(int value) {
    if (!isStop) {
        /*For Cloud*/
        cloudMov += 0.007f;
        if (cloudMov >= 1.9) {
            cloudMov = -1.6f;
        }
        cloudMov2 += 0.0007f;
        if (cloudMov2 >= 2.9) {
            cloudMov2 = -2.6;
        }

        /*For Plane*/
        planeMov += 0.007f;
        if (planeMov >= 2.1) {
            planeMov = -1.1f;
        }

        /*For Car*/
        if (car1pos <= 1.9f) {
            car1pos += 0.02f;
        }
        else {
            car1pos = -1.0f;
        }
        car2pos -= 0.02f;
        if (car2pos <= -1.9f) {
            car2pos = +1.0f;
        }

        /*For RiverLine*/
        if (riverLinePos <= 1.0f) {
            riverLinePos += 0.01f;
        }
        else {
            riverLinePos = 0.0f;
        }

        /*For Ship Movement*/
        if (shipPos > -1.8f) {
            shipPos -= 0.01;
        }
        else {
            shipPos = 1.5;
        }
        if (shipPos2 < 1.8f) {
            shipPos2 += 0.01;
        }
        else {
            shipPos2 = -1.0;
        }

        /*For Boat Movement*/
        if (boat <= 1.1f) {
            boat += .01f;
        }
        else {
            boat = -1.6f;
        }
        boat2 -= 0.015;
        if (boat2 <= -1.0) {
            boat2 = +1.9;
        }

        /*For Train*/
        if (trainPos <= 2.0f) {
            trainPos += 0.01;
        }
        else {
            trainPos = -1.9f;
        }

        /*For Rotating Fan*/
        i += 5;

        /*For Rain*/
        rainMovX -= 0.002f;
        rainMovY -= 0.009f;
        if (rainMovX < 1.0f) {
            rainMovX = 0.0f;
        }
        if (rainMovY < -1.0f) {
            rainMovY = 0.0f;
        }
    }
    glutPostRedisplay();
    /*Update() is Called After 50 Milliseconds*/
    glutTimerFunc(50, update, 0);
}

void riverSideRoadGrass() {
    glBegin(GL_QUADS);
    if (night) {
        glColor3f(0.3, 0.7, 0.3);
    }
    else {
        glColor3f(0.435, 0.839, 0.360);
    }
    glVertex2f(-1, -0.1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.1);
    glEnd();
}

void rain() {
    int i = 0;
    int j = 0;
    float x, y;
    x = 1.0f;
    y = 2.0f;
    while (j <= 100) {//Y-axis
        x = -1.0f;
        while (i <= 100) {//X-axis
            glBegin(GL_LINES);
            glColor3f(0.313, 0.560, 0.713);
            glVertex2f(x, y);
            glVertex2f(x - 0.02f, y - 0.07f);
            glEnd();
            x += 0.03f;
            i++;
        }
        y -= 0.05f;
        j++;
        i = 0;
    }
}

void circle(float a, float b, float c, float m, float n, float o) {
    int i;
    GLfloat x = a;
    GLfloat y = b;
    GLfloat radius = c;
    GLfloat theta5 = 2.0f * PI * i / 100;;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m, n, o);
    glVertex2f(x, y);
    for (i = 0; i <= 20; i++) {
        GLfloat theta5 = 2.0f * PI * i / 20;;
        glVertex2f(x + (radius * cos(theta5)), y + (radius * sin(theta5)));
    }
    glEnd();
}

void roadStripe() {
    /*Main Road*/
    glBegin(GL_QUADS);
    glColor3f(0.270, 0.270, 0.270);
    glVertex2f(-1, .3);
    glVertex2f(-1, .1);
    glVertex2f(1, .1);
    glVertex2f(1, .3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.917, 0.749, 0.211);
    glVertex2f(-1, .21);//2nd Line
    glVertex2f(-1, .19);
    glVertex2f(-.75, .19);
    glVertex2f(-.75, .21);

    glVertex2f(-.5, .21);//1st Line
    glVertex2f(-.5, .19);
    glVertex2f(-.25, .19);
    glVertex2f(-.25, .21);

    glVertex2f(0, .21);//3rd Line
    glVertex2f(.0, .19);
    glVertex2f(.25, .19);
    glVertex2f(.25, .21);

    glVertex2f(.5, .21);//4th Line
    glVertex2f(.5, .19);
    glVertex2f(.75, .19);
    glVertex2f(.75, .21);
    glEnd();
}

/*Car Portion Starts*/
void car1() {
    glBegin(GL_POLYGON);
    /*Car1 Body*/
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-.04, .2);
    glVertex2f(-.02, 0);
    glVertex2f(.7, 0);
    glVertex2f(.7, .15);
    glVertex2f(.65, .2);
    glEnd();
    /*Car1 Window Body*/
    glBegin(GL_POLYGON);
    glVertex2f(.2, .3);
    glVertex2f(0, .2);
    glVertex2f(.55, .2);
    glVertex2f(.4, .3);
    glEnd();
    /*Car1 Window*/
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(.2, .28);
    glVertex2f(0.04, .2);
    glVertex2f(.51, .2);
    glVertex2f(.4, .28);
    glEnd();
    /*Car1 Lights*/
    glBegin(GL_TRIANGLES);
    if (night) {
        glColor3f(1, 1, 1);
    }
    if (day) {
        glColor3f(0, 0, 0);
    }
    glVertex2f(.7, .15);
    glVertex2f(.6, .2);
    glVertex2f(.6, .15);
    glEnd();
    /*Car1 Wheels*/
    circle(.13, 0, .1, 0, 0, 0);
    circle(.13, 0, .07, 1.0, 1.0, 1.0);
    circle(.55, 0, .1, 0, 0, 0);
    circle(.55, 0, .07, 1.0, 1.0, 1.0);
}

void car2() {
    glBegin(GL_POLYGON);
    /*Car2 Body*/
    glColor3f(0.7, 0.0, 0.0);
    glVertex2f(-.04, .2);
    glVertex2f(-.02, 0);
    glVertex2f(.7, 0);
    glVertex2f(.7, .15);
    glVertex2f(.65, .2);
    glEnd();
    /*Car2 Window Body*/
    glBegin(GL_POLYGON);
    glVertex2f(.2, .3);
    glVertex2f(0, .2);
    glVertex2f(.55, .2);
    glVertex2f(.4, .3);
    glEnd();
    /*Car2 Window*/
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(.2, .28);
    glVertex2f(0.04, .2);
    glVertex2f(.51, .2);
    glVertex2f(.4, .28);
    glEnd();
    /*Car2 Lights*/
    glBegin(GL_TRIANGLES);
    if (night) {
        glColor3f(1, 1, 1);
    }
    if (day) {
        glColor3f(0, 0, 0);
    }
    glVertex2f(.7, .15);
    glVertex2f(.6, .2);
    glVertex2f(.6, .15);
    glEnd();
    /*Car2 Wheels*/
    circle(.13, 0, .1, 0, 0, 0);
    circle(.13, 0, .07, 1.0, 1.0, 1.0);
    circle(.55, 0, .1, 0, 0, 0);
    circle(.55, 0, .07, 1.0, 1.0, 1.0);
}

void car3() {
    glBegin(GL_POLYGON);
    /*Car3 Body*/
    glColor3f(0.0, 0.6, 0.7);
    glVertex2f(-.04, .2);
    glVertex2f(-.02, 0);
    glVertex2f(.7, 0);
    glVertex2f(.7, .15);
    glVertex2f(.65, .2);
    glEnd();
    /*Car3 Window Body*/
    glBegin(GL_POLYGON);
    glVertex2f(.2, .3);
    glVertex2f(0, .2);
    glVertex2f(.55, .2);
    glVertex2f(.4, .3);
    glEnd();
    /*Car3 Window*/
    glBegin(GL_POLYGON);
    glColor3f(0, 0.9, 0.9);
    glVertex2f(.2, .28);
    glVertex2f(0.04, .2);
    glVertex2f(.51, .2);
    glVertex2f(.4, .28);
    glEnd();
    /*Car3 Lights*/
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.2);
    glVertex2f(.7, .15);
    glVertex2f(.6, .2);
    glVertex2f(.6, .15);
    glEnd();
    /*Car3 Wheels*/
    circle(.13, 0, .1, 0.9, 0.5, 0.4);
    circle(.13, 0, .07, 0.0, 0.0, 0.0);
    circle(.55, 0, .1, 0.9, 0.5, 0.4);
    circle(.55, 0, .07, 0.0, 0.0, 0.0);
}
/*Car Portion End*/

void road() {
    roadStripe();
    glBegin(GL_QUADS);//1st Road
    glColor3f(0.435, 0.839, 0.360);
    glVertex2f(-1, .1);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, .1);
    glEnd();

    glTranslatef(0, -.3, 0);//2nd Road
    roadStripe();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(car1pos, 0, 0);
    glTranslatef(-.8, -.06, 0);
    glScalef(.4, .3, 1);
    car1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(car2pos, 0, 0);
    glTranslatef(.7, .14, 0);
    glScalef(-.4, .3, 1);
    car2();
    glLoadIdentity();
    glPopMatrix();

    /*Road Lamp*/
    float xLamp = -0.8f;
    float yLamp = 0.06f;
    for (int i = 0; i <= 4; i++) {
        glBegin(GL_QUADS);//Lamp Stand
        glColor3f(0.525, 0.372, 0.133);
        glVertex2f(xLamp, yLamp);
        glVertex2f(xLamp, yLamp + 0.1);
        glVertex2f(xLamp + .01, yLamp + 0.1);
        glVertex2f(xLamp + .01, yLamp);

        glColor3f(0, 0, 0);//Lamp Top
        glVertex2f(xLamp, yLamp + 0.1);
        glVertex2f(xLamp, yLamp + 0.09);
        glVertex2f(xLamp + 0.03, yLamp + 0.09);
        glVertex2f(xLamp + 0.03, yLamp + 0.1);
        glEnd();

        glBegin(GL_POLYGON);//Lamp Light
        if (night) {
            glColor3f(1, 1, 1);
        }
        else {
            glColor3f(0.337, 0.345, 0.333);
        }
        glVertex2f(xLamp + 0.02, yLamp + .09);
        glVertex2f(xLamp + 0.01, yLamp + 0.07);
        glVertex2f(xLamp + 0.03, yLamp + 0.07);
        glVertex2f(xLamp + 0.02, yLamp + .09);
        glEnd();
        xLamp += .5;
    }
}

void hill() {
    glBegin(GL_TRIANGLES);//For Large Hill
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0, 0);
    glVertex2f(.1, .1);
    glVertex2f(.2, 0);
    glEnd();

    glScalef(.7, .7, 1);
    glTranslatef(.2, 0, 0);

    glBegin(GL_TRIANGLES);//For Small Hill
    glColor3f(0.1, 0.7, 0.5);
    glVertex2f(0, 0);
    glVertex2f(.1, .1);
    glVertex2f(.2, 0);
    glEnd();
    glLoadIdentity();
}

void hillLong() {
    float x = -0.55;
    for (int i = 0; i < 10; i++) {
        glTranslatef(x, .6, 0);
        hill();
        glLoadIdentity();
        x += .25;
    }
}

void cow() {
    /*Cow Body*/
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.6);
    glVertex2f(0.1, .2);
    glVertex2f(0.1, 0.05);
    glVertex2f(.4, 0.05);
    glVertex2f(.4, .2);
    glEnd();
    /*Cow Leg Behind*/
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.6);
    glVertex2f(0.1, .1);
    glVertex2f(0.1, -.05);
    glVertex2f(.12, -.05);
    glVertex2f(.15, .1);
    glEnd();
    /*Cow Leg Front*/
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.6);
    glVertex2f(0.35, .1);
    glVertex2f(0.38, -.05);
    glVertex2f(.4, -.05);
    glVertex2f(.4, .1);
    glEnd();
    /*Cow Head*/
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.9, 0.7);
    glVertex2f(.35, .2);
    glVertex2f(.5, .15);
    glVertex2f(.55, .2);
    glVertex2f(.45, .25);
    glEnd();
    /*Cow Horns*/
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.43, .23);
    glVertex2f(.45, .25);
    glVertex2f(.3, .3);
    glEnd();
}

void c_circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat m, GLfloat n, GLfloat o) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m, n, o);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void c_circle2(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat m, GLfloat n, GLfloat o) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m, n, o);
    glVertex2f(cx, cy);
    for (int i = 19; i <= 30; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void c_circle3(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat m, GLfloat n, GLfloat o) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m, n, o);
    glVertex2f(cx, cy);
    for (int i = 17; i <= 30; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void chicken() {
    glBegin(GL_POLYGON);//Leg1 Straight Finger Top
    glColor3f(1, 0.6, 0.2);
    glVertex2f(-0.20f, -0.32f);
    glVertex2f(-0.16f, -0.32f);
    glVertex2f(-0.16f, -0.45f);
    glVertex2f(-0.20f, -0.45f);
    glEnd();

    glBegin(GL_POLYGON);//Leg1 Cross Finger
    glColor3f(1, 0.6, 0.2);
    glVertex2f(-0.30f, -0.45f);
    glVertex2f(-0.08f, -0.38f);
    glVertex2f(-0.08f, -0.43f);
    glVertex2f(-0.30f, -0.50f);
    glEnd();

    glBegin(GL_POLYGON);//Leg1 Straight Finger Bottom
    glColor3f(1, 0.6, 0.2);
    glVertex2f(-0.20f, -0.45f);
    glVertex2f(-0.16f, -0.45f);
    glVertex2f(-0.16f, -0.55f);
    glVertex2f(-0.20f, -0.55f);
    glEnd();

    glBegin(GL_POLYGON);//Leg2 Straight Finger Top
    glColor3f(1, 0.6, 0.2);
    glVertex2f(0.20f, -0.32f);
    glVertex2f(0.16f, -0.32f);
    glVertex2f(0.16f, -0.45f);
    glVertex2f(0.20f, -0.45f);
    glEnd();

    glBegin(GL_POLYGON);//Leg2 Cross Finger
    glColor3f(1, 0.6, 0.2);
    glVertex2f(0.30f, -0.45f);
    glVertex2f(0.08f, -0.38f);
    glVertex2f(0.08f, -0.43f);
    glVertex2f(0.30f, -0.50f);
    glEnd();

    glBegin(GL_POLYGON);//Leg2 Straight Finger Bottom
    glColor3f(1, 0.6, 0.2);
    glVertex2f(0.20f, -0.45f);
    glVertex2f(0.16f, -0.45f);
    glVertex2f(0.16f, -0.55f);
    glVertex2f(0.20f, -0.55f);
    glEnd();

    c_circle(0.36, 0.51, 0, 0.1, 0.0, 0.0, 0.0);
    c_circle(0.35, 0.50, 0, 0.10, 1.0, 1.0, 0.2);
    c_circle(0.26, 0.31, 0, 0.37, 0.0, 0.0, 0.0);//Hen Head
    c_circle(0.25, 0.30, 0, 0.37, 1.0, 1.0, 0.2);
    c_circle(0.08, 0.11, 0.09, 0.38, 0.0, 0.0, 0.0);//Hen Eye
    c_circle(0.08, 0.11, -0.09, 0.38, 0.0, 0.0, 0.0);
    c_circle(0.07, 0.10, 0.09, 0.38, 1.0, 1.0, 1.0);
    c_circle(0.07, 0.10, -0.09, 0.38, 1.0, 1.0, 1.0);
    c_circle(0.05, 0.08, 0.003, 0.75, 1, 0, 0.0);//Hen Tikli
    c_circle(0.02, 0.02, 0.085, 0.38, 0.0, 0.0, 0.0);//Hen Eye Ball
    c_circle(0.02, 0.02, -0.085, 0.38, 0.0, 0.0, 0.0);
    c_circle2(0.13, 0.17, 0.02, 0.10, 1.0, 0.0, 0.0);
    c_circle3(0.14, 0.18, 0, 0.10, 0.0, 0.0, 0.0);
    c_circle3(0.13, 0.17, 0, 0.10, 1.0, 0.8, 0.1);
    c_circle2(0.13, 0.17, 0, 0.55, 1.0, 0.0, 0.0);
}

void plane() {
    glBegin(GL_POLYGON);//Plane Body1
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.7f, 0.45f);
    glVertex2f(-0.5f, 0.45f);
    glVertex2f(-0.5f, 0.40f);
    glVertex2f(-0.7f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Body2
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.5f, 0.45f);
    glVertex2f(-0.46f, 0.45f);
    glVertex2f(-0.44f, 0.44f);
    glVertex2f(-0.44f, 0.41f);
    glVertex2f(-0.46f, 0.40f);
    glVertex2f(-0.50f, 0.40f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Body3
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.44f, 0.44f);
    glVertex2f(-0.40f, 0.44f);
    glVertex2f(-0.38f, 0.425f);
    glVertex2f(-0.40f, 0.41f);
    glVertex2f(-0.44f, 0.41f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Body4
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.7f, 0.45f);
    glVertex2f(-0.7f, 0.40f);
    glVertex2f(-0.75f, 0.40f);
    glVertex2f(-0.75f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Body5
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.75f, 0.44f);
    glVertex2f(-0.75f, 0.41f);
    glVertex2f(-0.78f, 0.41f);
    glVertex2f(-0.78f, 0.44f);
    glEnd();

    circle(-0.549, 0.50, 0.03, 0.4, 0.2, 0.9);
    glBegin(GL_POLYGON);//Plane Wings1
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.65f, 0.45f);
    glVertex2f(-0.65f, 0.55f);
    glVertex2f(-0.60f, 0.55f);
    glVertex2f(-0.50f, 0.45f);
    glVertex2f(-0.65f, 0.45f);
    glEnd();

    circle(-0.543, 0.355, 0.03, 0.4, 0.2, 0.9);
    glBegin(GL_POLYGON);//Plane Wings2
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.50f, 0.41f);
    glVertex2f(-0.50f, 0.40f);
    glVertex2f(-0.60f, 0.30f);
    glVertex2f(-0.65f, 0.30f);
    glVertex2f(-0.65f, 0.41f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Tail1
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.75f, 0.445f);
    glVertex2f(-0.75f, 0.50f);
    glVertex2f(-0.72f, 0.50f);
    glVertex2f(-0.70f, 0.445f);
    glEnd();

    glBegin(GL_POLYGON);//Plane Tail2
    glColor3f(0.4, 0.1, 0.0);
    glVertex2f(-0.70f, 0.41f);
    glVertex2f(-0.70f, 0.40f);
    glVertex2f(-0.72f, 0.35f);
    glVertex2f(-0.75f, 0.35f);
    glVertex2f(-0.75f, 0.41f);
    glEnd();
}

void Cloud() {
    circle(0.0, 0.8, 0.1, 0.686, 0.866, 0.933);
    circle(-0.1, 0.82, 0.1, 0.921, 0.980, 0.996);
    circle(0.0, 0.85, 0.1, 0.921, 0.980, 0.996);
    circle(0.1, 0.82, 0.1, 0.921, 0.980, 0.996);
    circle(0.0, 0.75, 0.1, 0.921, 0.980, 0.996);
}

/*Tree Section Starts*/
void tree() {
    float vTree = -0.95f;
    float zTree = 0.55f;
    float vTree2 = vTree + .05f;
    float zTree2 = zTree - .05f;

    glBegin(GL_QUADS);//Tree Left Stand
    glColor3f(0.482, 0.215, 0.078);
    glVertex2f(vTree, zTree + .15);
    glVertex2f(vTree, zTree);
    glVertex2f(vTree + .005, zTree);
    glVertex2f(vTree + .005, zTree + .15);

    glVertex2f(vTree2, zTree2 + .15);//Tree Right Stand
    glVertex2f(vTree2, zTree2);
    glVertex2f(vTree2 + .005, zTree2);
    glVertex2f(vTree2 + .005, zTree2 + .15);
    glEnd();

    vTree += .0025;
    vTree2 += .0025;
    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.8, 0.3);
    glVertex2f(vTree, zTree + .18);//Left Tree Top Triangle
    glVertex2f(vTree - .03, zTree + .12);
    glVertex2f(vTree + .03, zTree + .12);

    glVertex2f(vTree, zTree + .14);//Left Tree Bottom Triangle
    glVertex2f(vTree - .03, zTree + .08);
    glVertex2f(vTree + .03, zTree + .08);

    glVertex2f(vTree2, zTree2 + .18);//Right Tree Top Triangle
    glVertex2f(vTree2 - .03, zTree2 + .12);
    glVertex2f(vTree2 + .03, zTree2 + .12);

    glVertex2f(vTree2, zTree2 + .14);//Right Tree Bottom Triangle
    glVertex2f(vTree2 - .03, zTree2 + .08);
    glVertex2f(vTree2 + .03, zTree2 + .08);
    glEnd();

    vTree += 0.3;
    vTree2 += 0.3;
}
/*Tree Section Ends*/

void declare(char* string) {
    while (*string) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
    }
}

void board() {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.87, 0.8);
    glVertex2f(-0.87, 0.6);
    glVertex2f(-0.865, 0.6);
    glVertex2f(-0.865, 0.8);
    glEnd();
}

void board2() {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.6, 0.6);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.4, 0.7);
    glVertex2f(-0.9, 0.7);
    glVertex2f(-0.9, 0.5);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2f(-0.86, 0.59);
    declare("Rajshahi Dairy Farm");
}

void board3() {
    glBegin(GL_QUADS);
    glColor3f(0.5, 1.0, 0.5);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.8, 0.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(0.45, 0.55);
    declare("Owner of");
    glColor3f(0.0, 0.0, 1.0);
    glRasterPos2f(0.40, 0.51);
    declare("Rajshahi Dairy");
}

void carpet() {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.6);
    glVertex2f(0.45, 0.41);
    glVertex2f(0.45, 0.2);
    glVertex2f(0.55, 0.2);
    glVertex2f(0.55, 0.41);
    glEnd();
}

void dairy() {
    /*Dairy Body*/
    glBegin(GL_QUADS);
    glColor3f(0.788, 0.788, 0.788);
    glVertex2f(0, 0);
    glVertex2f(0, -.2);
    glVertex2f(.5, -.2);
    glVertex2f(.5, 0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glRasterPos2f(0.15, -.07);
    declare("Cow Dairy");

    /*Dairy Top Floor*/
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1.0);
    glVertex2f(-.01, 0);
    glVertex2f(-.01, -.01);
    glVertex2f(.51, -.01);
    glVertex2f(.51, 0);
    glEnd();

    /*Dairy Door*/
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 0.5);
    glVertex2f(0.2, -.1);
    glVertex2f(0.2, -.2);
    glVertex2f(.3, -.2);
    glVertex2f(.3, -.1);
    glEnd();
}

/*Human Section Starts*/
void human() {
    glPushMatrix();
    /*Top Cloth*/
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-.06, -.06);
    glVertex2f(-.11, -.09);
    glVertex2f(-.09, -.13);
    glVertex2f(-.06, -.11);
    glVertex2f(-.06, -.22);
    glVertex2f(.06, -.22);
    glVertex2f(.06, -.11);
    glVertex2f(.09, -.13);
    glVertex2f(.11, -.09);
    glVertex2f(.06, -.06);
    glVertex2f(.04, -.10);
    glVertex2f(-.04, -.10);
    glEnd();
    glPopMatrix();

    /*Left Hand*/
    glPushMatrix();
    glColor3f(1.0, 0.9, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(-.11, -.09);
    glVertex2f(-.09, -.13);
    glVertex2f(-.13, -.2);
    glVertex2f(-.16, -.18);
    glEnd();
    glPopMatrix();

    /*Left Hand Finger*/
    glPushMatrix();
    glTranslatef(-.15, -.2, 0.0);
    circle(.0001, -.01, 0.03, 1.0, 0.9, 0.7);
    glPopMatrix();

    /*Right Hand*/
    glPushMatrix();
    glColor3f(1.0, 0.9, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(.11, -.09);
    glVertex2f(.09, -.13);
    glVertex2f(.13, -.2);
    glVertex2f(.16, -.18);
    glEnd();
    glPopMatrix();

    /*Right Hand Finger*/
    glPushMatrix();
    glTranslatef(.147, -.2, 0.0);
    circle(.0001, -.01, .03, 1.0, 0.9, 0.7);
    glPopMatrix();

    /* Left Pant*/
    glPushMatrix();
    glColor3f(0.8, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-.06, -.38);
    glVertex2f(-.06, -.22);
    glVertex2f(-.02, -.22);
    glVertex2f(-.02, -.38);
    glEnd();
    glPopMatrix();

    /* Left Leg*/
    glPushMatrix();
    glColor3f(0.8, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(-.06, -.32);
    glVertex2f(-.02, -.32);
    glVertex2f(-.02, -.38);
    glVertex2f(-.06, -.38);
    glEnd();
    glPopMatrix();

    /* Right Pant*/
    glPushMatrix();
    glColor3f(0.8, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(.06, -.38);
    glVertex2f(.06, -.22);
    glVertex2f(.02, -.22);
    glVertex2f(.02, -.38);
    glEnd();
    glPopMatrix();

    /*Right Leg*/
    glPushMatrix();
    glColor3f(0.8, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(.06, -.32);
    glVertex2f(.02, -.32);
    glVertex2f(.02, -.38);
    glVertex2f(.06, -.38);
    glEnd();
    glPopMatrix();

    /*Right Shoe*/
    glPushMatrix();
    glColor3f(0.7, 1, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(.1, -.42);
    glVertex2f(.02, -.42);
    glVertex2f(.02, -.38);
    glVertex2f(.06, -.38);
    glEnd();
    glPopMatrix();

    /*Left Shoe*/
    glPushMatrix();
    glColor3f(0.7, 1, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-.1, -.42);
    glVertex2f(-.02, -.42);
    glVertex2f(-.02, -.38);
    glVertex2f(-.06, -.38);
    glEnd();
    glPopMatrix();

    /*Hair*/
    glPushMatrix();
    circle(.01, .02, .06, 0, 0, 0);
    glPopMatrix();

    /*Head*/
    glPushMatrix();
    circle(.0088, -0.01, .05, 1.0, 0.9, 0.7);
    glPopMatrix();

    /*Right Eye*/
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(.02, .02);
    glVertex2f(.03, .02);
    glEnd();
    glPopMatrix();

    /*Left Eye*/
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-.02, .02);
    glVertex2f(-.01, .02);
    glEnd();
    glPopMatrix();

    /*Lips*/
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(.024, -.03);
    glVertex2f(-.015, -.03);
    glEnd();
    glPopMatrix();

    /*Nose*/
    circle(.0035, 0.001, .01, 0, 0, 0);
    glPopMatrix();
}
/*Human Section End*/

/*Field Section Starts*/
void field() {
    glBegin(GL_QUADS);
    if (night) {
        glColor3f(0.3, 0.7, 0.3);
    }
    else {
        glColor3f(0.0, 0.60, 0.09);
    }
    glVertex2f(-1, .6);
    glVertex2f(-1, .24);
    glVertex2f(1, .24);
    glVertex2f(1, .6);
    glEnd();

    /*For Board*/
    glTranslatef(0, -.05, 0);
    board();
    glLoadIdentity();

    glTranslatef(0.23, -.05, 0);
    board();
    glLoadIdentity();

    glTranslatef(-0.09, .19, 0);
    board2();
    glLoadIdentity();

    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(0.22, -.25, 0);
        board3();
        glLoadIdentity();
    }

    /*Field Elements*/
    glTranslatef(-0.40, .04, 0);
    carpet();
    glLoadIdentity();

    glTranslatef(-.85, .6, 0);
    glScalef(1, 1, 1);
    dairy();
    glLoadIdentity();

    glTranslatef(.48, .6, 0);
    glScalef(1, 1, 1);
    dairy();
    glLoadIdentity();

    glTranslatef(-.15, .65, 0);
    glScalef(1, 1, 1);
    dairy();
    glLoadIdentity();

    /*For Trees*/
    glTranslatef(0, -.05, 0);
    tree();
    glLoadIdentity();

    glTranslatef(.7, -.08, 0);
    tree();
    glLoadIdentity();

    glTranslatef(1.34, -.08, 0);
    tree();
    glLoadIdentity();

    /*For Cow*/
    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(.25, .40, 0);
        glScalef(.35, .35, 1);
        glTranslatef(cowMovX, cowMovY, 0);
        cow();
        glLoadIdentity();
    }

    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(.01, .42, 0);
        glScalef(-.35, .35, 1);
        glTranslatef(cowMovX, cowMovY, 0);
        cow();
        glLoadIdentity();
    }

    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(-0.4, .40, 0);
        glScalef(.35, .35, 1);
        glTranslatef(cowMovX, cowMovY, 0);
        cow();
        glLoadIdentity();
    }

    /*For Car*/
    if (night) {
        glTranslatef(-0.001, .32, 0);
        glScalef(.50, .35, 0);
        glRotatef(angle, 0.0, 1.0, 0.0);
        glTranslatef(car3MovX, car3MovY, 0);
        car3();
        glLoadIdentity();
    }
    else {
        glTranslatef(0, 0, 0);
    }

    /*For Human*/
    if (night) {
        glTranslatef(0.0, 0.0, 0.0);
    }
    else {
        glTranslatef(.90, .45, 0);
        glScalef(.35, .35, 1);
        glTranslatef(humanMovX, humanMovY, 0.0);
        human();
        glLoadIdentity();
    }

    /*For Chicken*/
    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(-0.9, .45, 0);
        glScalef(.10, .10, 0);
        glTranslatef(chickenMovX, chickenMovY, 0);
        chicken();
        glLoadIdentity();
    }

    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(-0.7, .45, 0);
        glScalef(.10, .10, 0);
        glTranslatef(chickenMovX, chickenMovY, 0);
        chicken();
        glLoadIdentity();
    }

    if (night) {
        glTranslatef(0, 0, 0);
    }
    else {
        glTranslatef(-0.5, .45, 0);
        glScalef(.10, .10, 0);
        glTranslatef(chickenMovX, chickenMovY, 0);
        chicken();
        glLoadIdentity();
    }
}
/*Field Section End*/

/*Sky Section Starts*/
void moon() {
    circle(0.6, 0.7, 0.15, 1, 1, 1);
    circle(0.65, 0.75, 0.15, 0.164, 0.180, 0.239);
}

void sky() {
    if (day) {
        circle(0.25, 0.84, 0.1, 1, 0.733, 0.2);//Day Sun
    }
    if (night) {
        glTranslatef(-.2, .35, 0);
        glScalef(.7, .7, 1);
        moon();
        glLoadIdentity();
    }

    glTranslatef(cloudMov, 0.0, 0);
    glTranslatef(-.3, .35, 0);
    glScalef(.6, .6, 1);
    Cloud();
    glLoadIdentity();

    glTranslatef(cloudMov, 0.0, 0);
    glTranslatef(.7, .4, 0);
    glScalef(.6, .6, 1);
    Cloud();
    glLoadIdentity();

    glTranslatef(planeMov, 0.0, 0);
    glTranslatef(-.5, .60, 0);
    glScalef(.6, .6, 1);
    plane();
    glLoadIdentity();
}
/*Sky Section End*/

/*River Section Starts*/
void river() {
    glBegin(GL_QUADS);
    glColor3f(0.26, 0.73, 1.0);
    if (night) {
        glColor3f(0.133, 0.207, 0.211);
    }
    glVertex2f(-1, -.3);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.3);
    glEnd();
}

void riverLine() {
    glBegin(GL_LINES);
    GLfloat x = -1.8;
    glColor3f(0.6, 0.9, 0.9);
    if (night) {
        glColor3f(0.133, 0.207, 0.211);
    }
    for (int i = 0; i <= 10; i++) {
        glVertex2f(x, -.3);
        glVertex2f(x, -1);
        x += .6;
    }
    glEnd();
}
/*River Section Ends*/

/*Ship Section Starts*/
void smoke(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 20; i++) {
        GLfloat theta2 = 2.0f * PI * i / 20;
        glVertex2f(cx + (cos(theta2) * rx), cy + (sin(theta2) * ry));
    }
    glEnd();
}

void ship() {
    glBegin(GL_POLYGON);//Main Body
    glColor3f(0.4, 0.6, 0.3);
    glVertex2f(-.15, -.7);
    glVertex2f(-.05, -.85);
    glVertex2f(.55, -.85);
    glVertex2f(.65, -.7);
    glEnd();

    GLfloat xCircle = 0.01f;
    GLfloat yCircle = -.78f;
    GLfloat radius = .03f;
    for (int i = 0; i < 5; i++) {
        glBegin(GL_TRIANGLE_FAN);//Main Body Window
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(xCircle, yCircle);
        for (int i = 0; i <= 20; i++) {
            GLfloat theta4 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + ((radius - .003) * cos(theta4)), yCircle + ((radius - .003) * sin(theta4)));
        }
        glEnd();
        xCircle += .12;
    }

    glBegin(GL_QUADS);//Main Body Roof
    glColor3f(0.4, 0.3, 1.0);
    glVertex2f(-0.15, -.7);
    glVertex2f(-0.15, -.68);
    glVertex2f(.65, -.68);
    glVertex2f(.65, -.7);
    glEnd();

    glBegin(GL_QUADS);//Upper Body
    glColor3f(0.5, 0.4, 0.3);
    glVertex2f(-0.05, -.68);
    glVertex2f(-0.05, -.6);
    glVertex2f(.55, -.6);
    glVertex2f(.55, -.68);
    glEnd();

    xCircle = 0.05f;
    yCircle = -.645f;
    radius = .025f;
    for (int i = 0; i < 5; i++) {
        glBegin(GL_TRIANGLE_FAN);//Upper Body Window
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(xCircle, yCircle);
        for (int i = 0; i <= 20; i++) {
            GLfloat theta4 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + ((radius - .003) * cos(theta4)), yCircle + ((radius - .003) * sin(theta4)));
        }
        glEnd();
        xCircle += .1;
    }

    glBegin(GL_POLYGON);//Top Body
    glColor3f(0.6, 0.6, 0.1);
    glVertex2f(-0.03, -.55);
    glVertex2f(-0.03, -.6);
    glVertex2f(.53, -.6);
    glVertex2f(.5, -.55);
    glEnd();

    glBegin(GL_QUADS);/*Smoke1 Body*/
    glColor3f(1.0, 0.7, 0.8);
    glVertex2f(.1, -.45);
    glVertex2f(.1, -.55);
    glVertex2f(.15, -.55);
    glVertex2f(.15, -.45);

    glColor3f(0.6, 1.0, 0.9);/*Smoke1 Head*/
    glVertex2f(.1, -.43);
    glVertex2f(.1, -.45);
    glVertex2f(.15, -.45);
    glVertex2f(.15, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.016, 0.026, .126, -.41);

    glBegin(GL_QUADS);/*Smoke2 Body*/
    glColor3f(1.0, 0.7, 0.8);
    glVertex2f(.2, -.45);
    glVertex2f(.2, -.55);
    glVertex2f(.25, -.55);
    glVertex2f(.25, -.45);

    glColor3f(0.6, 1.0, 0.9);/*Smoke2 Head*/
    glVertex2f(.2, -.43);
    glVertex2f(.2, -.45);
    glVertex2f(.25, -.45);
    glVertex2f(.25, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.016, 0.026, .226, -.41);

    glBegin(GL_QUADS);/*Smoke3 Body*/
    glColor3f(1.0, 0.7, 0.8);
    glVertex2f(.3, -.45);
    glVertex2f(.3, -.55);
    glVertex2f(.35, -.55);
    glVertex2f(.35, -.45);

    glColor3f(0.6, 1.0, 0.9);/*Smoke3 Head*/
    glVertex2f(.3, -.43);
    glVertex2f(.3, -.45);
    glVertex2f(.35, -.45);
    glVertex2f(.35, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.016, 0.026, .326, -.41);

    if (night) {
        glBegin(GL_TRIANGLES);//Ship Light
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(-0.05, -.68);
        glVertex2f(-0.65, -.72);
        glVertex2f(-0.65, -.86);
        glEnd();
    }
}

void ship2() {
    glBegin(GL_POLYGON);//Main Body
    glColor3f(0.5, 0.5, 0.1);
    glVertex2f(-.15, -.7);
    glVertex2f(-.05, -.85);
    glVertex2f(.55, -.85);
    glVertex2f(.65, -.7);
    glEnd();

    GLfloat xCircle = 0.01f;
    GLfloat yCircle = -.78f;
    GLfloat radius = .03f;
    for (int i = 0; i < 5; i++) {
        glBegin(GL_TRIANGLE_FAN);//Main Body Window
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(xCircle, yCircle);
        for (int i = 0; i <= 20; i++) {
            GLfloat theta3 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + ((radius - .003) * cos(theta3)), yCircle + ((radius - .003) * sin(theta3)));
        }
        glEnd();
        xCircle += .12;
    }

    glBegin(GL_QUADS);//Main Body Roof
    glColor3f(0.219, 0.219, 0.219);
    glVertex2f(-0.15, -.7);
    glVertex2f(-0.15, -.68);
    glVertex2f(.65, -.68);
    glVertex2f(.65, -.7);
    glEnd();

    glBegin(GL_QUADS);//Upper Body
    glColor3f(0.5, 0.4, 0.3);
    glVertex2f(-0.05, -.68);
    glVertex2f(-0.05, -.6);
    glVertex2f(.55, -.6);
    glVertex2f(.55, -.68);
    glEnd();

    xCircle = 0.05f;
    yCircle = -.645f;
    radius = .025f;
    for (int i = 0; i < 5; i++) {
        glBegin(GL_TRIANGLE_FAN);//Upper Body Window
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(xCircle, yCircle);
        for (int i = 0; i <= 20; i++) {
            GLfloat theta3 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + ((radius - .003) * cos(theta3)), yCircle + ((radius - .003) * sin(theta3)));
        }
        glEnd();
        xCircle += .1;
    }

    glBegin(GL_POLYGON);//Top Body
    glColor3f(0.5, 0.5, 0.6);
    glVertex2f(-0.03, -.55);
    glVertex2f(-0.03, -.6);
    glVertex2f(.53, -.6);
    glVertex2f(.5, -.55);
    glEnd();

    glBegin(GL_QUADS);/*Smoke1 Body*/
    glColor3f(0.4, 0.6, 0.6);
    glVertex2f(.1, -.45);
    glVertex2f(.1, -.55);
    glVertex2f(.15, -.55);
    glVertex2f(.15, -.45);

    glColor3f(0.8, 0.8, 0.8);/*Smoke1 Head*/
    glVertex2f(.1, -.43);
    glVertex2f(.1, -.45);
    glVertex2f(.15, -.45);
    glVertex2f(.15, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.02, 0.026, .127, -.41);

    glBegin(GL_QUADS);/*Smoke2 Body*/
    glColor3f(0.4, 0.6, 0.6);
    glVertex2f(.2, -.45);
    glVertex2f(.2, -.55);
    glVertex2f(.25, -.55);
    glVertex2f(.25, -.45);

    glColor3f(0.8, 0.8, 0.8);/*Smoke2 Head*/
    glVertex2f(.2, -.43);
    glVertex2f(.2, -.45);
    glVertex2f(.25, -.45);
    glVertex2f(.25, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.02, 0.026, .227, -.41);

    glBegin(GL_QUADS);/*Smoke3 Body*/
    glColor3f(0.4, 0.6, 0.6);
    glVertex2f(.3, -.45);
    glVertex2f(.3, -.55);
    glVertex2f(.35, -.55);
    glVertex2f(.35, -.45);

    glColor3f(0.8, 0.8, 0.8);//Smoke3 Head
    glVertex2f(.3, -.43);
    glVertex2f(.3, -.45);
    glVertex2f(.35, -.45);
    glVertex2f(.35, -.43);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Smoke
    smoke(0.02, 0.026, .327, -.41);

    /*For Light*/
    if (night) {
        glBegin(GL_TRIANGLES);//Ship Light
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(0.65, -0.7);
        glVertex2f(0.95, -0.75);
        glVertex2f(0.95, -0.88);
        glEnd();
    }
}
/*Ship Section Ends*/

/*Boat Section Starts*/
void boatM() {
    glBegin(GL_POLYGON);//Boat Body
    glColor3f(1.0, 1.0, 0.6);
    glVertex2f(0, 0);
    glVertex2f(0.02, -0.05);
    glVertex2f(0.18, -0.05);
    glVertex2f(0.2, 0);
    glEnd();

    glBegin(GL_TRIANGLES);//Boat Small Flag
    glColor3f(0.9, 0.5, 0.7);
    glVertex2f(0.06, 0);
    glVertex2f(0.075, 0);
    glVertex2f(0.075, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);//Boat Large Flag
    glColor3f(0.9, 0.5, 0.6);
    glVertex2f(0.08, 0);
    glVertex2f(0.125, 0);
    glVertex2f(.08, 0.1);
    glEnd();

    /*For Light*/
    if (night) {
        glBegin(GL_TRIANGLES);//Boat Light
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(0.19, -0.01);
        glVertex2f(0.28, -0.02);
        glVertex2f(0.27, -0.05);
        glEnd();
    }
}

void boatM2() {
    glBegin(GL_POLYGON);//Boat Body
    glColor3f(1.0, 0.9, 0.9);
    glVertex2f(0, 0);
    glVertex2f(0.02, -0.05);
    glVertex2f(0.18, -0.05);
    glVertex2f(0.2, 0);
    glEnd();

    glBegin(GL_TRIANGLES);//Boat Small Flag
    glColor3f(0.9, 0.5, 0.5);
    glVertex2f(0.11, 0);
    glVertex2f(0.095, 0);
    glVertex2f(0.095, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);//Boat Large Flag
    glColor3f(0.9, 0.5, 0.3);
    glVertex2f(0.09, 0);
    glVertex2f(0.045, 0);
    glVertex2f(.09, 0.1);
    glEnd();

    /*For Light*/
    if (night) {
        glBegin(GL_TRIANGLES);//Boat Light
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(0.01, -0.01);
        glVertex2f(-0.1, -0.02);
        glVertex2f(-0.08, -0.05);
        glEnd();
    }
}
/*Boat Section Ends*/

/*Train Section Starts*/
void trainTrack() {
    glBegin(GL_LINES);
    glColor3f(0.392, 0.113, 0.047);
    glVertex2f(-1, -.205);
    glVertex2f(1, -.205);

    glVertex2f(-1, -.12);
    glVertex2f(1, -.12);
    GLfloat x = -1.5;
    GLfloat y = -.12;
    while (x < 1.5) {
        glVertex2f(x, y);
        glVertex2f(x, y - .085);
        x += 0.03;
    }
    glEnd();
}

void train() {
    /*Train Wheel*/
    GLfloat xCircle = -.45f;
    GLfloat yCircle = -0.18f;
    GLfloat radius = .02f;
    while (xCircle <= .42) {
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0, 0.0, 0.0);//For Outside Portion of the Wheel
        glVertex2f(xCircle, yCircle);//CenterX, CenterY
        for (int i = 0; i <= 20; i++) {
            GLfloat theta1 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + (radius * cos(theta1)), yCircle + (radius * sin(theta1)));
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.6, 0.7, 0.8);//For Inside Portion of the Wheel
        glVertex2f(xCircle, yCircle);//CenterX, CenterY
        for (int i = 0; i <= 20; i++) {
            GLfloat theta1 = 2.0f * PI * i / 20;
            glVertex2f(xCircle + ((radius - .003) * cos(theta1)), yCircle + ((radius - .003) * sin(theta1)));
        }
        glEnd();
        xCircle += .05;
    }
    /*Train Wheel End*/

    glBegin(GL_QUADS);//Train Main Body
    glColor3f(0.109, 0.282, 0.505);
    glVertex2f(-.48, -.05);
    glVertex2f(-.48, -.18);
    glVertex2f(.45, -.18);
    glVertex2f(.45, -.05);
    glEnd();

    glBegin(GL_POLYGON);//Train Smoke Machine
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(.4, -.02);
    glVertex2f(.4, -.03);
    glVertex2f(.41, -.05);
    glVertex2f(.43, -.05);
    glVertex2f(.44, -.03);
    glVertex2f(.44, -.02);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);//Train Smoke
    smoke(0.01, 0.01, 0.42, -0.001);
    smoke(0.014, 0.01, 0.43, 0.01);
    smoke(0.014, 0.01, 0.41, 0.01);
    smoke(0.01, 0.01, 0.42, 0.02);
    smoke(0.01, 0.014, 0.41, -0.001);

    glBegin(GL_QUADS);//Train Main Body Line
    glColor3f(0.713, 0.6, 0.439);
    glVertex2f(-.48, -.06);
    glVertex2f(-.48, -.07);
    glVertex2f(.45, -.07);
    glVertex2f(.45, -.06);

    glBegin(GL_QUADS);//Train Window Body
    glVertex2f(-.48, -.09);
    glVertex2f(-.48, -.15);
    glVertex2f(.45, -.15);
    glVertex2f(.45, -.09);

    GLfloat x1 = -0.45;
    GLfloat y1 = -0.09;
    GLfloat y2 = -.13;
    while (x1 <= .1) {
        glColor3f(0, 0, 0);
        glVertex2f(x1, y1);//Train Window
        glVertex2f(x1, y2);
        glVertex2f(x1 + .03, y2);
        glVertex2f(x1 + .03, y1);

        glVertex2f(x1 + 0.12, y1);//Train Window
        glVertex2f(x1 + 0.12, y2);
        glVertex2f(x1 + 0.15, y2);
        glVertex2f(x1 + 0.15, y1);

        glColor3f(0.6, 0.8, 0.8);//Engine Door
        glVertex2f(x1 + 0.17, y1 + .04);//Train Door
        glVertex2f(x1 + 0.17, y2 - .04);
        glVertex2f(x1 + 0.195, y2 - .04);
        glVertex2f(x1 + 0.195, y1 + .04);
        x1 += .25;
    }

    glColor3f(0.6, 0.8, 0.8);//Engine Door
    glVertex2f(.295, y1 + .04);
    glVertex2f(.295, y2 - .04);
    glVertex2f(0.34, y2 - .04);
    glVertex2f(0.34, y1 + .04);

    glColor3f(0.0, 0.0, 0.0);//Engine Window
    glVertex2f(.35, y1 + .02);
    glVertex2f(.35, y2 + .02);
    glVertex2f(.365, y2 + .02);
    glVertex2f(.365, y1 + .02);

    glVertex2f(.375, y1 + .02);//Engine Window
    glVertex2f(.375, y2 + .02);
    glVertex2f(.39, y2 + .02);
    glVertex2f(.39, y1 + .02);
    glEnd();
    if (night) {
        glBegin(GL_TRIANGLES);//Train Light
        glColor3f(0.968, 0.968, 0.788);
        glVertex2f(0.45, -0.11);
        glVertex2f(0.45, -0.17);
        glVertex2f(0.7, -0.17);
        glEnd();
    }
}
/*Train Section Ends*/

/*Windmill Section Starts*/
void windmill() {
    glBegin(GL_QUADS);//Mill Stick
    glColor3f(0.5, 0.2, 0.1);
    glVertex2f(.1, .47);
    glVertex2f(.1, .32);
    glVertex2f(.11, .32);
    glVertex2f(.11, .47);
    glEnd();

    /*For Animation*/
    /*glPushMatrix() Copies TopMatrix & Pushes into Stack*/
    glPushMatrix();
    glTranslatef(0.105, .47, 0.0);
    /*i = How many Degree we want to Rotate Around an Axis*/
    glRotatef(i, 0.0, 0.0, 0.1);
    glBegin(GL_TRIANGLES);//Mill Wings
    glColor3f(1.0, 1.0, 1.0);//White Wings
    glVertex2f(.0, .0);
    glVertex2f(-.06, -.11);
    glVertex2f(-.08, -.12);

    glColor3f(1.0, 0.0, 1.0);//Beguni Wings
    glVertex2f(.0, .0);
    glVertex2f(-.07, .09);
    glVertex2f(-.09, .10);

    glColor3f(1.0, 1.0, 0.0);//Yellow Wings
    glVertex2f(.0, .0);
    glVertex2f(.11, -.02);
    glVertex2f(.12, -.04);
    glEnd();
    /*glPopMatrix Pops TopMatrix into Stack*/
    glPopMatrix();

    /*Circle of Fan*/
    GLfloat xMoon = 0.105f;
    GLfloat yMoon = .47f;
    GLfloat moonRadius = .02f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1, 0.6, 0.5);
    glVertex2f(xMoon, yMoon);//CenterX, CenterY
    for (int i = 0; i <= 20; i++) {
        GLfloat theta = 2.0f * PI * i / 20;
        glVertex2f(xMoon + (moonRadius * cos(theta)), yMoon + (moonRadius * sin(theta)));
    }
    glEnd();
}
/*Windmill Section Ends*/

void scene() {
    sky();
    hillLong();
    glScalef(1, .7, 1);
    glTranslatef(0, .05, 0);
    road();
    field();
    glLoadIdentity();

    riverSideRoadGrass();
    glTranslatef(0, -.02, 0);
    glScalef(1.0, 0.8, 0.0);
    trainTrack();
    glLoadIdentity();

    glScalef(1.0, 0.8, 0.0);
    glTranslatef(trainPos, 0.0, 0.0);
    glTranslatef(0, -.02, 0);
    train();
    glLoadIdentity();

    /*For Wind Mills*/
    glTranslatef(-.9, -.6, 0);
    windmill();
    glLoadIdentity();

    glTranslatef(-.13, -.6, 0);
    windmill();
    glLoadIdentity();

    glTranslatef(.6, -.6, 0);
    windmill();
    glLoadIdentity();

    /*For River*/
    river();
    glPushMatrix();
    glTranslatef(riverLinePos, 0.0, 0.0);
    riverLine();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shipPos2, 0, 0);
    glTranslatef(-.4, .02, 0);
    glScalef(.5, .5, 0.0);
    ship2();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boat, 0.0, 0.0);
    glTranslatef(0.2, -.45, 0);
    glScalef(1.5, 1.5, 0);
    boatM();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(shipPos, 0, 0);
    ship();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boat2, 0.0, 0.0);
    glTranslatef(-0.6, -.8, 0);
    glScalef(1.7, 1.7, 0);
    boatM2();
    glLoadIdentity();
    glPopMatrix();

    if (isRain) {
        glTranslatef(rainMovX, rainMovY, 0);
        rain();
        glLoadIdentity();
    }
}

void display() {
    if (night) {
        glClearColor(0.164f, 0.180f, 0.239f, 1.0f);
    }
    else {
        glClearColor(0.552f, 0.733f, 0.839f, 1.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);
    glLoadIdentity();
    scene();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Computer Graphics Lab Project");
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}