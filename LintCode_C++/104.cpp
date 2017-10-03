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
	/**
	* @param lists: a list of ListNode
	* @return: The head of one sorted list.
	*/
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// write your code here
		ListNode *dummy = new ListNode(0);
		ListNode *temp = dummy;
		int len = lists.size();
		int index, min;
		while (true)
		{
			min = INT_MAX;
			index = -1;
			for (int i = 0; i < len; i++) {
				if (lists[i] && lists[i]->val < min) {
					min = lists[i]->val;
					index = i;
				}
			}
			if (index != -1) {
				temp->next = lists[index];
				temp = temp->next;
				lists[index] = lists[index]->next;
			}
			else return dummy->next;
		}
	}
};