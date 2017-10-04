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
	* @param head: A ListNode.
	* @return: A boolean.
	*/
	bool isPalindrome(ListNode * head) {
		// write your code here
		if (!head) return true;
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// reverse linked list after slow
		ListNode *prev = NULL;
		ListNode *temp = slow->next;
		ListNode *next = temp;
		while (temp) {
			next = next->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		slow->next = prev;
		// check
		fast = slow->next;
		slow = head;
		while (fast) {
			if (fast->val != slow->val) {
				return false;
			}
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}
};