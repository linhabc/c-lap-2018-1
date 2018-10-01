#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/ADT/symbol_table.h"

<<<<<<< HEAD
#define DEFAULT_SIZE 10

typedef struct {
  char *name;
  char *phone_number;
} Phone_entry;

typedef struct {
  Phone_entry *phone_entries;
  int nmemb;
  int size;
} Phone_book;

Phone_book *new_phone_book() {
  Phone_book *ret = (Phone_book *)malloc(sizeof(Phone_book));
  Phone_entry *phone_entries = 
    (Phone_entry *)malloc(DEFAULT_SIZE * sizeof(Phone_entry));
  
  ret->phone_entries = phone_entries;
  ret->nmemb = 0;
  ret->size = DEFAULT_SIZE;
  return ret;
}

Phone_entry *get_phone_entry_by_name(Phone_book *phone->book, char *search_name) {
  int nmemb = phone_book->nmemb;
  Phone_entry *phone_entries = phone_book->phone_entries;
  for (int i = 0; i < nmemb; i++) {
    if (strcmp(phone_entries[i]->name, search_name) == 0) {
      return phone_entries + i;
    }
  }

  return NULL;
}

char *get_phone_number_by_name(Phone_book phone_book, char *search_name) {
  Phone_entry *phone_entry = get_phone_entry_by_name(phone_book, search_name);
  if (phone_entry != NULL) {
    return phone_entry->phone_number;
  }
  return NULL;
}

void append(Phone_book phone_book, phone_entry new_phone_entry) {
  int nmemb = phone_book->nmemb;
  int size = phone_book->size;
  Phone_entry *phone_entries = phone_book->phone_entries;

  if (nmemb == size) {
    double_phone_book_size(phone_book);
  } 

  phone_entries[nmemb] = new_phone_entry;
  phone_book->nmemb ++;
  return;
}

void modify_phone_entry(Phone_entry *target_phone_entry, char *new_phone_number) {
  target_phone_entry->phone_number = new_phone_number;
  return;
}

void add(Phone_book *phone_book, Phone_entry new_phone_entry) {
  char *search_name = new_phone_entry->name;
  Phone_entry *search_phone_entry = 
    get_phone_entry_by_name(phone_book, search->name);
  
  if (search_phone_entry == NULL) {
    append(phone_book, new_phone_entry);
  } else {
    char *new_phone_number = new_phone_entry->phone_number;
    modify_phone_entry(search_phone_entry, new_phone_number);
  }
  return;
=======
Entry *new_phone_book_entry(void *key, void *value) {
	Entry *new_entry = (Entry *)malloc(sizeof(Entry));
	new_entry->key = key;
	new_entry->value = value;
	return new_entry;
}

int key_cmp(void *entry_key, void *search_key) {
	return strcmp((char *)entry_key, (char *)search_key);
>>>>>>> 1b9aad6e55ab92d6f9ae8ffec0462f241a5d529e
}

int main() {

	Symbol_table *phone_book =
		new_symbol_table(new_phone_book_entry, key_cmp);

	add(phone_book, "Thanh", "111");
	add(phone_book, "Dung", "222");
	add(phone_book, "Chuong", "333");
	add(phone_book, "Tung", "444");
	add(phone_book, "Ngoc", "555");
	add(phone_book, "Phung", "666");
	add(phone_book, "Vinh", "777");
	add(phone_book, "Long", "888");
	add(phone_book, "Quang", "999");
	add(phone_book, "Hieu", "101010");
	add(phone_book, "Binh", "111111");
	

	Entry *phone_book_entry = get_entry_by_key(phone_book, "Binh");
	printf("pointer: %p \n", phone_book_entry);
	printf("value : %s \n", (char *)phone_book_entry->value);
	return 0;
}
