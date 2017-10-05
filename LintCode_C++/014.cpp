class Solution {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target number to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &array, int target) {
		int start = 0;
		int end = array.size() - 1;
		int middle;
		while (start + 1 < end)
		{
			middle = start + (end - start) / 2;
			if (array[middle] >= target) end = middle;
			else start = middle + 1;
		}
		if (array[start] == target) return start;
		else if (array[end] == target) return end;
		else return -1;
	}
};