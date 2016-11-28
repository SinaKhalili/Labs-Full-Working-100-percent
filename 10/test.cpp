#include <stdint.h>
#include "image.hpp"
#include <stdio.h>
#include <stdlib.h>

int main(){
  Image* img = new Image();
  int i = img->cols;
  printf("hello %d \n", i);
  img->resize(5,45, 3);
  i = img->cols;
  printf("hello %d \n", i);
  int j = 0;
  for(i = 0 ; i < img->rows; i++ ){
    for(j = 0; j < img->cols; j++){
      printf("%d ", img->pixels[j*img->cols + i]);
    }
    printf("\n");
  }
  img->resize(7,7, 7);
  for(i = 0 ; i < img->rows; i++ ){
    for(j = 0; j < img->cols; j++){
      printf("%d ", img->pixels[j*img->cols + i]);
    }
    printf("\n");
  }

  delete img;


}
