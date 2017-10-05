class Solution {
public:
	/*
	* @param nums: An ineger array
	* @return: An integer
	*/
	int removeDuplicates(vector<int> &nums) {
		// write your code here
		if (nums.size() == 0 || nums.size() == 1) {
			return nums.size();
		}
		vector<int>::iterator iter;
		for (iter = nums.begin() + 2; iter != nums.end(); iter++) {
			if (*iter == *(iter - 1) && *iter == *(iter - 2)) {
				nums.erase(iter);
				iter--;
			}
		}
		return nums.size();
	}
};