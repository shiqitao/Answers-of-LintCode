class Solution {
public:
	/*
	* @param A: A list of integers
	* @return: A boolean
	*/
	bool canJump(vector<int> &A) {
		// write your code here
		int len = A.size() - 1;
		canJump(A, len);
	}
	bool canJump(vector<int> &A, int n) {
		if (n <= A[0]) {
			return true;
		}
		for (int i = 0; i < n; i++) {
			if (n - i <= A[i]) {
				return canJump(A, i);
			}
		}
		return false;
	}
};