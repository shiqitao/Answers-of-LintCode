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
	* @param head: The head of linked list.
	* @return: nothing
	*/
	void reorderList(ListNode * head) {
		// write your code here
		if (!head) {
			return;
		}
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		if (slow->next && slow->next->next)
		{
			ListNode *pre = slow->next;
			fast = pre->next;
			pre->next = NULL;
			ListNode *next = fast;
			while (fast) {
				next = next->next;
				fast->next = pre;
				pre = fast;
				fast = next;
			}
			fast = pre;
		}
		else {
			fast = slow->next;
		}
		slow->next = NULL;
		slow = head;
		ListNode *temp;
		while (slow && fast) {
			temp = fast->next;
			fast->next = slow->next;
			slow->next = fast;
			slow = slow->next->next;
			fast = temp;
		}
	}
};