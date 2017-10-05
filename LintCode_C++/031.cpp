class Solution {
public:
	int partitionArray(vector<int> &nums, int k) {
		if (nums.size() == 0) return 0;
		unsigned short low = 0;
		unsigned short high = nums.size() - 1;
		int temp;
		while (low < high) {
			while (low < high && nums[low] < k) low++;
			temp = nums[low];
			nums[low] = nums[high];
			nums[high] = temp;
			while (low < high && nums[high] >= k) high--;
			temp = nums[low];
			nums[low] = nums[high];
			nums[high] = temp;
		}
		if (nums[low] < k) low++;
		return low;
	}
};