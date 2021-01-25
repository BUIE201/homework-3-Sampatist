//This version is more simple


#pragma once

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b);

struct Node_v1
{
	int i;
	Node_v1* pLeft;
	Node_v1* pRight;
	
	Node_v1(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node_v1*& pRoot, Node_v1* pNew)	//O(logn)		
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	bool Direction = rand() % 2;   //To not have a sorted and to have an approximately balanced tree the direction is chosen randomly. 
	if (Direction)	//left 
	{
		InsertToTree(pRoot->pLeft, pNew);	

	}
	else //right
	{
		InsertToTree(pRoot->pRight, pNew);	
	}
}

void PrintTree(Node_v1* pRoot, int Level)	//O(n)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

vector<int> MaxRoute(Node_v1* pRoot)
{
	vector<int> extra{};
	if (!pRoot)
		return extra;

	int leftsum = 0;

	auto left = MaxRoute(pRoot->pLeft);
	for (auto i : left)
		leftsum += i;

	int rightsum = 0;

	auto right = MaxRoute(pRoot->pRight);
	for (auto i : right)
		rightsum += i;

	if (leftsum > rightsum)
		extra = left;
	else
		extra = right;
	extra.push_back(pRoot->i);
	return extra;
}

void printVector(vector<int> in)
{
	int sum = 0;
	auto a = in.end() - 1;
	cout << "Branch with the largest sum is : ";
	for (a; a > in.begin(); a--)
	{
		cout << *a << " ";
		sum += *a;
	}
	sum += *a;
	cout << *a << "->SUM = " << sum <<endl;
}

