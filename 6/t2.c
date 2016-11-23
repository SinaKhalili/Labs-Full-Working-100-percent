#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]

  The following lines are a valid JSON array:
  [
   100,
   200,
   300
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
  FILE * fs = fopen(filename, "w");
  if(!fs){
    return 1;
  }
  //fwrite(&(ia->len),sizeof(char),1,fs);
  int i = 0;
  fprintf(fs, "[");
  for(i=0; i<ia->len-1; i++){
    fprintf(fs, " %d,",ia->data[i]);
  }
  fprintf(fs, " %d", ia->data[i]);
  fprintf(fs, " ]");
  fclose(fs);
  return 0;

}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){
  intarr_t* ia = intarr_create(0);
  if(!ia){
    return NULL;
  }
  FILE * fs = fopen(filename, "r");
  if(!fs){
    return NULL;
  }

  intarr_resize(ia, 0);
  int j = 0;
  char number[16];
  memset(number, 0, 16*sizeof(char));
  int character = fgetc(fs);

  while(character != EOF){

    if((character >='0' && character <='9') || character == '-'){
        number[j] = character;
        number[j+1] = '\0';
    //printf("The numbers array is now:\n %s\n", number);
        j++;
    }
    else{
      if(number[0] != 0){
        int numberAdded = atoi(number);
      //  printf("I just added %d \n", numberAdded );
        intarr_push(ia, numberAdded);
        memset(number, 0, 16*sizeof(char));
        j = 0;
      }
    }
    character = fgetc(fs);
    //printf("New character is %c \n",character );
  }
    return ia;

}

  //ascii for numbers are: 48 to 57
