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

int binary_search(int *arr, int start, int end, const int key)
{
	if (start > end) {
		return -1;
	}

	const int middle = start + ((end - start) / 2);

	if (arr[middle] == key) {
		return middle;
	} else if (arr[middle] > key) {
		return binary_search(arr, start, middle - 1, key);
	}

	return binary_search(arr, middle + 1, end, key);
}

void insert_element_to_array_by_index(int *arr, int *length, int value, int index) {
	int *new_array = new int[*length + 1];
	for (int i = 0; i < *length + 1; i++) {
		if (i == index) {
			new_array[i] = value;
		} else if (i < index) {
			new_array[i] = arr[i];
		} else if (i > index) {
			new_array[i] = arr[i - 1];
		}
	}
	*length = (*length + 1);
	memcpy(arr, new_array, *length * sizeof(int));
	delete[] new_array;
}

int main(int argc, char *argv[])
{
	int array_length = 15;
	int *array = new int[array_length];
	int i;

	fill_array(array, array_length);
	std::sort(array, array + array_length);
	print_array(array, array_length);

	std::cout << "Input haystack for array: ";
	std::cin >> i;

	int find_index = binary_search(array, 0, array_length, i);

	if (find_index == -1) {
		std::cout << "Value not found, inserting to index=3..." << std::endl;
		insert_element_to_array_by_index(array, &array_length, i, 3);
		print_array(array, array_length);
	} else {
		std::cout << "Value found, all ok..." << std::endl;
	}

	return 0;
}

