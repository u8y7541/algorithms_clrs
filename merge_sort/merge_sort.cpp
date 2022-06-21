#include <bits/stdc++.h>
using namespace std;

/*
 * Basically, there are two scenarios where A[i] is selected over A[j]:
 * 1. A[i] < A[j] && i<n/2, meaning A[i] is smaller and is not infinity
 * 2. j>=n, meaning A[j] is infinity and should not be chosen
 * These are the only two scenarios where A[i] should be selected. Also,
 * the loop's condition could be i<n/2 || j<n, but it always runs exactly
 * n times, so k<n is more efficient.
 */
void merge(int* A, int n) {
	int i = 0, j = n/2, ans[n] = { 0 };
	for (int k = 0; k<n; k++)
		ans[k] = A[ ((A[i] < A[j] && i<n/2) || j>=n) ? i++ : j++ ];
	memcpy(A, ans, n*sizeof(int));
}

void mergesort(int* A, int n) {
	if (n == 1) return;
	mergesort(A, n/2);
	mergesort(A+n/2, (n+1)/2);
	merge(A, n);
}

int main(void) {
	int x[9] = {5, 1, 4, 3, 2, 6, 8, 100, 54};
	mergesort(x, 9);
	for (int i = 0; i<9; i++) cout<<x[i]<<' ';
	cout<<endl;
	return 0;
}
