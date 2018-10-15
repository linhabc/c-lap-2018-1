#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./jrb.h"

typedef struct {
	char name[50];
	char phone_number[30];
} Phonebook_entry;

int cmp_name(Jval a, Jval b) {
	return strcmp(jval_s(a), jval_s(b));
}

Phonebook_entry *read_data_from_file(char *fn) {
	FILE *fp = fopen(fn, "r");
	if (fp == NULL) {
		printf("\nCan not open file! \n");
		return NULL;
	}
	char buff[1000];
	int nmemb = 0;
	fscanf(fp, "%d", &nmemb);
 
	Phonebook_entry *list = (Phonebook_entry)malloc(nmemb * sizeof(Phonebook_entry));
	for (int i = 0; i < nmemb; i++) {
		fgets(buff, 1000, fp);
		sscanf(buff, "%s %s", list[i].name, list[i].phone_number);
	}

	return list
}

void print_phonebook(Phonebook_entry *list, int nmemb) {
	for (int i = 0; i < nmemb; i++) {
		printf("%s %s \n", list[i].name, list[i].phone_number);
	}
	return;
}

int main() {

	JRB phonebook = make_jrb();
	Phonebook_entry *list = read_data_from_file("phonebook.txt");
	print_phonebook(list, 6);
	return 0;
}

