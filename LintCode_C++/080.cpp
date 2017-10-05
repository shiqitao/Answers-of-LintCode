class Solution {
public:
	/*
	* @param nums: A list of integers
	* @return: An integer denotes the middle number of the array
	*/
	int median(vector<int> &nums) {
		// write your code here
		int n = (nums.size() - 1) / 2;
		int low = 0, high = nums.size() - 1;
		int k = pivot(nums, low, high);
		while (k != n) {
			if (k < n) {
				low = k + 1;
				k = pivot(nums, low, high);
			}
			else {
				high = k - 1;
				k = pivot(nums, low, high);
			}
		}
		return nums[k];
	}
	int pivot(vector<int> &nums, int low, int high) {
		int key = nums[low];
		while (low < high) {
			while (low < high && nums[low] <= nums[high]) {
				high--;
			}
			swap(nums[low], nums[high]);
			while (low < high && nums[low] <= nums[high]) {
				low++;
			}
			swap(nums[low], nums[high]);
		}
		return low;
	}
};