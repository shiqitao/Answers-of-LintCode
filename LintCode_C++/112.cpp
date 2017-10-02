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
	* @param head: head is the head of the linked list
	* @return: head of linked list
	*/
	ListNode * deleteDuplicates(ListNode * head) {
		// write your code here
		if (!head) {
			return NULL;
		}
		if (!head->next) {
			return head;
		}
		if (head->val == head->next->val) {
			ListNode *temp = head->next;
			head->next = head->next->next;
			delete temp;
			deleteDuplicates(head);
		}
		else {
			deleteDuplicates(head->next);
		}
		return head;
	}
};