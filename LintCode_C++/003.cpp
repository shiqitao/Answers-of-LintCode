class Solution {
public:
	/*
	* @param : An integer
	* @param : An integer
	* @return: An integer denote the count of digit k in 1..n
	*/
	int digitCounts(int k, int n) {
		// write your code here
		int result = 0;
		for (int i = 0; i < n + 1; i++) {
			result += check(k, i);
		}
		return result;
	}
	int check(int k, int n) {
		if (k == 0 && n == 0) {
			return 1;
		}
		int result = 0;
		while (n != 0) {
			result += n % 10 == k ? 1 : 0;
			n /= 10;
		}
		return result;
	}
};