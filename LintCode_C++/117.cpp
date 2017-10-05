class Solution {
public:
	/*
	* @param A: A list of integers
	* @return: An integer
	*/
	int jump(vector<int> &A) {
		// write your code here
		int len = A.size() - 1;
		jump(A, len, 0);
	}
	int jump(vector<int> &A, int n, int count) {
		for (int i = 0; i < n; i++) {
			if (n - i <= A[i]) {
				count = jump(A, i, count) + 1;
				return count;
			}
		}
	}
};