class Solution {
public:
	/*
	* @param matrix: matrix, a list of lists of integers
	* @param target: An integer
	* @return: a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// write your code here
		int len = matrix.size();
		if (len == 0) {
			return false;
		}
		int low = 0, high = len - 1, mid;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] == target) return true;
			else if (matrix[mid][0] > target) high = mid;
			else low = mid;
		}
		int cur;
		if (matrix[low][0] == target || matrix[high][0] == target) return true;
		if (matrix[low][0] > target) return false;
		else if (matrix[high][0] < target) cur = high;
		else cur = low;
		len = matrix[cur].size();
		low = 0; high = len - 1;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			if (matrix[cur][mid] == target) return true;
			else if (matrix[cur][mid] > target) high = mid;
			else low = mid;
		}
		if (matrix[cur][low] == target || matrix[cur][high] == target) return true;
		return false;
	}
};