class Solution {
public:
	/*
	* @param numbers : An array of Integer
	* @param target : target = numbers[index1] + numbers[index2]
	* @return : [index1+1, index2+1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (hash.find(target - nums[i]) != hash.end()) {
				result.push_back(hash[target - nums[i]] + 1);
				result.push_back(i + 1);
				return result;
			}
			hash[nums[i]] = i;
		}
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};
