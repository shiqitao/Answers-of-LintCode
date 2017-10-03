/**
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
* Definition of Doubly-ListNode
* class DoublyListNode {
* public:
*     int val;
*     DoublyListNode *next, *prev;
*     DoublyListNode(int val) {
*         this->val = val;
this->prev = this->next = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param root: The root of tree
	* @return: the head of doubly list node
	*/
	DoublyListNode * bstToDoublyList(TreeNode * root) {
		// write your code here
		if (!root) return NULL;
		DoublyListNode *temp = new DoublyListNode(root->val);
		DoublyListNode *left = bstToDoublyList(root->left);
		DoublyListNode *right = bstToDoublyList(root->right);
		if (right) {
			right->prev = temp;
		}
		temp->next = right;
		if (left) {
			DoublyListNode *result = left;
			while (left->next) {
				left = left->next;
			}
			left->next = temp;
			temp->prev = left;
			return result;
		}
		return temp;
	}
};