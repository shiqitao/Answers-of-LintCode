class MinStack {
public:
	/*
	* @param a: An integer
	*/
	stack<int> pool, minStack;
	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		// write your code here
		pool.push(number);
		if (minStack.empty()) {
			minStack.push(number);
		}
		else {
			minStack.push(number < minStack.top() ? number : minStack.top());
		}
	}

	/*
	* @param a: An integer
	* @return: An integer
	*/
	int pop() {
		// write your code here
		minStack.pop();
		int temp = pool.top();
		pool.pop();
		return temp;
	}

	/*
	* @param a: An integer
	* @return: An integer
	*/
	int min() {
		// write your code here
		return minStack.top();
	}
};