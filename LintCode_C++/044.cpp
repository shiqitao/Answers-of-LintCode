class Solution {
public:
	/**
	* @param nums: a list of integers
	* @return: A integer denote the sum of minimum subarray
	*/
	int minSubArray(vector<int> nums) {
		if (nums.size() == 0) return 0;
		int min = nums[0];
		int sum = min;
		for (int i = 1; i < nums.size(); i++) {
			if (min > 0 && nums[i] > 0) min = min <= nums[i] ? min : nums[i];
			else if (min > 0) {
				min = nums[i];
				sum = nums[i];
			}
			else {
				sum += nums[i];
				if (sum > 0) sum = 0;
				else if (sum < min) min = sum;
			}
		}
		return min;
	}
};
