#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]) {

  int d = 0;
  char word[128] = {};
  int c = getchar();

  int counter = 0;

  int i = 0;
  int k = 0;
  int j = 1;
  int wordIncrementor = 0;

  while( c!=EOF ){

        if(!((c > 64 && c<91)||(c > 96 && c<123)||(c == 39))){
          if ((d > 64 && d<91)||(d > 96 && d<123)||(d == 39)){
            for(counter; counter<128 ; counter++){
              word[counter] = 0;
            }
            counter = 0;
            for (j; j<argc; j++){
              //printf("Checking word %d \n", j);
              for (i ; i < strlen(argv[j]); i++){
                //printf("Checking letter %d of word %d \n", i, j );
                //printf("Comparing %c from words to %c from arguments\n", word[i], argv[j][i]);
                if(word[i] != argv[j][i]){
                  k++;
                  //printf("I'm about to break\n");
                  break;
                }
              }
              i = 0;
            }
            //printf("the counter on k, also known as the number of words needed is %d\n", k);
            if(k < argc-1){
                //printf("The counter is %d therefore I will print \n", k);
                printf("CENSORED");
                counter = 0;
              }
            else if(k>= argc-1){
              //printf("The counter is %d therefore I will print NOT CENSORED\n", k);
              printf("%s", word);
              counter = 0;
            }
            //memset(&word, '\0', 128);
            i=0;
            j=1;
            k=0;
            counter = 0;
            //420 blaze it
          }
        }


      if((c > 64 && c<91)||(c > 96 && c<123)||(c == 39)){
        //printf("The word array just ate a '%c' at index %d\n", c, counter  );

        word[counter] = c;

        //printf("The word array is now %s\n",word );
        counter++;
      }
      else{
        printf("%c", c);
      }
      d = c;
      c = getchar();
    }
    printf("%c", d);
  return 0;
}
