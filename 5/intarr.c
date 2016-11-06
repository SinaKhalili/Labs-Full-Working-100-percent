#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.

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
  for(n; n< ia->len; n++){
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
  int k = 0;
  for ( k; k<ia->len; k++){
    newArray[k] = ia->data[k];
  }
  newArray[k+1] = val;
  int* tmpPtr;
  ia->len +=1;
  tmpPtr = ia->data;
  ia->data=newArray;
  free(tmpPtr);
}

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i );


//REMEMBER TO fukin  DELETE THIS MAIN FUNCTION BEFORE HANDING IT IN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*int main(){

    intarr_t* test = intarr_create(4);

    intarr_set(test, 0, 5);
    intarr_set(test, 1, 4);
    intarr_set(test, 2, 6);
    intarr_set(test, 3, 7);
    intarr_push(test, 500);


    intarr_t* fergie = intarr_copy(test);

    int number = 0; int i =0;
    intarr_find(test, 7, &number);
    printf("This number should be a three: %d \n", number);

    intarr_get(test, 2, &i);
    printf("This should be a six: %d\n", i );
    for(i=0; i<fergie->len; i++){
      printf("%d =: %d \n",i, *(fergie->data+i));
    }
    intarr_sort(fergie);
    i = 0;
    for(i=0; i<fergie->len; i++){
      printf("%d =: %d \n",i, *(fergie->data+i));
    }
    printf("Here should be the number seven: %d \n", test->data[3]);
    intarr_destroy(test);
    return 0;

}*/
