class Solution {
public:
	/*
	* @param A: an integer array
	* @return:
	*/
	void sortIntegers(vector<int> &A) {
		// write your code here
		int len = A.size();
		for (int i = 0; i < len; i++) {
			for (int j = len - 1; j > i; j--) {
				if (A[j] < A[j - 1]) {
					swap(A[j], A[j - 1]);
				}
			}
		}
	}
};