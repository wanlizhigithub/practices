#include "stdafx.h"
#include "LetterCombinationOfAPhone.h"
#include <iostream>


vector<string> keyboard{ " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void dfs(vector<string>& result, string path, size_t index, const string& digits)
{
	if (index == digits.size())
	{
		result.push_back(path);
		return;
	}
	for (auto c : keyboard[digits[index] - '0'])
	{
		dfs(result, path + c, index + 1, digits);
	}
}

vector<string> LetterCombinationOfAPhone::letterCombinatoins(const string& digits)
{
	vector<string> result;
	if (digits.empty())
	{
		return result;
	}
	dfs(result, "", 0, digits);
	return result;
}

void LetterCombinationOfAPhone::test()
{
	auto vec = LetterCombinationOfAPhone().letterCombinatoins("22");

	cout << "aa, ab, ac, ba, bb, bc, ca, cb, cc" << endl;

	for (auto e : vec)
	{
		cout << e << ", ";
	}
}