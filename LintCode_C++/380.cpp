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
	* @param headA: the first list
	* @param headB: the second list
	* @return: a ListNode
	*/
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
		// write your code here
		if (!headA || !headB) return NULL;
		int lenA = 1, lenB = 1;
		ListNode *endA = headA, *endB = headB;
		while (endA->next) {
			lenA++; endA = endA->next;
		}
		while (endB->next) {
			lenB++; endB = endB->next;
		}
		if (endA != endB) return NULL;
		if (lenA > lenB) {
			for (int i = 0; i < lenA - lenB; i++) {
				headA = headA->next;
			}
		}
		else {
			for (int i = 0; i < lenB - lenA; i++) {
				headB = headB->next;
			}
		}
		while (headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};