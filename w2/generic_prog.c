#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/array_functions.h"
#include "../lib/sort/quickSort.h" 

void printInt(void const *ptr) {
  int value = *(int *)ptr;
  printf("%d ", value);
  return;
}

void printString(void const *ptr) {
  printf("%s \n", (char *)ptr);
  return;
}

void mapIntToInt(void *ptr_in, void *ptr_out) {
  int val_in = *(int *)ptr_in;
  *(int *)ptr_out = val_in + 10;
  return;
}

void mapIntToString(void *ptr_in, void *ptr_out) {
  char temp_str[50] = "number : ";
  int val_in = *(int *)ptr_in; 
  temp_str[ strlen(temp_str) ] = '0' + val_in;
  temp_str[ strlen(temp_str) + 1 ] = '\0';
  memcpy(ptr_out, temp_str, 50 * sizeof(char));
  return;
}

int isOddNum(void const *ptr) {
  int value = *(int *)ptr;
  return value % 2 == 1;
}

void addReducer(void *accumulator_ptr, void *curr_ptr) {
  int curr_val = *(int *)curr_ptr;
  *(int *)accumulator_ptr = *(int *)accumulator_ptr + curr_val;
  return;
}

int main() {
  
  int arr_1[] = { 1, 2, 3, 4, 5, 6, 7 };
  int nmemb_1 = len(arr_1);
  forEach(arr_1, nmemb_1, sizeof(int), printInt);
  printf("\n");
  
  int *arr_2 = map(arr_1, nmemb_1, sizeof(int), sizeof(int), mapIntToInt);
  int nmemb_2 = nmemb_1;
  forEach(arr_2, nmemb_2, sizeof(int), printInt);
  printf("\n");
   
  int nmemb_3 = 0;
  int *arr_3 = filter(arr_1, nmemb_1, &nmemb_3, sizeof(int), isOddNum);
  forEach(arr_3, nmemb_3, sizeof(int), printInt);
  printf("\n");
   
  int *sum = reduce(arr_1, nmemb_1, sizeof(int), sizeof(int), addReducer);
  printf("Sum = %d\n", *sum);
  printf("\n");
   
  char *arr_4 = map(arr_1, nmemb_1, sizeof(int), 50 * sizeof(char), mapIntToString);
  int nmemb_4 = nmemb_1;
  forEach(arr_4, nmemb_4, 50 * sizeof(char), printString);
  printf("\n");

  int *arr_5 = concat(arr_1, nmemb_1, arr_2, nmemb_2, sizeof(int));
  int nmemb_5 = nmemb_1 + nmemb_2;
  reverse(arr_5, nmemb_5, sizeof(int));
  forEach(arr_5, nmemb_5, sizeof(int), printInt);
  printf("\n");

  int *arr_6 = copy(arr_1, nmemb_1, sizeof(int));
  forEach(arr_6, nmemb_1, sizeof(int), printInt);
  printf("\n");
  return 0;
}
