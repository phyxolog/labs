#include "stdafx.h"

using namespace std;

int get_gt_paired(int *arr, int len) {
	int data[2] = { 0, arr[0] };
	for (int i = 0; i < len; i++) {
		if (arr[i] % 2 == 0) {
			if (data[1] < arr[i]) {
				data[0] = i;
				data[i] = arr[i];
			}
		}
	}

	return data[0];
}

int main(int argc, char *argv[])
{
	int k;
	
	cout << "Enter k: ";
	cin >> k;

	int *arr = new int[k];

	for (int i = 0; i < k; i++) {
		cout << "Enter " << i + 1 << " number:";
		cin >> arr[i];
	}

	cout << "Gt paired: " << get_gt_paired(arr, k) << endl;

	return 0;
}

