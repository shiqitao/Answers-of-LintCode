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
	* @return: a ListNode
	*/
	ListNode * swapPairs(ListNode * head) {
		// write your code here
		if (!head || !head->next) return head;
		ListNode *end = head->next;
		head->next = swapPairs(end->next);
		end->next = head;
		return end;
	}
};