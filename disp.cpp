#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<cmath>
#include<iostream>
#include<string.h>

using namespace std;
int scap, qcap, dqcap, cqcap, top = -1, kkey = 32, linp = 0, value, l[100], iinp = 0, jinp = 0, leninp[50], pushed = 0, poped = 0, len = 0;
bool check, fullstate = false, empstate = false, push = NULL, pop = NULL, mpush = NULL, mpop = NULL, entered = false, mentered = false, pentered = false, go = false, go1 = false, timepush = false, timepop = false, be = true;
float x, y, p = -20, q, r = 20, s = 100, a = -20, b = 1000, c = 19.65, d;
char inp[100], st[100][100], minp[100][100], t[50];

void stack();
void pushele();
void popele();
void mpushele();
void mpopele();
void singlepush();
void singlepop();

void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}
GLuint LoadTexture( const char * filename )
{

  GLuint texture;

  int width, height;

  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = 1024;
  height = 512;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
{
   int index = i*3;
   unsigned char B,R;
   B = data[index];
   R = data[index+2];

   data[index] = R;
   data[index+2] = B;

}


glGenTextures( 1, &texture );
glBindTexture( GL_TEXTURE_2D, texture );
glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
free( data );

return texture;
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void draw_poly(float a, float b, float c, float d)
{
    glBegin(GL_POLYGON);
    glVertex2f(a,b);
    glVertex2f(a,d);
    glVertex2f(c,d);
    glVertex2f(c,b);
    glEnd();
}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        x = (float)mousex/3.5-100;
        y = (700-(float)mousey)/3.5-100;
        if(x<=-50 && x>=-80 && y<=40 && y>=25)
        {
            pushele();
        }
        else if(x<=-50 && x>=-80 && y<=20 && y>=5)
        {
            popele();
        }
        else if(x<=-50 && x>=-80 && y<=0 && y>=-15)
        {
            mpushele();
        }
        else if(x<=-50 && x>=-80 && y<=-10 && y>=-35)
        {
            mpopele();
        }
        else if(x<=65 && x>=53 && y<=70 && y>=60)
        {
            go = true;
        }
        else if(x<=95 && x>=83 && y<=70 && y>=60)
        {
            go1 = true;
        } 
    }
    glutPostRedisplay();
}

int j=0;
void keyboard(unsigned char key, int x, int y)
{
    kkey = (int)key;
    if(be == true)
    {
        cout<<"true";
        if(kkey == 13)
        {
            glutDisplayFunc(stack);
            be = false;
        }
    }
    if(push == true)
    {
        if(kkey == 13)
        {
            entered = true;
        }
        else if(isdigit(key) || key == '-')
        {
            inp[linp] = char(kkey);
            linp++;
        }
        //glutPostRedisplay();
    }
    else if(mpush == true)
    {
        if(kkey == 13)
        {
            mentered = true;
            leninp[iinp] = jinp;
        }
        else if(isdigit(key) || key == '-')
        {
            minp[iinp][jinp] = char(kkey);
            jinp++;
            inp[linp] = char(kkey);
            linp++;
        }
        else if(key == ' ')
        {
            leninp[iinp] = jinp;
            iinp++;
            inp[linp] = ', ';
            linp++;
            jinp = 0;
        }
    }
    else if(mpop == true)
    {
        if(kkey == 13)
        {
            pentered = true;
        }
        else if(isdigit(key) && kkey>=49 && kkey <= 57)
        {
            inp[linp] = char(kkey);
            linp++;
            len = kkey-48;
        }
    }
    glutPostRedisplay();
}

void pushele()
{
    if(top == scap-1)
    {
        fullstate = true;
    }
    else
    {
        push = true;
    }
}

void popele()
{
    if(top == -1)
    {
        empstate = true;
    }
    else
    {
        pop = true;
    }
}

void mpushele()
{
    if(top == scap-1)
    {
        fullstate = true;
    }
    else
    {
        mpush = true;
    }
}
void mpopele()
{
    if(top == -1)
    {
        empstate = true;
    }
    else
    {
        mpop = true;
    }
}

void printtext(char s[], int x, int y, int l, int state = 1)
{
    glRasterPos2i(x,y);
    for(int i = 0;i<l;i++)
    {
        if(state == 1)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
        else if(state == 2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
        else if(state == 3)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
}

void print_top(int scap)
{
    printtext("Top --> ", -42, -50+(top+1)*(100/scap), 8);
    printtext("Top = ", 40, 0, 6);
    if(top == -1)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 45);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 49);
    }
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, top + 48);
    }
}


void timer1(int)
{
    if(timepush == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60,timer1,0);
        if(s > value)
        {
            s -= 1.3;
            q = s+100/scap;
        }
        else
        {
            timepush = false;
        }
    }
}
void timer2(int)
{
    if(timepop == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60, timer2, 0);
        if(d < 100)
        {
            b += 1.3;
            d = b - 100/scap + 0.35;
        }
        else
        {
            timepop = false;
        }
    }
}

