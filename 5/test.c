#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    intarr_t* test = intarr_create(4);

    intarr_set(test, 0, 5);
    intarr_set(test, 1, 4);
    intarr_set(test, 2, 6);
    intarr_set(test, 3, 7);

    intarr_resize(test, 7);

    printf("This number should be a zero : %d \n", test->data[3]);
    int i =0;
    for(i=0; i<test->len; i++){
      printf("%d =: %d \n",i, *(test->data+i));
    }


    intarr_t* fergie = intarr_copy(test);

    int number = 0;
    intarr_find(test, 7, &number);
  //  printf("This number shhaegregretgould be a three: %d \n", number);

    intarr_get(test, 2, &i);
    printf("This should be a six: %d\n", i );

    intarr_sort(fergie);
    i = 0;
    for(i=0; i<fergie->len; i++){
      printf("%d =: %d \n",i, *(fergie->data+i));
    }
    printf("Here should be the number seven: %d \n", test->data[3]);
    intarr_destroy(test);
    return 0;

}
