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
	* @param head: the List
	* @param k: rotate to the right k places
	* @return: the list after rotation
	*/
	ListNode * rotateRight(ListNode * head, int k) {
		// write your code here
		if (!head) {
			return head;
		}
		ListNode * slow = head;
		ListNode * fast = head;
		for (int i = 0; i < k; i++) {
			if (fast->next) {
				fast = fast->next;
			}
			else {
				fast = head;
			}
		}
		if (slow == fast) {
			return head;
		}
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		ListNode *result = slow->next;
		slow->next = NULL;
		fast->next = head;
		return result;
	}
};