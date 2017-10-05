class Solution {
public:
	/*
	* @param matrix: A lsit of lists of integers
	* @return:
	*/
	void setZeroes(vector<vector<int>> &matrix) {
		// write your code here
		int n = matrix.size();
		if (n == 0) {
			return;
		}
		int m = matrix[0].size();
		int *data = new int[n*m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				data[i*m + j] = matrix[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (data[i*m + j] == 0) {
					for (int k = 0; k < n; k++) {
						matrix[k][j] = 0;
					}
					for (int k = 0; k < m; k++) {
						matrix[i][k] = 0;
					}
				}
			}
		}
		delete[] data;
	}
};