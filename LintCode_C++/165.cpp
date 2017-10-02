/**
* Definition of ListNode
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*         this->val = val;
*         this->next = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param l1: ListNode l1 is the head of the linked list
	* @param l2: ListNode l2 is the head of the linked list
	* @return: ListNode head of linked list
	*/
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		// write your code here
		if (!l1 && !l2) return NULL;
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};