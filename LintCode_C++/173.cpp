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
	* @param head: The first node of linked list.
	* @return: The head of linked list.
	*/
	ListNode * insertionSortList(ListNode * head) {
		// write your code here
		ListNode *dummy = new ListNode(INT_MIN);
		ListNode *curr, *temp;
		while (head) {
			curr = dummy;
			while (curr->next && head->val > curr->next->val) {
				curr = curr->next;
			}
			temp = head->next;
			if (curr->next) {
				head->next = curr->next;
				curr->next = head;
			}
			else {
				curr->next = head;
				head->next = NULL;
			}
			head = temp;
		}
		return dummy->next;
	}
};