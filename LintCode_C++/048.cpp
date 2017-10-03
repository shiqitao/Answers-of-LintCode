class Solution {
public:
	/*
	* @param nums: a list of integers
	* @return: The majority number that occurs more than 1/3
	*/
	int majorityNumber(vector<int> &nums, int k) {
		// write your code here
		map<int, int> myMap;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			myMap[nums[i]]++;
		}
		for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
			if (it->second > len / k) {
				return it->first;
			}
		}
	}
};