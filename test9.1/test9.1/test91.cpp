#include "stdafx.h"

int random_number(int min, int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(mt);
}

void fill_array(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		arr[i] = random_number(101, 290);
	}
}

void print_array(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << "Element [" << i << "]: " << arr[i] << std::endl;
	}
}

int linear_search(int *arr, int length, int haystack) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == haystack) {
			return i;
		}
	}

	return -1;
}

void remove_element_from_array_by_index(int *arr, int *length, int index) {
	memmove(arr + index, arr + (index + 1), (*length - index - 1) * sizeof(int));
	*length = (*length - 1);
}

int main(int argc, char *argv[])
{
	int array_length = 12;
	int *array = new int[array_length];
	int i;

	fill_array(array, array_length);
	print_array(array, array_length);

	std::cout << "Input haystack for array: ";
	std::cin >> i;

	int find_index = linear_search(array, array_length, i);

	if (find_index == -1) {
		std::cout << "Value not found, sorry..." << std::endl;
		std::cout << "Array:" << std::endl;
		print_array(array, array_length);
	}
	else {
		std::cout << "Found, removing..." << std::endl;
		remove_element_from_array_by_index(array, &array_length, find_index);
		if (find_index > 0) {
			remove_element_from_array_by_index(array, &array_length, find_index - 1);
		}
		std::cout << "Array:" << std::endl;
		print_array(array, array_length);
	}

	return 0;
}

