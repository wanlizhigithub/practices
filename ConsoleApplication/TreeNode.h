#pragma once
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr)
	{
		this->val = val;
		this->left = left;
		this->right = right;
	}
};

