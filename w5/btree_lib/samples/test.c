#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./phonebook.h"


int main() {

	Phonebook *phonebook = new_phonebook();

	add_entry_to_phonebook(phonebook, "Thanh", "1111111111");
	add_entry_to_phonebook(phonebook, "Tung", "222222222");
	add_entry_to_phonebook(phonebook, "Phung", "333333333");
	add_entry_to_phonebook(phonebook, "Ngoc", "444444444");
	add_entry_to_phonebook(phonebook, "Chuong", "55555555");
	add_entry_to_phonebook(phonebook, "Dung", "666666666");

	update(phonebook, "Thanh", "AAAAAAAA");
	delete_by_name(phonebook, "Thanh");
	char *phone_number = get_phone_number_by_name(phonebook, "Thanh");
	
	printf("Search phone number: %s\n", phone_number);
	return 0;
}
