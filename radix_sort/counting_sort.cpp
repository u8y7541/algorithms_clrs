#include <bits/stdc++.h>
using namespace std;

void counting_sort(int* A, int n, int k) {
	int C[k+1] = { 0 };
	for (int i = 0; i<n; i++) C[A[i]+1]++;
	for (int i = 1; i<k; i++) C[i] += C[i-1];
	for (int i = 0; i<k; i++) {
		A[k]
}
