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
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param head: The first node of linked list.
	* @return: a tree node
	*/
	TreeNode * sortedListToBST(ListNode * head) {
		// write your code here
		if (!head) return NULL;
		ListNode *slow = head, *fast = head;
		int len = 0;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			len += 2;
		}
		len += fast ? 1 : 0;
		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(head, len / 2);
		root->right = sortedListToBST(slow->next, len - len / 2 - 1);
		return root;
	}
	TreeNode * sortedListToBST(ListNode * head, int len) {
		if (len == 0) return NULL;
		ListNode *temp = head;
		for (int i = 0; i < len / 2; i++) {
			temp = temp->next;
		}
		TreeNode *root = new TreeNode(temp->val);
		root->left = sortedListToBST(head, len / 2);
		root->right = sortedListToBST(temp->next, len - len / 2 - 1);
		return root;
	}
};