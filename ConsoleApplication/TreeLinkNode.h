#pragma once

/*
 * 这个类主要针对 populate next right pointer in each node.
 * 成员变量 next 指向右边的兄弟节点，或者 nullptr 
 */
class TreeLinkNode
{
public:
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	int val;

	TreeLinkNode(int val)
	{
		this->val = val;
		this->left = this->right = this->next = nullptr;
	}
};