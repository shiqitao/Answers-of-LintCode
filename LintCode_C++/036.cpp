/**
* Definition of singly-linked-list:
*
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*        this->val = val;
*        this->next = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param head: ListNode head is the head of the linked list
	* @param m: An integer
	* @param n: An integer
	* @return: The head of the reversed ListNode
	*/
	ListNode * reverseBetween(ListNode * head, int m, int n) {
		// write your code here
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		head = dummy;
		ListNode *pre, *now;
		for (int i = 0; i < m - 1; i++) {
			head = head->next;
		}
		pre = head;
		head = head->next;
		now = head;
		ListNode *mid = head;
		ListNode *last = head->next;
		for (int i = 0; i < n - m; i++) {
			head = mid;
			mid = last;
			last = mid->next;
			mid->next = head;
		}
		pre->next = mid;
		now->next = last;
		return dummy->next;
	}
};