#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include<math.h>
double change = 3.14/180*4;
void reshape(int width, int height){
     glViewport(0, 0, width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0, (double)width/height, 0.1, 100.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(5.0, 5.0, 13.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
}
void setup(){
    float lightPosition[4] = {5.25, 2.0, 0.25, 0.5};
    float ambient[4] = {0.3, 0.5, 0.0, 0.5};
    float diffuse[4] = {1.0, 1.0, 0.3, 0.5};
    float specular[4] = {1.0, 1.0, 1.0, 0.5};
     float shininess[1] = {20.0};

     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
     glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
     glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
     glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}
void key(unsigned char key, int x, int y){
    switch (key){
        case'q':
            exit(0);
            break;
        case'c':
            glutPostRedisplay();
            break;
        default:
            break;
    }
}
void display(void){
     glEnable(GL_DEPTH_TEST);
     glClearColor(0.0, 0.0, 0.0, 1.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     int x = 10;
     int y = 90;
     int z = 90;
   //  int rot=10;
     glPushMatrix();

     for(int k=0; k<x; k++){
         for(int j=0; j<y; j++){
             for(int i=0; i<z; i++){
                 glPushMatrix();
                 glColor4d( k*0.1, 0.5, i*0.01, 0.5);
                 //glTranslatef(2*cos(rot*i*change), 2*sin(rot*i*change), -k);
                 glTranslatef(2*sin(j*change)*cos(i*change)+4*sin(k*9*change), 2*sin(j*change)*sin(i*change)+4*cos(k*9*change), 2*cos(j*change));
                 glutSolidCube(0.3);
                 glPopMatrix();
             }
         }
     }
     glutSwapBuffers();
}
int main(int argc, char * argv[]) {

     glutInit(&argc, argv);
     glutInitWindowSize(500, 500);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
     glutCreateWindow("for");
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(key);
 //    setup();
     glutMainLoop();
    return 0;
}

