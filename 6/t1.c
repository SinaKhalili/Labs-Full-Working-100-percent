#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){

  if(!ia){
    return 1;
  }
  if(!(ia->data)){
    return 1;
  }

  FILE* fs = fopen(filename, "w");

  if(ia->len == 0){
    fclose(fs);
    return 0;
  }

  fs = fopen(filename, "w");

  if(!fs){
    return 1;
  }

  size_t size = ia->len;

  fwrite(&(ia->len),sizeof(int),1,fs);

  int as = fwrite(ia->data, sizeof(int), size, fs);

    if( as == 0){
      return 1;
    }
    fclose(fs);

    return 0;

}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){

	//size_t bignews;

	intarr_t* Hello = malloc(sizeof(intarr_t));


	FILE * fs = fopen(filename, "r");

  fread(&(Hello->len),sizeof(unsigned int),1,fs);

  Hello->data = malloc(sizeof(int)*Hello->len);

	//int as = fread(Hello->data, sizeof(int), , fs);

	int i = 0;

	while(!feof(fs)){
		fread(Hello->data+i, sizeof(int), 1, fs);
		i++;
	}

	return Hello;


}


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
int intarr_save_json( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename );
