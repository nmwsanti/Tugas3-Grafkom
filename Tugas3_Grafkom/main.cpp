#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"

const double PI = 3.141592653589793;
int i;

void back(){
glBegin(GL_QUADS);
glColor3f(1,1,1);
  glVertex2d (-150,150);
  glVertex2d(150,150);
  glVertex2d(150,-150);
  glVertex2d (-150,-150);
glEnd();
}

void ellips(float rx, float ry, float xc, float yc, int n){
    glBegin( GL_POLYGON);
    double t;
    for  (int i=0;  i < n;  ++i) {
       	t = i * 2.0 * 3.14159 / n;
       	glVertex2f( ry*cos(t)+yc, rx*sin(t)+xc );
    }
  	glEnd();
}

void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_POLYGON);
 for (i=0;i<=360;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  glVertex2f(x,y);
 }
 glEnd();
}

void Draw() {
 glClear(GL_COLOR_BUFFER_BIT);
 back();
 glColor3f(0.0,0.0,1.0); //badan berwarna biru
 lingkaran(10,70,0,0);

 glColor3f(0,0.5,1); //kepala berwarna biru sayan
 ellips(8,5.0,5,0.0,36.0);

 glColor3f(1.0,1.0,1.0); // mata berwarna putih
 lingkaran(2,70,2.5,8);// mata kiri
 lingkaran(2,70,-2.5,8); // mata kanan

 glColor3f(0.0,0.0,0.0); // bola mata berwarna hitam
 lingkaran(1,70,-1.9,8); // bola mata kiri
 lingkaran(1,70,1.9,8); // bola mata kanan

 glColor3f(1.0,0.0,0.0); //mulut berwarna merah
 lingkaran(1,70,0,0);

 glColor3f(0.0,0.0,1.0); // warna biru
 lingkaran(2,70,5,12); // telinga kanan
 lingkaran(2,70,-5,12); // telinga kiri

 glBegin(GL_POLYGON); // kaki kiri warna biru
 glColor3f(0.0,0.0,1.0);
    glVertex2d (-6,-12);
    glVertex2d(-5,-12);
    glVertex2d(-5,0);
    glVertex2d (-6,0);
    glEnd();

glBegin(GL_POLYGON); // kaki kanan warna biru
glColor3f(0.0,0.0,1.0);
    glVertex2d(6,-12);
    glVertex2d(5,-12);
    glVertex2d(5,0);
    glVertex2d(6,0);
    glEnd();

 glFlush();
}


int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutInitWindowPosition(300, 300);
 glutCreateWindow("Sapi Biru");
 gluOrtho2D(-15., 15., -15., 15.);
 glutDisplayFunc(Draw);
 glutMainLoop();
 return 0;
}
