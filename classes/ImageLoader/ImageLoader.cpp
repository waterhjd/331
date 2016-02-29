#include <cstdio>

#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>
#include "ImageLoader.h"

using namespace std;

GLuint ImageLoader::LoadTexture( const char * filename, int &w, int &h )
{
  GLuint texture;
  int width = 1024, height = 512;

  unsigned short depth;
  unsigned char * data;
  unsigned long i;                    // standard counter.

  FILE * file;
  file = fopen( filename, "rb" );

  if ( file == NULL )
  {
     printf("Can't load picture file %s  \n",filename);
     return 0;
  }

   int fileSize;
   fseek(file, 2, SEEK_SET);
   if ((i = fread(&fileSize, 4, 1, file)) != 1) 
	{
		printf("Error reading file size from %s.\n", filename);
		return 0;
    }
    //printf("Size of %s: %lu\n", filename, fileSize);

   // seek through the bmp header, up to the width/height:
   fseek(file, 18, SEEK_SET);
   // read the width
   if ((i = fread(&width, 4, 1, file)) != 1) 
   {
      printf("Error reading width from %s.\n", filename);
      return 0;
   }
   //printf("Width of %s: %lu\n", filename, width); 

   // read the height 
   if ((i = fread(&height, 4, 1, file)) != 1) 
   {
      printf("Error reading height from %s.\n", filename); 
      return 0;
   }
   //printf("Height of %s: %lu\n", filename, height);

   // read the colour depth
   fseek(file, 28, SEEK_SET);
   if ((i = fread(&depth, 2, 1, file)) != 1)
   {
      printf("Error reading colour depth from %s.\n", filename); 
      return 0;
   }
   printf("Depth of %s: %lu\n", filename, depth); 

   // this file will only read files with depth of 24 and 32
   if(depth != 24 && depth != 32){
      printf("Unexpected colour depth");
      return 0;
   }

   // get the size of the header
   fseek(file, 10, SEEK_SET);
   int offset;
   if ((i = fread(&offset, 4, 1, file)) != 1) 
   {
      printf("Error reading offset from %s.\n", filename);
      return 0;
   }
   printf("offset of %s: %lu\n", filename, offset); 

   // Debug Dr. J Seek past the header. How big is the 
   // header of a bmp file?
   fseek(file, offset, SEEK_SET); 

   //fseek(file,headersize,SEEK_SET);

   // pixelval is the number of ints (4 bytes) per pixel
   // ex: for a 24-bit BMP file we expect 3 ints per pixel
   unsigned short pixelval = depth / 8;
   data = (unsigned char *)malloc( width * height * pixelval );
   //int size = fseek(file,);
   fread( data, width * height * pixelval, 1, file );
   fclose( file );

   w = width;
   h = height;
   if(pixelval == 3){
      for(int i = 0; i < width * height ; ++i)
      {
         int index = i*3;
         unsigned char B,R;
         B = data[index];
         R = data[index+2];

         data[index] = R;
         data[index+2] = B;
      }
   }else if(pixelval == 4){
      for(int i = 0; i < width * height ; ++i)
      {
         int index = i*4;
         unsigned char A, G, B, R;
         A = data[index];
         B = data[index+1];
         G = data[index+2];
         R = data[index+3];

         data[index] = R;
         data[index+1] = G;
         data[index+2] = B;
         data[index+3] = A;
      }
   }

   glGenTextures( 1, &texture );
   glBindTexture( GL_TEXTURE_2D, texture );
   glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
   glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
cerr << "Before pixelval\nData:\n" << data << "\n";
   if(pixelval == 3){
cerr << "pixelval3\n";
      gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
cerr << "after 3 build2DMipmaps\n";
   }else if(pixelval == 4){
cerr << "pixelval4\n";
      gluBuild2DMipmaps( GL_TEXTURE_2D, 4, width, height,GL_RGBA, GL_UNSIGNED_BYTE, data );
cerr << "after 4 build2DMipmaps\n";
   }
   free( data );

   return texture;
}

void ImageLoader::drawBox(GLfloat size, GLenum type, int x, int y, int xangle, int yangle)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;


  glTranslated(x,y,0);
  glRotated(xangle, 1.0, 0.0, 0.0);
  glRotated(yangle, 0.0, 1.0, 0.0);

  for (i = 5; i >= 0; i--) {
    glBegin(GL_POLYGON);
    glNormal3fv(&n[i][0]);
    glTexCoord2i(0, 0);glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2i(0, 1);glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2i(0, 1);glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2i(1, 1);glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2i(1, 0);glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void ImageLoader::RenderString(float x, float y, void *font, const char* string)
{  
  char *c;

  const unsigned char* string2 = (const unsigned char*)string;

  //glColor3f(1.0, 0.0, 0.0); 
  glRasterPos2f(x, y);

  glutBitmapString(font, string2);
}

void ImageLoader::arc(GLfloat x, GLfloat y, GLfloat r, int n, int s, int e) 
{
   int i;
   GLfloat r2 = r/2.0;
   glBegin(GL_POLYGON);
   {
      for (i = s; i < e; i++) {
          double a = 2*i*M_PI/n;
	  glVertex2f(x+r2+r2*cos(a),y+r2+r2*sin(a));
      }
   }
   glEnd();
}

void ImageLoader::circle(GLfloat x, GLfloat y, GLfloat r, int n) 
{
   arc(x, y, r, n, 0, n);
}

void ImageLoader::rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) 
{
   glTranslated(x,y,0);
   glBegin(GL_QUADS); // Note: A GL_QUADS is similar to a GL_POLYGON, but it limits the 
                      // number of vertices to 4. This allows OpenGL to break it up 
                      // into two triangles quite simply for faster processing. 
                      // This is needed if we are adding textures.
   {
           glTexCoord2i(0, 0); glVertex2i(0,   0);
           glTexCoord2i(0, 1); glVertex2i(0,   height);
           glTexCoord2i(1, 1); glVertex2i(width, height);
           glTexCoord2i(1, 0); glVertex2i(width, 0);
   }
   glEnd();
}

void ImageLoader::line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness) 
{
   glLineWidth(thickness);
   glBegin(GL_LINES);
   {
      glVertex2f(x1,y1);
      glVertex2f(x2,y2);
   }
   glEnd();
   glLineWidth(1.f);//reset
}
