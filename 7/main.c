#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();

  //task 1

  list_t* list1 = list_create(); list1->head = NULL; list_index(list1, 5);
  list_destroy(list1);
  //task 2
int i = 0;
list_t* list2 = list_create();
list_prepend(list2, 9);
if(list2->head!=list2->tail){
  printf("This is t4 failing\n");
  return 1;
}
element_t* t6Tester = list_index(list2, 51);
free(t6Tester); 
for(i=0;i<200; i++){
  list_append(list2,54);
}
list_destroy(list2);
list_t* list21 = list_create();
list_append(list21,54);
list_destroy(list2);





  //list->head = list->head->next;
  /*int i = 0;

  int* test = malloc(sizeof(int)* 10000);
  int tester = 0;
  for(tester=0; tester<10000; tester++){
    test[tester] = rand();
    printf("%d", test[tester]);
  }
  free(test);


    list_t* list1 = list_create();
    if(list1 == NULL ){
      printf("failed\n");
      return 1;
    }
    if ( list->head != NULL){
            printf("failed\n");
      return 1;
    }
    if(list->tail != NULL){
      printf("failed\n");
      return 1;
    }*/



  //list_prepend(list1, 1);

  //list_prepend(list1, NULL);

  //task 2
  /*element_t element2 = element_create();
  element2 = NULL;
  list_append( list,  );
*/


  for( int i=0; i<5; i++ )
    list_append( list, i );

  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );

  if(list->tail->next != NULL){
      printf("This is t2 failing\n");
      assert(list->tail->next == NULL);
  }



  list_print( list );



  int index = 2;
  element_t* el = list_index( list, index );

  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }

  printf( "value at index %d is %d\n", index, el->val );

  if( el->val != -2 )
    return 1;

  list_destroy( list );

  return 0; // tests pass
}
