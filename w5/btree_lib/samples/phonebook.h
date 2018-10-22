#ifndef __PHONEBOOK_H_
#define __PHONEBOOK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "btree.h"

#define MAX_SIZE_PHONE_NUMBER 50

typedef struct {
	int nmemb;
	BTA *tree_root;
} Phonebook;

Phonebook *new_phonebook() {
	Phonebook *ret = (Phonebook *)malloc(sizeof(Phonebook));
	btinit();
	BTA *tree_root = btcrt("phonebook_tree.bt", 0, FALSE);
	ret->nmemb = 0;
	ret->tree_root = tree_root;
	return ret;
}

void add_entry_to_phonebook(Phonebook *phonebook,char *name, char *phone_number) {
	BTA *tree_root = phonebook->tree_root;
	char *key = (char *)malloc(MAX_SIZE_PHONE_NUMBER * sizeof(char));
	strcpy(key, name);
	int isOk = btins(tree_root, key, phone_number, MAX_SIZE_PHONE_NUMBER);
	if (isOk != 0) {
		printf("add entry to phonebook error!\n");
		return;
	}
	phonebook->nmemb ++;
	return;
}

char *get_phone_number_by_name(Phonebook *phonebook, char *name) {
	BTA *tree = phonebook->tree_root; 
	char *ret;
	int ret_actual_size;
	int isOk = btsel(tree, name, ret, MAX_SIZE_PHONE_NUMBER, &ret_actual_size);
	if (isOk != 0) {
		printf("get phone number error!\n");
		exit(1);
	}
	printf("actual size : %d\n", ret_actual_size);
	return ret;
}

void update(Phonebook *phonebook, char *name, char *new_phone_number) {
	BTA *tree = phonebook->tree_root;
	char *buff = (char *)malloc(MAX_SIZE_PHONE_NUMBER * sizeof(char));
	strcpy(buff, new_phone_number);
	int isOk = btupd(tree, name, buff, MAX_SIZE_PHONE_NUMBER);
	if (isOk != 0) {
		printf("update error!");
		return;
	}
	return;
}

void delete_by_name(Phonebook *phonebook, char *name) {
	BTA *tree = phonebook->tree_root;
	int isOK = btdel(tree, name);
	if (isOK != 0) {
		printf("Delete error!\n");
		return;
	}
	return;
}

void phonebook_close(Phonebook *phonebook) {
	btcls(phonebook->tree_root);
	return;
}
#endif


