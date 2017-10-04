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
	* @param l1: the first list
	* @param l2: the second list
	* @return: the sum list of l1 and l2
	*/
	ListNode * addLists(ListNode * l1, ListNode * l2) {
		// write your code here
		int carry = 0;
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (l1 && l2) {
			ListNode *temp = new ListNode(l1->val + l2->val + carry);
			carry = temp->val / 10;
			temp->val %= 10;
			cur->next = temp;
			cur = cur->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode *rest = l1 ? l1 : l2;
		while (rest && carry) {
			ListNode *temp = new ListNode(rest->val + carry);
			carry = temp->val / 10;
			temp->val %= 10;
			cur->next = temp;
			cur = cur->next;
			rest = rest->next;
		}
		if (rest) {
			cur->next = rest;
		}
		if (carry) {
			ListNode *temp = new ListNode(carry);
			cur->next = temp;
		}
		return dummy->next;
	}
};