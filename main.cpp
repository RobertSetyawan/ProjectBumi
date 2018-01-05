#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

static int planet1=0, satelit1=0, planet2=0, satelit2=0;
//float pmatax,pmatay,pmataz,pandangx,pandangy,pandangz;

float pmatax = 0.0f;
float pmatay = 2.0f;
float pmataz = 13.0f;
float pandangx = 0.0f;
float pandangy = 0.0f;
float pandangz = 0.0f;

float pindah = 0.8f;

void init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={100.0};
    GLfloat light_position0[]={1.0,1.0,1.0,0.0};
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
    GLfloat light_position1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
}

void gambar(void){
    //Warna Matahari
     glColor3f(1.0,0.0,0.0);

     glPushMatrix();
     //Matahari
     glutSolidSphere(1.0,80,18);

     //Alur putar planet1
     glRotatef((GLfloat)planet1,0.0,1.0,0.0);
     //posisi planet terhadap matahari
     glTranslatef(2.0,0.0,0.0);
     //Warna planet
     glColor3f(0.0,1.0,1.0);
     //ukuran dari planet
     glutSolidSphere(0.3,50,9);

     //Alur putar satelit1
     glRotatef((GLfloat)satelit1,0.0,1.0,0.0);
     //posisi satelit
     glTranslatef(0.5,0.0,0.0);
     //Warna satelit
     glColor3f(1.0,1.0,1.0);
     //ukuran satelit
     glutSolidSphere(0.1,80,4);
     glPopMatrix();

     glPushMatrix();
     //Alur putar planet2
     glRotatef((GLfloat)planet2,0.0,1.0,0.0);
     //posisi planet terhadap matahari
     glTranslatef(3.5,0.0,0.01);
     //Warna planet
     glColor3f(0.0,1.0,1.0);
     //ukuran dari planet
     glutSolidSphere(0.6,80,9);
     glPopMatrix();

     glPopMatrix();
}
void display(void) {
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();

     //menset titik mata, titik pandang
     gluLookAt(pmatax,pmatay,pmataz,pandangx,pandangy,pandangz,0.0,1.0,0.0);
     gambar();
     glutSwapBuffers();

}

void reshape(int w, int h) {
     glViewport(0,0,(GLsizei)w,(GLsizei)h);
     glMatrixMode(GL_PROJECTION);

     //mengukur kedalaman windows
     gluPerspective(40.0,(GLfloat)w/(GLfloat)h,1.0,100.0);
     glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

}

void keyboard(unsigned char key, int x, int y) {
     if(key == 'a'){
        pmatax += pindah;
   }
    else if (key == 'd'){
        pmatax-= pindah;
             }
     else if (key == 's'){
        pmatay-= pindah;
    }
     else if (key == 'w'){
        pmatay+= pindah;
   }
     else if(key == 'p'){
        planet1=(planet1+3); glutPostRedisplay();
          satelit1=(satelit1+7); glutPostRedisplay();
          planet2=(planet2+5); glutPostRedisplay();
     }
     glutPostRedisplay();
}

int main(int argc, char** argv) {

     glutInit(&argc, argv);

     glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
     glutInitWindowSize(800,800);
     glutInitWindowPosition(0,0);
     glutCreateWindow("Sistem Revolusi Bumi");

     init();

     glutReshapeFunc(reshape);
     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     glutMainLoop();
     return 0;
}
