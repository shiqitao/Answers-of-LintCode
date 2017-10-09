class Solution {
public:
	/*
	* @param n: an integer
	* @return: an ineger f(n)
	*/
	int fibonacci(int n) {
		// write your code here
		if (n == 1) return 0;
		if (n == 2) return 1;
		int a = 0, b = 1, c;
		for (int i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
};