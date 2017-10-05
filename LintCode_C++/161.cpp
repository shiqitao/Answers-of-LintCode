class Solution {
public:
	/*
	* @param matrix: a lists of integers
	* @return:
	*/
	void rotate(vector<vector<int>> &matrix) {
		// write your code here
		int n = matrix.size();
		if (n == 0) {
			return;
		}
		int *data = new int[n*n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i*n + j] = matrix[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[j][i] = data[(n - 1 - i)*n + j];
			}
		}
		delete[] data;
	}
};