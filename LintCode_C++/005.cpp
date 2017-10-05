class Solution {
public:
	/*
	* @param n: An integer
	* @param nums: An array
	* @return: the Kth largest element
	*/
	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
		n--;
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
			while (low < high && nums[low] >= nums[high]) {
				high--;
			}
			swap(nums[low], nums[high]);
			while (low < high && nums[low] >= nums[high]) {
				low++;
			}
			swap(nums[low], nums[high]);
		}
		return low;
	}
};