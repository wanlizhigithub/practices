// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TreeNode.h"
#include "RelatedToTree.h"
#include <iostream>
using namespace std;

void isSameTree_case1()
{
	TreeNode node1(1), node2(2);
	node1.right = &node2;

	auto res = RelatedToTree().isSameTree(&node1, &node1);
	cout << "true, " << res << endl;
}

void isBalanced_basic()
{
	TreeNode node1(1), node2(2), node3(3);
	node1.right = &node2;
	node2.right = &node3;

	auto res = RelatedToTree().isBalanced(&node1);
	cout << "false, " << res << endl;
}

void flattern_basic()
{
	TreeNode node1(1), node2(2), node3(3), node4(4);
	node1.left = &node2;
	node2.left = &node3;
	node1.right = &node4;

	RelatedToTree().flattern(&node1);

	cout << "1, #, 2, #, 3, #, 4, #, #" << endl;
	RelatedToTree().preorderTraversal(&node1);
}

void morris_inorder_basic()
{
	TreeNode node1(1), node2(2), node3(3);
	node1.left = &node2;
	node1.right = &node3;
	cout << "2, 1, 3" << endl;
	RelatedToTree().morris_inorderTraversal(&node1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	morris_inorder_basic();
	system("pause");
	return 0;
}

