#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

intarr_t* intarr_create( unsigned int len ){
  intarr_t* swaggyP = malloc( sizeof(intarr_t));
  swaggyP->data = malloc(len * sizeof(int));
  if(swaggyP == NULL){
    return NULL;
  }
  swaggyP->len = len;
  return swaggyP;
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
  if(ia->data == NULL || ia == NULL){
    return;
  }
  free(ia);
  return;
}

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ){
  if(!ia){
    return INTARR_BADARRAY;
  }
  if( index < 0 || index > ((ia->len) - 1)){
    return INTARR_BADINDEX;
  }
  *(ia->data+index) = val;
  return INTARR_OK;
}
// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* i ){
  if(!ia){
    return INTARR_BADARRAY;
  }
  if( index < 0 || index > ((ia->len) - 1) || i == NULL){
    return INTARR_BADINDEX;
  }

  *i = ia->data[index];
  return INTARR_OK;
}

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia ){
  if(ia == NULL){
    return NULL;
  }
  intarr_t* HillaryClinton = malloc(sizeof(intarr_t));
  *HillaryClinton = *ia;
  HillaryClinton->data = malloc (HillaryClinton->len * (sizeof(int)));
  memcpy(HillaryClinton->data, ia->data, (HillaryClinton->len)*(sizeof(int) ) ) ;
  if(HillaryClinton->data == NULL){
    return NULL;
  }
  return HillaryClinton;
}

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){

  if(!ia){
    return INTARR_BADARRAY;
  }
  //PreCond: array pointer is valid and n is the length
  //PostCond: return sorted array in ascending order
  int current;
  int innerCount;
  int p;
  int tmp;
   for ( current = 0 ; current < ( ia->len - 1 ) ; current++ )
   {
      p = current;
      for ( innerCount = current + 1 ; innerCount < ia->len ; innerCount++ ){
         if ( ia->data[p] > ia->data[innerCount] )
            p = innerCount;
       }
      if ( p != current ){
         tmp = ia->data[current];
         ia->data[current] = ia->data[p];
         ia->data[p] = tmp;
       }
    }
    return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){

  if(!ia){
    return INTARR_BADARRAY;
  }
  int n = 0;
  for(n = 0; n< ia->len; n++){
    if(ia->data[n] == target){
      *i = n;
        return INTARR_OK;
    }
  }
  return INTARR_NOTFOUND;


}

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  if(!ia){
    return INTARR_BADARRAY;
  }
  int* newArray = malloc((ia->len+1)*sizeof(int));
  if(!newArray){
    return INTARR_BADALLOC;
  }
  int k = 0;
  for ( k =0; k<ia->len; k++){
    newArray[k] = ia->data[k];
  }
  newArray[k] = val;
  int* tmpPtr;
  ia->len +=1;
  tmpPtr = ia->data;
  ia->data=newArray;
  free(tmpPtr);
  //printf("I just pushed a zero into the array, boss. \n");
  return INTARR_OK;
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){

  if(!ia){
    return INTARR_BADARRAY;
  }
  if(ia->len < 0 || i == NULL){
    return INTARR_BADINDEX;
  }
  int* newArray = malloc((ia->len-1)*sizeof(int));
  int k = 0;
  for ( k =0; k<ia->len-1; k++){
    newArray[k] = ia->data[k];
  }
  *i = ia->data[k];
  int* tmpPtr = ia->data;
  ia->len -= 1;
  ia->data=newArray;
  free(tmpPtr);
  //printf("I just popped a molly fam. \n");
  return INTARR_OK;
}

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  if(!ia){
    return INTARR_BADARRAY;
  }
  int difference = newlen - ia->len; 

  //printf("The difference is %d ! \n", difference);

  if(newlen > ia->len){
    int i = 0;
    for(i = 0; i< difference;i++){
        if(intarr_push( ia, 0 ) == INTARR_BADALLOC){
          //printf("I just pushed a zero into the array, boss. \n");
            return INTARR_BADALLOC;
        }
    }
  }
  if(difference<0){
    int k = 0;
    int i = 0;
    for(i = 0; i<=((ia->len)-newlen);i++){
        if(intarr_pop( ia , &k ) == INTARR_BADALLOC){
            return INTARR_BADALLOC;
        }
    }
  }
  return INTARR_OK;
}
// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia,
				unsigned int first,
				unsigned int last ){
        int difference = last - first + 1; 
        if(!ia || 
          (first<0) || 
          (last > ia->len -1) || 
          (last < first)){

          return NULL; 
        }
        intarr_t* RipStick = malloc ( sizeof(intarr_t)); 
        RipStick->data = malloc(difference*sizeof(int)); 
        int i = first;
        int k = 0; 
        for ( i = first; i <= last; i++){
          RipStick->data[k] = ia->data[i];
          k++; 
        }
        RipStick->len = difference; 
        //printf("Copied the subarray boss! \n");
        return RipStick;
        }