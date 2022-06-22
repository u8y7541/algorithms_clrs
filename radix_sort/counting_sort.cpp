#include <bits/stdc++.h>
using namespace std;

// Unstable sort
void counting_sort(int* A, int n, int k) {
	int C[k] = { 0 };
	int i = 0;
	for (; i<n; i++) C[A[i]]++;
	i = 0;
	for (int j = 0; j<k; j++) for (int l = 0; l<C[j]; l++) A[i++] = j;
}

int main(void) {
	int A[10] = {5,0,4,0,0,2,3,3,1,4};
	cout<<"Unsorted: ";
	for (int i = 0; i<10; i++) cout<<A[i]<<' '; cout<<endl;
	counting_sort(A, 10, 6);
	cout<<"Sorted: ";
	for (int i = 0; i<10; i++) cout<<A[i]<<' '; cout<<endl;

	return 0;
}
