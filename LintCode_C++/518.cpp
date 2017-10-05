class Solution {
public:
	/*
	* @param n: a positive integer
	* @param primes: the given prime list
	* @return: the nth super ugly number
	*/
	int nthSuperUglyNumber(int n, vector<int> &primes) {
		// write your code here
		int *num = new int[n];
		num[0] = 1;
		int len = primes.size();
		int **cur = new int*[len];
		for (int i = 0; i < len; i++) {
			cur[i] = num;
		}
		for (int i = 1; i < n; i++) {
			int min = INT_MAX;
			int index = -1;
			for (int j = 0; j < len; j++) {
				while (*cur[j] * primes[j] <= num[i - 1]) {
					cur[j]++;
				}
				if (min > *cur[j] * primes[j]) {
					min = *cur[j] * primes[j];
					index = j;
				}
			}
			num[i] = *cur[index] * primes[index];
			cur[index]++;
		}
		int result = num[n - 1];
		delete[] num;
		delete[] cur;
		return result;
	}
};