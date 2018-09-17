#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/array_function.h"

void printOne(void const *ptr) {
  int value = *(int *)ptr;
  printf("%d ", value);
  return;
}

void mapElement(void const *ptr_in, void const *ptr_out) {
  int val_in = *(int *)ptr_in;
  *(int *)ptr_out = val_in + 10;
  return;
}

int test(void const *ptr) {
  int value = *(int *)ptr;
  return value % 2 == 1;
}

int main() {
  
  int arr_1[] = { 1, 2, 3, 4, 5, 6, 7 };
  int nmemb_1 = sizeof(arr_1) / sizeof(arr_1[0]);

  int *arr_2 = map(arr_1, nmemb_1, sizeof(int), sizeof(int), mapElement);
  
  int nmemb_3 = 0;
  int *arr_3 = filter(arr_1, nmemb_1, &nmemb_3, sizeof(int), test);
  forEach(arr_3, nmemb_3, sizeof(int), printOne);
  printf("\n");
  forEach(arr_1, nmemb_1, sizeof(int), printOne);
  printf("\n");
  forEach(arr_2, nmemb_1, sizeof(int), printOne);
  printf("\n");
  
  return 0;
}
