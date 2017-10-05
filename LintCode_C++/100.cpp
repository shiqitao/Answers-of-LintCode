class Solution {
public:
	/*
	* @param nums: An ineger array
	* @return: An integer
	*/
	int removeDuplicates(vector<int> &nums) {
		// write your code here
		if (nums.size() == 0) {
			return 0;
		}
		vector<int>::iterator iter;
		for (iter = nums.begin() + 1; iter != nums.end(); iter++) {
			if (*iter == *(iter - 1)) {
				nums.erase(iter);
				iter--;
			}
		}
		return nums.size();
	}
};