#include "stdafx.h"

int random_number(int min, int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(mt);
}

void fill_array(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		arr[i] = random_number(-1000, 1000);
	}
}

void print_array(int *arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << "Element [" << i << "]: " << arr[i] << std::endl;
	}
}

int calculate_sum(int *arr, int length) {
	int sum = 0;
	bool all = arr[0] > 0;
	for (int i = 0; i < length; i++) {
		sum += all ? arr[i] :
			i % 2 != 0 ? arr[i] : 0;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int array_length = 11;
	int *array = new int[array_length];
	int i;

	fill_array(array, array_length);
	print_array(array, array_length);

	std::cout << "Array sum: " << calculate_sum(array, array_length) << std::endl;

	return 0;
}

