#include <bits/stdc++.h>
using namespace std;

int insertion_sort_median(int* A, int n) {
	for (int i = 1; i<n; i++) {
		int x = A[i];
		int j = i-1;
		for (; j >= 0 && A[j]>x; j--) A[j+1] = A[j];
		A[j+1] = x;
	}
	return A[(n-1)/2]; // Smaller median
}

int partition(int* A, int n, int i) {
	swap(A[i], A[n-1]);
	i = 0;
	for (int j = 0; j<n-1; j++)
		if (A[j]<=A[n-1]) swap(A[i++], A[j]);
	swap(A[i], A[n-1]);
	return i;
}

int select(int* A, int n, int i) {
	if (n == 1) return A[0];
	int B[(n+4)/5] = { 0 }; // Round up
	for (int j = 0; j<n; j+=5)
		B[j/5] = insertion_sort_median(A+j, min(5, n-j));
	int x = select(B, (n+4)/5, (n-1)/10);
	int k = 0;
	for (; A[k] != x; k++);
	k = partition(A, n, k);
	if (i == k) return x;
	if (i < k) return select(A, k, i);
	return select(A+k+1, n-k-1, i-k-1);
}

int main(void) {
	int A[10] = {3,2,9,0,7,5,4,8,6,1};
	cout<<"Original array: ";
	for (int i = 0; i<10; i++) cout<<A[i]; cout<<endl;
	cout<<"Order statistics: ";
	for (int i = 0; i<10; i++) cout<<select(A, 10, i); cout<<endl;
}
