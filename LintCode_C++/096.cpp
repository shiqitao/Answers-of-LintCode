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
	* @param head: The first node of linked list
	* @param x: An integer
	* @return: A ListNode
	*/
	ListNode * partition(ListNode * head, int x) {
		// write your code here
		ListNode *leftDummy = new ListNode(-1);
		ListNode *rightDummy = new ListNode(-1);
		ListNode *left = leftDummy, *right = rightDummy;
		while (head) {
			if (head->val < x) {
				left->next = head;
				left = left->next;
			}
			else {
				right->next = head;
				right = right->next;
			}
			head = head->next;
		}
		left->next = rightDummy->next;
		right->next = NULL;
		return leftDummy->next;
	}
};