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
	* @param v1: An integer
	* @param v2: An integer
	* @return: a new head of singly-linked list
	*/
	ListNode * swapNodes(ListNode * head, int v1, int v2) {
		// write your code here
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		head = dummy;
		ListNode *pre1 = NULL, *pre2 = NULL;
		while (head->next) {
			if (head->next->val == v1 || head->next->val == v2) {
				if (pre1) {
					pre2 = head;
				}
				else {
					pre1 = head;
				}
			}
			head = head->next;
		}
		if (pre1 && pre2) {
			if (pre1->next == pre2) {
				ListNode *cur2 = pre2->next;
				pre2->next = cur2->next;
				cur2->next = pre2;
				pre1->next = cur2;
			}
			else {
				ListNode *cur1 = pre1->next, *cur2 = pre2->next;
				ListNode *next1 = cur1->next, *next2 = cur2->next;
				pre1->next = cur2;
				pre2->next = cur1;
				cur1->next = next2;
				cur2->next = next1;
			}
		}
		return dummy->next;
	}
};