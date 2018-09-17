#ifndef __ARRAY_FUNCTION
#define __ARRAY_FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void (* ToDo)(void const *);
typedef void (* MapElement)(void *, void *);
typedef int (* Filter)(void const *);
typedef void ( * Reducer)(void *, void *);

void forEach(void *arr, int nmemb, int size, ToDo todo) {

	char *ptr_i = NULL; 
	for (int i = 0; i < nmemb; i++) {
		ptr_i = (char *)arr + i * size;
		todo(ptr_i);
	}
	printf("\n");
	return;
}

void *map(void *arr_in, int nmemb, int size_in, int size_out, MapElement map_element) {
	void *arr_out = malloc(nmemb * size_out);
	char *ptr_i_in = NULL;
	char *ptr_i_out = NULL;
	
	for (int i = 0; i < nmemb; i++) {
		ptr_i_in = (char *)arr_in + i * size_in;
		ptr_i_out = (char *)arr_out + i * size_out;
		map_element(ptr_i_in, ptr_i_out);
	}
	return arr_out;
}

void *filter(void *arr_in, int nmemb_in, int *nmemb_out, int size, Filter test) {
	char *arr_out = malloc(nmemb_in * size);
	int temp_nmemb_out = 0;
	char *ptr_i_in = NULL;
	char *ptr_i_out = NULL;
	for (int i = 0; i < nmemb_in; i++) {
		ptr_i_in = (char *)arr_in + i * size;
		if (test(ptr_i_in)) {
			ptr_i_out = (char *)arr_out + temp_nmemb_out * size;
			memcpy(ptr_i_out, ptr_i_in, size);
			temp_nmemb_out ++;
		}
	}
	*nmemb_out = temp_nmemb_out;
	return arr_out;
}

void *reduce(void *arr_in, int nmemb, int size_in, int size_out, Reducer reducer) {
	char *ret_ptr = malloc(size_out);
	char *ptr_i_in = NULL;
	for (int i = 0; i < nmemb; i++) {
		ptr_i_in = (char *)arr_in + i * size_in;
		reducer(ret_ptr, ptr_i_in);
	}
	return ret_ptr;
}

#endif
