#include "stdafx.h"
#include "RelatedToTree.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

void RelatedToTree::preorderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		cout << "#" << ", ";
		return;
	}

	cout << root->val << ", ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}

bool RelatedToTree::isSameTree(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
	{
		return true;
	}

	if (left == nullptr || right == nullptr)
	{
		return false;
	}

	return left->val == right->val &&
		isSameTree(left->left, right->left)
		&& isSameTree(left->right, right->right);
}

bool RelatedToTree::isBalanced(TreeNode* root)
{
	return balancedHeight(root) >= 0;
}

int RelatedToTree::balancedHeight(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int left = balancedHeight(root->left);
	int right = balancedHeight(root->right);

	if (left < 0 || right < 0 || abs(left - right) > 1)
	{
		return -1;
	}
	return max(left, right) + 1;
}

void RelatedToTree::flattern(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	flattern(root->left);
	flattern(root->right);

	auto p = root->left;

	if (p == nullptr)
	{
		return;
	}

	// 让 p 指向左边链表的最后一个
	while (p->right != nullptr)
	{
		p = p->right;
	}

	// 组合最后结果
	p->right = root->right;
	root->right = root->left;
	root->left = nullptr;
}

void RelatedToTree::morris_inorderTraversal(TreeNode* root)
{
	TreeNode* p = root, *tmp;

	// p 指向当前操作的节点
	while (p != nullptr)
	{
		// 中序访问，意味着左边孩子节点是空，访问当前结点.
		if (p->left == nullptr)
		{
			cout << p->val << ", ";
			p = p->right; 
		}
		else
		{
			tmp = p->left;
			while (tmp->right != nullptr
				&& tmp->right != p)
			{
				tmp = tmp->right ;
			}

			if (tmp->right == nullptr)
			{
				tmp->right = p;
				p = p->left;
			}
			else
			{
				cout << p->val << ", ";
				tmp->right = nullptr;
				p = p->right;
			}
		}
	}
}