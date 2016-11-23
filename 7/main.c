#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();

  for( int i=0; i<5; i++ )
    list_append( list, i );
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
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
