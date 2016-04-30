#pragma once
#include "TreeLinkNode.h"
#include "TreeNode.h"
class RelatedToTree
{
public:
	void preorderTraversal(TreeNode* root);
	void morris_inorderTraversal(TreeNode* root);
	bool isSameTree(TreeNode* left, TreeNode* right);
	bool isBalanced(TreeNode* root);
	void flattern(TreeNode* root);
	void populateNextRightPointer(TreeLinkNode* root);

private:
	// 关键在于返回值，返回值是-1，意味着以这个节点为树的不是平衡树
	int balancedHeight(TreeNode* root);
};

