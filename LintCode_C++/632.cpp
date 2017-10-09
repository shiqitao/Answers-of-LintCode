class Solution {
public:
	/*
	* @param root: the root of tree
	* @return: the max node
	*/
	TreeNode * maxNode(TreeNode * root) {
		// write your code here
		if (!root) return root;
		TreeNode *left = maxNode(root->left);
		TreeNode *right = maxNode(root->right);
		if (!left && !right) return root;
		if (!left) return root->val > right->val ? root : right;
		if (!right) return root->val > left->val ? root : left;
		TreeNode *temp = left->val > right->val ? left : right;
		return root->val > temp->val ? root : temp;
	}
};