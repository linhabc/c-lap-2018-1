#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/array_function.h"

void printInt(void const *ptr) {
  int value = *(int *)ptr;
  printf("%d ", value);
  return;
}

void printString(void const *ptr) {
  printf("%s \n", (char *)ptr);
}

void mapIntToInt(void const *ptr_in, void const *ptr_out) {
  int val_in = *(int *)ptr_in;
  *(int *)ptr_out = val_in + 10;
  return;
}

void mapIntToString(void const *ptr_in, void const *ptr_out) {
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

void addReducer(void const *accumulator_ptr, void const *curr_ptr) {
  int curr_val = *(int *)curr_ptr;
  *(int *)accumulator_ptr = *(int *)accumulator_ptr + curr_val;
  return;
}

int main() {
  
  int arr_1[] = { 1, 2, 3, 4, 5, 6, 7 };
  int nmemb_1 = sizeof(arr_1) / sizeof(arr_1[0]);

  int *arr_2 = map(arr_1, nmemb_1, sizeof(int), sizeof(int), mapIntToInt);
  int nmemb_2 = nmemb_1;
 
  int nmemb_3 = 0;
  int *arr_3 = filter(arr_1, nmemb_1, &nmemb_3, sizeof(int), isOddNum);
  
  forEach(arr_3, nmemb_3, sizeof(int), printInt);
  printf("\n");
  forEach(arr_1, nmemb_1, sizeof(int), printInt);
  printf("\n");
  forEach(arr_2, nmemb_2, sizeof(int), printInt);
  printf("\n");
  
  int *sum = reduce(arr_1, nmemb_1, sizeof(int), sizeof(int), addReducer);
  printf("Sum = %d\n", *sum);

  char *arr_4 =  map(arr_1, nmemb_1, sizeof(int), 50 * sizeof(char), mapIntToString);
  int nmemb_4 = nmemb_1;
  forEach(arr_4, nmemb_4, 50 * sizeof(char), printString);
  return 0;
}
