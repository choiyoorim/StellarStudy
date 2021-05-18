#include <iostream>
using namespace std;


int * sorted = new int[1000000];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else sorted[k++] = list[j++];
	}
	if (i > mid) for (l = j; l <= right; l++) sorted[k++] = list[l];
	else for (l = i; l <= mid; l++) sorted[k++] = list[l];

	for (l = left; l <= right; l++) list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}

void print_array(int array[], int max_size) {
	for (int i = 0; i < max_size; i++) {
		cout << array[i] << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	int* num_array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num_array[i];
	}
	merge_sort(num_array, 0, n - 1);
	print_array(num_array, n);
	return 0;
}