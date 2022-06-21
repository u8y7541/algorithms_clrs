#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<vector<int> >& A, int k, int digit) {
	int n = A.size(), d = A[0].size();
	int B[n] = { 0 };
	int C[k] = { 0 };
	for (int i = 0; i<n; i++) C[A[i][digit]]++;
	for (int i = 1; i<k; i++) C[i] += C[i-1];
	for (int i = n-1; i>=0; i--) B[C[A[i][digit]]-- - 1] = i;
	bool visited[n] = { 0 };
	
	for (int i = 0; i<n; i++) {
		if (visited[i]) continue;
		int j = i;
		vector<int> temp = A[i];
		while (!visited[B[j]]) {
			A[j] = A[B[j]];
			visited[j] = true;
			j = B[j];
		}
		A[j] = temp;
	}
}

void radix_sort(vector<vector<int> >& A, int k) {
	for (int i = A[0].size(); i>=0; i--) counting_sort(A, k, i);
}

int main(void) {
	vector<vector<int> > A = {{3,2,9},{4,5,7},{6,5,7},{8,3,9},{4,3,6},{7,2,0},{3,5,5}};
	cout<<"Unsorted: ";
	for (int i = 0; i<7; i++) cout<<A[i][0]<<A[i][1]<<A[i][2]<<' ';
	cout<<endl;
	radix_sort(A, 10);
	cout<<"Sorted: ";
	for (int i = 0; i<7; i++) cout<<A[i][0]<<A[i][1]<<A[i][2]<<' ';
	cout<<endl;

	return 0;
}

