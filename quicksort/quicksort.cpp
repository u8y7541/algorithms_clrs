#include <bits/stdc++.h>
using namespace std;

int partition(int* A, int n) {
	int i = 0;
	for (int j = 0; j<n-1; j++)
		if (A[j]<=A[n-1]) swap(A[i++], A[j]);
	swap(A[i], A[n-1]);
	return i;
}

void quicksort(int* A, int n) {
	if (n<2) return;
	int p = partition(A, n);
	quicksort(A, p);
	quicksort(A+p+1, n-p-1);
}

int main(void) {
	int A[8] = {8, 4, 7, 1, 3, 2, 5, 6};
	cout<<"Unsorted: ";
	for (int i = 0; i<8; i++) cout<<A[i]<<' '; cout<<endl;
	quicksort(A, 8);
	cout<<"Sorted: ";
	for (int i = 0; i<8; i++) cout<<A[i]<<' '; cout<<endl;

	return 0;
}
