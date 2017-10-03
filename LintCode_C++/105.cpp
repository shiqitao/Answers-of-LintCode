/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	/**
	* @param head: The head of linked list with a random pointer.
	* @return: A new head of a deep copy of the list.
	*/
	RandomListNode *copyRandomList(RandomListNode *head) {
		// write your code here
		unordered_map<RandomListNode*, RandomListNode*> old2new;
		RandomListNode* dummy = new RandomListNode(-1);
		RandomListNode* tmp = head;
		RandomListNode* curr = dummy;
		while (tmp) {
			RandomListNode* newNode = new RandomListNode(tmp->label);
			old2new[tmp] = newNode;
			curr->next = newNode;
			curr = curr->next;
			tmp = tmp->next;
		}
		tmp = head;
		while (tmp) {
			if (tmp->random) {
				old2new[tmp]->random = old2new[tmp->random];
			}
			tmp = tmp->next;
		}
		return dummy->next;
	}
};