#include <stdlib.h>
#include <stdio.h>
//#include <sys/time.h>
//#include <time.h>
#include <stdint.h>
#include <assert.h>
#include "point_array.h"
// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
  assert(pa);
  pa->len = 0;
  pa->points = malloc(sizeof(point_t)*2);
  pa->reserved = 1;
  //printf("The reserved is (init): %zu \n", pa->reserved );
}
// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
  assert(pa);
  free(pa->points);
  free(pa);
  pa->len = 0;
  pa->reserved = 0;
  //printf("The reserved is (reset) : %zu \n", pa->reserved );

}
// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){

  if(!pa){
    return 1;
  }
  if(!p){
    return 1;
  }
  //void *newPointer;
  pa->reserved--;

  if(pa->reserved == 0 && pa->len!=0){

    pa->points = realloc(pa->points,sizeof(point_t)*(pa->len)*2);
    pa->reserved = pa->len;
    //printf("The reserved is (append I got to the inner loop): %zu \n", pa->reserved );

  }

  else if(pa->reserved == 0){
    pa->points = malloc(sizeof(point_t)*2);
    pa->reserved = 1;
    //printf("The reserved is (second loop): %zu \n", pa->reserved );
  }
  if(!(pa->points)){
    return 1;
  }
  pa->points[pa->len]=*p;
  pa->len++;
  //printf("The reserved is (append) : %zu \n", pa->reserved );
  return 0;

}
// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
  if(!pa){
    return 1;
  }
  if(pa->len == 0){
    return 1;
  }
  if(i >= pa->len){
    return 1;
  }

  //printf("I got here\n");
  pa->points[i] = pa->points[pa->len-1];
  //pa->points = realloc(pa->points, sizeof(point_t)*(pa->len-1));
  //printf("I should not be here\n");
  //printf("I also got here\n");
  if(pa->points != NULL || pa->len>0){
    pa->len--;
    pa->reserved++;
    //printf("The reserved is (remove): %zu \n", pa->reserved );

  return 0;
  }

  return 1;
}
