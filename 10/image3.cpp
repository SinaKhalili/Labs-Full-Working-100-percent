#include <stdint.h>
#include "image3.hpp"
#include <stdio.h>
#include <stdlib.h>

Image::Image()
  : cols(0),
    rows(0),
    pixels(NULL){{}{}}
/* Frees all memory allocated for img */
Image::~Image()
{
  if(pixels != NULL){
    int i =0 ;
    for(i =0;i<this->rows;i++){
      delete[] pixels[i];
    }
    delete[] pixels;
  }
}
/* Changes the size of an image, allocating memory as necessary, and
setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/
int Image::resize( unsigned int width,
                   unsigned int height,
                   uint8_t fillcolor )
{
  int i = 0;
  for(i =0;i<this->rows;i++){
    delete[] this->pixels[i];
  }
  delete[]this->pixels;

  this->cols = width;
  this->rows = height;
  uint8_t ** swagswag = new uint8_t*[height];
  int w = 0;
  for(w = 0; w < height; w++){
    swagswag[w] = new uint8_t[width];
  }
  this->pixels = swagswag;
  if(!(this->pixels)){
     return 1;
  }
  int j = 0;
  for (i=0; i<height; i++){
    for(j=0; j<width; j++){
    this->pixels[i][j] = fillcolor;
    }
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

  this->pixels[y][x] = color;
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
  *colorp = this->pixels[y][x];
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
    int len = 0;
    fwrite(&len, sizeof(int), 1, fs);
    fclose(fs);
    return 0;
  }
  int len = this->cols * this->rows;
  int colser = this->cols;
  int rowser = this->rows;
  fwrite(&len, sizeof(int), 1, fs);
  fwrite(&colser, sizeof(int), 1, fs);
  fwrite(&rowser, sizeof(int), 1, fs);
  int i = 0;
  int j = 0;
  for(i = 0; i < rowser ; i++){
    for(j = 0; j < colser; j++){
      fwrite(&(this->pixels[i][j]), sizeof(uint8_t), 1 , fs);
    }
  }

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
  if(leny == 0){
    this->pixels = NULL;
    this->cols = 0;
    this->rows = 0;
    fclose(fs);
    return 0;
  }
  fread(&rowsy, sizeof(int), 1, fs);
  fread(&colsy, sizeof(int), 1, fs);

  //printf("Len: %d  Cols %d Rows: %d\n", leny,colsy,rowsy);
  this->resize(colsy,rowsy,0);
  int i = 0;
  int j = 0;
  for(i = 0; i < rowsy ; i++){
    for(j = 0; j < colsy; j++){
      fread(&(this->pixels[i][j]), sizeof(uint8_t), 1, fs);
    }
  }

  fclose(fs);
  return 0;
}
