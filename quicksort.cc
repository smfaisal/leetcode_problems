#include <iostream>

using namespace std;

int partition(int* array, int p, int q) {
	int tmp = array[q];
	int i=p-1;
	int j;
	int t;
	for (j=p; j<q; j++) {
		if (array[j] < tmp) {
			t = array[i+1];
			array[i+1] = array[j];
			array[j] = t;
			i++;
		}
	}
	t = array[q];
	array[q] = array[i+1];
	array[i+1] = t;
	return i+1;
}

void quicksort (int* array, int start, int end) {
	if (start < end) {
					int q = partition(array, start, end);
					cout << "Partition: " << q << "\n";
					quicksort(array, start, q-1);
					quicksort(array, q+1, end);
}
}

int main() {
	int array[] = {4, 3, 5, 12, 3, 123, 40};
	quicksort(array, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
	return 0;
}
