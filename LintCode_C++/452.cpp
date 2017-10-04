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
	* @param val: An integer
	* @return: a ListNode
	*/
	ListNode * removeElements(ListNode * head, int val) {
		// write your code here
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy;
		while (head) {
			if (head->val == val) {
				pre->next = head->next;
				delete head;
				head = pre->next;
			}
			else {
				pre = head;
				head = head->next;
			}
		}
		return dummy->next;
	}
};