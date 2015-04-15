#include <iostream>

using namespace std;

void max_heapify(int* array, int ind, int heap_len) {
	int largest;
	int left = ind*2+1;
	int right = ind*2+2;
	if (left < heap_len && array[left] > array[ind]) {
		largest = left;
	} else {
		largest = ind;
	}
	if (right < heap_len && array[right] > array[largest]) {
		largest = right;
	}
	int tmp;
	if (ind != largest) {
		tmp = array[ind];
		array[ind] = array[largest];
		array[largest] = tmp;
		max_heapify(array, largest, heap_len);
	}
}

void build_max_heap(int* array, int len) {
	for (int i = len/2 - 1; i >=0; i--) {
		max_heapify(array, i, len);
	}
}

void heap_sort(int* array, int len) {
	int heap_len = len;
	int tmp;
	build_max_heap(array, len);
	for (int i = len-1; i >0; i--) {
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		heap_len--;
		max_heapify(array, 0, heap_len);
	}
}

int main() {
	int array[] = {4, 3, 5, 12, 3, 123, 40};
	heap_sort(array, 7);
	for (int i = 0; i < 7; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
	return 0;
}
