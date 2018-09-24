#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    (Phone_entry *)malloc(DEFAULT_Size * sizeof(Phone_entry));
  
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
  Phone_entry *phone_entries = phone_book->phone_entries; 
  phone_entries[nmemb] = new_phone_entry;
  phone_book->nmemb ++;
  return;
}

void overwrite_phone_entry(Phone_entry *target_phone_entry, char *new_phone_number) {
  target_phone_entry->phone_number = new_phone_number;
  return;
}

void append_or_overwrite(Phone_entry new_phone_entry, Phone_book phone_book) {
  char *search_name = new_phone_entry->name;
  Phone_entry *phone_entry = get_phone_entry_by_name(phone_book, search_name);
  if (phone_entry == NULL) {
    append(phone_book, new_phone_entry);
  } else {
    char new_phone_number = new_phone_entry->phone_number;
    overwrite_phone_entry(phone_entry, new_phone_number);
  }
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
    modify_phone_number(search_phone_entry, new_phone_number);
  }
  return;
}

int main() {
  
  return 0;
}
