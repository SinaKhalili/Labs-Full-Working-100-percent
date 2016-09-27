#include<stdio.h>
int main( void )
{
  unsigned int a[0] = {};
  unsigned int b[0] = {};

  if( scrambled( a, b, 0 ) == 1 )
  {
     printf( "b is a scrambled version of a\n" );
  } else {
     printf( "b has different contents to a\n" );
  }

  return 0;
}

int scrambled( unsigned int a[], unsigned int b[], unsigned int len ){
    int i = 0;
    int o = 0;
    int k = 0;
    int counter1 =0;
    int counter2 =0;
    for(i; i<len; i++){
        k = a[i];
        for(o; o<len; o++){
            if(k==a[o]){
                counter1++;
            }
        }
        o=0;
        for(o; o<len; o++){
            if(k==b[o]){
                counter2++;
            }
        }
        o=0;
        if(counter2 != counter1){
            return 0;
        }
    }
    return 1;
}
