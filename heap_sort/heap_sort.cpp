#include <bits/stdc++.h>
using namespace std;

// Iterative implementation
void max_heapify(int* A, int n, int i) {
	while (true) {
		int l = 2*i+1, r = 2*i+2;
		int largest = i;
		if (l<n && A[l] > A[i]) largest = l;
		if (r<n && A[r] > A[largest]) largest = r;
		if (largest == i) break;

		A[i] ^= A[largest]; A[largest] ^= A[i]; A[i] ^= A[largest];
		i = largest;
	}
}

void build_max_heap(int* A, int n) {
	for (int i = n/2-1; i>=0; i--) max_heapify(A, n, i);
}

void heapsort(int* A, int n) {
	build_max_heap(A, n);
	// Print out heap
	cout<<"Heap: ";
	for (int i = 0; i<n; i++) cout<<A[i]<<' '; cout<<endl;

	for (int i = n-1; i>0; i--) {
		A[0] ^= A[i]; A[i] ^= A[0]; A[0] ^= A[i];
		max_heapify(A,i,0);
	}
}

int main(void) {
	int A[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int N = 10;
	// Print unsorted
	cout<<"Unsorted: ";
	for (int i = 0; i<N; i++) cout<<A[i]<<' '; cout<<endl;
	heapsort(A, N);
	// Print sorted
	cout<<"Sorted: ";
	for (int i = 0; i<N; i++) cout<<A[i]<<' '; cout<<endl;

	return 0;
}
