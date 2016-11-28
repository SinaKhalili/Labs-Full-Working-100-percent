#include <stdint.h>
#include "image.hpp"
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
