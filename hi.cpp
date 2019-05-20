#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
using namespace std;

int width = 480;
int height = 640;



void init()
{
  glClearColor(0,0,0,0);
  glMatrixMode(GLUT_SINGLE | GLUT_RGB);
  glLoadIdentity();
  glOrtho(-90,100,-15,100,0,1);
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

void display()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20,20,-20,20,-1,1);

  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_EQUAL,1);

  LoadTexture( "cse.bmp" );

  glutSwapBuffers();
  glFlush();
}

int main(int arg, char ** argv)
{
  glutInit(&arg,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(30,30);
  glutInitWindowSize(width, height);
  glutCreateWindow("Hi");
  init();
  glutDisplayFunc(display);
}
