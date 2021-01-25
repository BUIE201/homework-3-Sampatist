//This is a homework for IE201 Course, Murat Öztürk 2019402093
//I got the binary tree code from the lecture repo, then I changed the tree into being unsorted and randomly selected directions.
//Afterwards I got rid of the useless functions for this homework. I used the same print function in the lecture repo to print the tree.

#include "WhileInsert.h"
#include "AfterInsert.h"

int max(int a, int b) { return a < b ? b : a; };

void main()
{
	int versionNum = 1;

	if (versionNum == 1)
	{
		Node_v1* pRoot = nullptr;

		int i = 5;
		while (true)
		{
			Node_v1* p = new Node_v1(i);
			InsertToTree(pRoot, p);
			i += 1;
			if (i == 150)
				break;
		}
		PrintTree(pRoot, 1);
		printVector(MaxRoute(pRoot));
	}

	if(versionNum == 2)
	{
		Node_v2* pRoot = nullptr;
	
		int i = 16;
		while (true)
		{
			Node_v2* p = new Node_v2(i);
			InsertToTree(pRoot, p);
			i -= 1;
			if (i == 0)
				break;
		}
	
		i = -256;
		while (true)
		{
			Node_v2* p = new Node_v2(i);
			InsertToTree(pRoot, p);
			i += 1;
			if (i == 1)
				break;
		}
	
		i = 0;
		while (true)
		{
			Node_v2* p = new Node_v2(i);
			InsertToTree(pRoot, p);
			i += 1;
			if (i == 256)
				break;
		}
	
		PrintAnswerFormat(pRoot, 1);
	}
}