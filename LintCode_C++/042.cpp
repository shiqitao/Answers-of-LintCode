class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer denotes the sum of max two non-overlapping subarrays
	*/
	int maxTwoSubArrays(vector<int> nums) {
		if (nums.size() == 0 || nums.size() == 1) return 0;
		int *maxLeft = new int[nums.size() - 1];
		int *maxRight = new int[nums.size() - 1];
		maxLeft[0] = nums[0];
		maxRight[nums.size() - 2] = nums[nums.size() - 1];
		int sumLeft = nums[0];
		int sumRight = nums[nums.size() - 1];
		for (int i = 1; i < nums.size() - 1; i++) {
			maxLeft[i] = maxLeft[i - 1];
			maxRight[nums.size() - 2 - i] = maxRight[nums.size() - 1 - i];
			if (maxLeft[i] < 0 && nums[i] < 0) maxLeft[i] = maxLeft[i] >= nums[i] ? maxLeft[i] : nums[i];
			else if (maxLeft[i] < 0) {
				maxLeft[i] = nums[i];
				sumLeft = nums[i];
			}
			else {
				sumLeft += nums[i];
				if (sumLeft < 0) sumLeft = 0;
				else if (sumLeft > maxLeft[i]) maxLeft[i] = sumLeft;
			}
			if (maxRight[nums.size() - 2 - i] < 0 && nums[nums.size() - 1 - i] < 0) maxRight[nums.size() - 2 - i] = maxRight[nums.size() - 2 - i] >= nums[nums.size() - 1 - i] ? maxRight[nums.size() - 2 - i] : nums[nums.size() - 1 - i];
			else if (maxRight[nums.size() - 2 - i] < 0) {
				maxRight[nums.size() - 2 - i] = nums[nums.size() - 1 - i];
				sumRight = nums[nums.size() - 1 - i];
			}
			else {
				sumRight += nums[nums.size() - 1 - i];
				if (sumRight < 0) sumRight = 0;
				else if (sumRight > maxRight[nums.size() - 2 - i]) maxRight[nums.size() - 2 - i] = sumRight;
			}
		}
		int max = INT_MIN;
		for (int i = 0; i < nums.size() - 1; i++) max = max >= maxLeft[i] + maxRight[i] ? max : maxLeft[i] + maxRight[i];
		delete[] maxLeft;
		delete[] maxRight;
		return max;
	}
};
