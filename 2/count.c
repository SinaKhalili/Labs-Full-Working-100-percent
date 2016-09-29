#include<stdio.h>
#include<stdlib.h>
int main () {
  int character = 0;
  int words = 0;
  int lines = 0;
  int c = getchar();
  while( c != -1){
    character++;
    if(!((c > 64 && c<91)||(c > 96 && c<123)||(c == 39))){
      //do new lines count as words? maybe?
      words++;
    }
    if(c == 10){
      lines++;
    }
    c = getchar();
  }
  printf("%lu %lu %lu\n", character, words, lines );
}
