class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the value of maximum difference between two
	*          Subarrays
	*/
	int maxDiffSubArrays(vector<int> nums) {
		if (nums.size() == 0 || nums.size() == 1) return 0;
		int *maxLeft = new int[nums.size() - 1];
		int *maxRight = new int[nums.size() - 1];
		int *minLeft = new int[nums.size() - 1];
		int *minRight = new int[nums.size() - 1];
		maxLeft[0] = nums[0];
		minLeft[0] = nums[0];
		maxRight[nums.size() - 2] = nums[nums.size() - 1];
		minRight[nums.size() - 2] = nums[nums.size() - 1];
		int sumMaxLeft = nums[0];
		int sumMaxRight = nums[nums.size() - 1];
		int sumMinLeft = nums[0];
		int sumMinRight = nums[nums.size() - 1];
		for (int i = 1; i < nums.size() - 1; i++) {
			maxLeft[i] = maxLeft[i - 1];
			maxRight[nums.size() - 2 - i] = maxRight[nums.size() - 1 - i];
			minLeft[i] = minLeft[i - 1];
			minRight[nums.size() - 2 - i] = minRight[nums.size() - 1 - i];
			if (maxLeft[i] < 0 && nums[i] < 0) maxLeft[i] = maxLeft[i] >= nums[i] ? maxLeft[i] : nums[i];
			else if (maxLeft[i] < 0) {
				maxLeft[i] = nums[i];
				sumMaxLeft = nums[i];
			}
			else {
				sumMaxLeft += nums[i];
				if (sumMaxLeft < 0) sumMaxLeft = 0;
				else if (sumMaxLeft > maxLeft[i]) maxLeft[i] = sumMaxLeft;
			}
			if (maxRight[nums.size() - 2 - i] < 0 && nums[nums.size() - 1 - i] < 0) maxRight[nums.size() - 2 - i] = maxRight[nums.size() - 2 - i] >= nums[nums.size() - 1 - i] ? maxRight[nums.size() - 2 - i] : nums[nums.size() - 1 - i];
			else if (maxRight[nums.size() - 2 - i] < 0) {
				maxRight[nums.size() - 2 - i] = nums[nums.size() - 1 - i];
				sumMaxRight = nums[nums.size() - 1 - i];
			}
			else {
				sumMaxRight += nums[nums.size() - 1 - i];
				if (sumMaxRight < 0) sumMaxRight = 0;
				else if (sumMaxRight > maxRight[nums.size() - 2 - i]) maxRight[nums.size() - 2 - i] = sumMaxRight;
			}
			if (minLeft[i] > 0 && nums[i] > 0) minLeft[i] = minLeft[i] <= nums[i] ? minLeft[i] : nums[i];
			else if (minLeft[i] > 0) {
				minLeft[i] = nums[i];
				sumMinLeft = nums[i];
			}
			else {
				sumMinLeft += nums[i];
				if (sumMinLeft > 0) sumMinLeft = 0;
				else if (sumMinLeft < minLeft[i]) minLeft[i] = sumMinLeft;
			}
			if (minRight[nums.size() - 2 - i] > 0 && nums[nums.size() - 1 - i] > 0) minRight[nums.size() - 2 - i] = minRight[nums.size() - 2 - i] <= nums[nums.size() - 1 - i] ? minRight[nums.size() - 2 - i] : nums[nums.size() - 1 - i];
			else if (minRight[nums.size() - 2 - i] > 0) {
				minRight[nums.size() - 2 - i] = nums[nums.size() - 1 - i];
				sumMinRight = nums[nums.size() - 1 - i];
			}
			else {
				sumMinRight += nums[nums.size() - 1 - i];
				if (sumMinRight > 0) sumMinRight = 0;
				else if (sumMinRight < minRight[nums.size() - 2 - i]) minRight[nums.size() - 2 - i] = sumMinRight;
			}
		}
		int max = INT_MIN;
		for (int i = 0; i < nums.size() - 1; i++) {
			max = max >= maxLeft[i] - minRight[i] ? max : maxLeft[i] - minRight[i];
			max = max >= maxRight[i] - minLeft[i] ? max : maxRight[i] - minLeft[i];
		}
		delete[] maxLeft;
		delete[] maxRight;
		delete[] minLeft;
		delete[] minRight;
		return max;
	}
};
