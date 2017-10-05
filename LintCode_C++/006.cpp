class Solution {
public:
	/**
	* @param A and B: sorted integer array A and B.
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		vector <int>C;
		C.reserve(A.size() + B.size());
		int i, j;
		for (i = 0, j = 0; i < A.size() && j < B.size();) {
			if (A[i] < B[j]) {
				C.push_back(A[i]);
				i++;
			}
			else {
				C.push_back(B[j]);
				j++;
			}
		}
		for (int p = i; p < A.size(); p++)C.push_back(A[p]);
		for (int q = j; q < B.size(); q++)C.push_back(B[q]);
		return C;
	}
};