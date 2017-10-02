class Solution {
public:
	/*
	* @param : an integer
	* @return:  the factorial of n
	*/
	string factorial(int n) {
		// write your code here
		string result = "1";
		for (int i = 1; i <= n; i++) {
			int len = result.size();
			int carry = 0;
			int temp;
			for (int j = 0; j < len; j++) {
				temp = (result[j] - '0')*i + carry;
				result[j] = temp % 10 + '0';
				carry = temp / 10;
			}
			while (carry != 0) {
				result += carry % 10 + '0';
				carry /= 10;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};