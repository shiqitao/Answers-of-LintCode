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
	* @return: head of the linked list
	*/
	ListNode * deleteDuplicates(ListNode * head) {
		// write your code here
		if (!head || !head->next) {
			return head;
		}
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;
		ListNode *next;
		while (cur && cur->next) {
			if (cur->val == cur->next->val) {
				int val = cur->val;
				while (cur && cur->val == val) {
					next = cur->next;
					delete cur;
					cur = next;
				}
				pre->next = cur;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};