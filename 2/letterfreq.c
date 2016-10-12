#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){

  int c = getchar();
  int letters[26] = {};
  float lettersCounters[26] = {};
  float totalLetterCount = 0.0;

  int i = 0;

  for(i; i<26; i++){
    letters[i] =  97+i;
  }

  i = 0;
  while (c!=EOF){
  if ((c > 64 && c<91)||(c > 96 && c<123)){
    if(c < '[' ){
      //printf("the %c character is now", c);
      c += 32;
      //printf(" a %c\n",c );
    }
    for ( i ; i<26; i++){
      if (letters[i] == c){
        lettersCounters[i] += 1.0;
        //printf("a counter was pushed up on letter %d\n", i );
        totalLetterCount += 1.0;
      }
    }
    i = 0;

  }

  //printf("the totalLetterCount is now %f because I just ate a %c\n", totalLetterCount, c);
  c = getchar();
  }
  float sum = 0.0;
  float freq = 0.0;
  for(i; i<26; i++){
    if (lettersCounters[i]!=0.0000){
      //printf("The number of %c is %f\n", letters[i], lettersCounters[i] );
      //printf("The total character count is %f\n", totalLetterCount );
      freq = lettersCounters[i]/totalLetterCount;
      sum+=freq;
      printf( "%c %.4f\n", letters[i], freq);
      //printf("The sum is now %f\n", sum );
    }
  }
}
