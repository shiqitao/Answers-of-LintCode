class Solution {
public:
	/*
	* @param n: An integer
	* @return: the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		int *num = new int[n];
		num[0] = 1;
		int *cur2 = num;
		int *cur3 = num;
		int *cur5 = num;
		for (int i = 1; i < n; i++) {
			if (*cur2 * 2 < *cur3 * 3 && *cur2 * 2 < *cur5 * 5) {
				if (*cur2 * 2 > num[i - 1]) num[i] = *cur2 * 2;
				else i--;
				cur2++;
			}
			else if (*cur3 * 3 < *cur5 * 5) {
				if (*cur3 * 3 > num[i - 1]) num[i] = *cur3 * 3;
				else i--;
				cur3++;
			}
			else {
				if (*cur5 * 5 > num[i - 1]) num[i] = *cur5 * 5;
				else i--;
				cur5++;
			}
		}
		int result = num[n - 1];
		delete[] num;
		return result;
	}
};