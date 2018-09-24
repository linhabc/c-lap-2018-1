#ifndef __ARRAY_FUNCTION
#define __ARRAY_FUNCTION

#include <stdlib.h>
#include <string.h>

typedef void (* ToDo)(void const *);
typedef void (* MapElement)(void const *, void const *); 
 typedef int (* Filter)(void const *);
 typedef void (* Reducer)(void const *, void const *);

 void forEach(void *arr, int nmemb, int size, ToDo todo) {
   for (int i = 0; i < nmemb; i++) {
     char *ptr = (char *)arr + i * size;
     todo(ptr);
   }
   return;
 }

 void *map(void *arr, int nmemb, int inSize, int outSize, MapElement mapElement) {
   void *outArr = malloc( nmemb * outSize);
   for (int i = 0; i < nmemb; i++) {
     char *ptr_in = (char *)arr + i * inSize;
     char *ptr_out = (char *)outArr + i * outSize;
     mapElement(ptr_in, ptr_out);
   }
   return outArr;
 }

 void *filter(void *arr, int in_nmemb, int *out_nmemb, int size, Filter test) {
   void *outArr = malloc(in_nmemb * size);
   int temp_out_nmemb = 0;
   for (int i = 0; i < in_nmemb; i++) {
     char *ptr_i_in = (char *)arr + i * size;
     char *ptr_i_out = (char *)outArr + temp_out_nmemb * size;
     if ( test(ptr_i_in) ) {
       memcpy(ptr_i_out, ptr_i_in, size);
       temp_out_nmemb ++;
     }
   }
   *out_nmemb = temp_out_nmemb;
   return outArr;
} 

void *reduce(void *arr_in, int nmemb, int size_in, int size_out, Reducer reducer) {
   void *ret_ptr = malloc(size_out);
   for (int i = 0; i < nmemb; i++) {
     char *ptr_i = (char *)arr_in + i * size_in;
     reducer(ret_ptr, ptr_i);
   }
   return ret_ptr;
}

#endif
