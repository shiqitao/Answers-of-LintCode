class Solution {
public:
	/*
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		// write your code here
		int len = matrix.size();
		if (len == 0) {
			return false;
		}
		int low = 0, high = len - 1, mid;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] > target) high = mid;
			else low = mid;
		}
		int cur;
		if (matrix[low][0] > target) return 0;
		else if (matrix[high][0] <= target) cur = high;
		else cur = low;
		int sum = 0;
		for (int i = 0; i <= cur; i++) {
			sum += searchMatrix(matrix[i], target);
		}
		return sum;
	}
	bool searchMatrix(vector<int> &matrix, int target) {
		int len = matrix.size();
		int low = 0, high = len - 1, mid;
		while (low + 1 < high) {
			mid = (low + high) / 2;
			if (matrix[mid] == target) return true;
			else if (matrix[mid] > target) high = mid;
			else low = mid;
		}
		if (matrix[low] == target || matrix[high] == target) return true;
		return false;
	}
};