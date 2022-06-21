#include <bits/stdc++.h>
using namespace std;

// Arguments: array (cumulative, not change), begin index, end index
// Return value: begin and end subarray indices, index of min, index of max
vector<int> maxsub(int* A, int x, int y) {
	vector<int> ans;
	// Base case
	if (y-x == 1) {
		for (int i = 0; i<4; i++) ans.push_back(x);
		return ans;
	}

	vector<int> first = maxsub(A, x, (x+y)/2);
	vector<int> second = maxsub(A, (x+y)/2, y);
	// Combine maxsub answer for first and second half
	if (A[first[1]] - A[first[0]] >= A[second[1]] - A[second[0]] &&
		A[first[1]] - A[first[0]] >= A[second[3]] - A[first[2]])
		{ ans.push_back(first[0]); ans.push_back(first[1]); }
	else if (A[second[1]] - A[second[0]] >= A[first[1]] - A[first[0]] &&
		A[second[1]] - A[second[0]] >= A[second[3]] - A[first[2]])
		{ ans.push_back(second[0]); ans.push_back(second[1]); }
	else
		{ ans.push_back(first[2]); ans.push_back(second[3]); }

	// Combine mins and maxes for first and second half
	if (A[first[2]] < A[second[2]]) ans.push_back(first[2]);
	else ans.push_back(second[2]);
	if (A[first[3]] > A[second[3]]) ans.push_back(first[3]);
	else ans.push_back(second[3]);

	return ans;
}

int main(void) {
	int A[17] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	auto ans = maxsub(A, 0, 17);
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<endl;
	
	return 0;
}

