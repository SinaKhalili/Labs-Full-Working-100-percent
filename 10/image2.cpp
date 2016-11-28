#include <stdint.h>
#include "image2.hpp"
#include <stdio.h>
#include <stdlib.h>


Image::Image()
  : cols(0),
    rows(0),
    pixels(NULL){}
/* Frees all memory allocated for img */
Image::~Image()
{
  if(pixels != NULL){
    delete[] pixels;
  }
}
/* Changes the size of an image, allocating memory as necessary, and
setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/
int Image::resize( unsigned int width,
                   unsigned int height,
                   uint8_t fillcolor )
{
  delete[] pixels;
  this->cols = width;
  this->rows = height;
  uint8_t * swagswag = new uint8_t[width*height];
  this->pixels = swagswag;
  if(!(this->pixels)){
     return 1;
  }
  int i = 0;
  for (i=0; i<width*height; i++){
    this->pixels[i] = fillcolor;
  }
  return 0;
}

/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero
   error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
  if(x >= this->cols){
    return 1;
  }
  if(y >= this->rows){
    return 1;
  }

  this->pixels[y*this->cols + x] = color;
  return 0;
}
/* Gets the color of the pixel at (x,y) and stores at the address pointed to
   by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
  if(!colorp){
    return 1;
  }
  if(x >= this->cols)
  {
    colorp = NULL;
    return 1;
  }
  if(y >= this->rows)
  {
    colorp = NULL;
    return 1;
  }
  *colorp = this->pixels[y*this->cols + x];
  return 0;
}

/* Saves the image in the file filename. In a format that can be
   loaded by load().  Returns 0 on success, else a non-zero error
   code. */
int Image::save( const char* filename ){
  if(filename == NULL){
    return 1;
  }
  FILE * fs = fopen(filename, "w");
  if(!fs){
    return 1;
  }
  if(this->pixels == NULL){
    return 1;
  }
  int len = this->cols * this->rows;
  int colser = this->cols;
  int rowser = this->rows;
  fwrite(&len, sizeof(int), 1, fs);
  fwrite(&colser, sizeof(int), 1, fs);
  fwrite(&rowser, sizeof(int), 1, fs);

  fwrite(this->pixels, sizeof(uint8_t), len, fs);

  fclose(fs);
  return 0;
}

/* Load the an image from the file filename, replacing the current
   image size and data. The file is in a format that was saved by
   save().  Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename ){
  if(filename == NULL){
    return 1;
  }
  FILE * fs = fopen(filename, "r");
  if(!fs){
    return 1;
  }

  int leny = 0;
  int colsy = 0;
  int rowsy = 0;
  fread(&leny, sizeof(int), 1, fs);
  fread(&rowsy, sizeof(int), 1, fs);
  fread(&colsy, sizeof(int), 1, fs);

  //printf("Len: %d  Cols %d Rows: %d\n", leny,colsy,rowsy);
  this->resize(colsy,rowsy,0);

  fread(this->pixels, sizeof(uint8_t), leny, fs);

  fclose(fs);
  return 0;
}
