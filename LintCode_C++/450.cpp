/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


class Solution {
public:
	/*
	* @param head: a ListNode
	* @param k: An integer
	* @return: a ListNode
	*/
	ListNode * reverseKGroup(ListNode * head, int k) {
		// write your code here
		if (!head) return head;
		ListNode *end = head;
		for (int i = 1; i < k; i++) {
			if (!end->next) return head;
			end = end->next;
		}
		ListNode *start = head, *mid = start->next;
		end = mid;
		for (int i = 1; i < k; i++) {
			end = end->next;
			mid->next = start;
			start = mid;
			mid = end;
		}
		head->next = reverseKGroup(end, k);
		return start;
	}
};