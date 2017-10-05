class Solution {
public:
	int getGCD(int a, int b) {
		if (a % b == 0) return b;
		return getGCD(b, a % b);
	}
	void recoverRotatedSortedArray(vector<int> &nums) {
		int offset = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] > nums[i]) offset = i;
		}
		if (offset == 0) return;
		offset = nums.size() - offset;
		int gcd = getGCD(offset, nums.size());
		for (int i = 0; i < gcd; i++) {
			int next = (i + offset) % nums.size();
			while (next != i) {
				int temp = nums[i];
				nums[i] = nums[next];
				nums[next] = temp;
				next = (next + offset) % nums.size();
			}
		}
	}
};