//This is a homework for IE201 Course, Murat Öztürk 2019402093
//I got the binary tree code from the lecture repo, then I changed the tree into being unsorted and randomly selected directions.
//Afterwards I got rid of the useless functions for this homework. I used the same print function in the lecture repo to print the tree.
//I changed the insert function significantly.
//I had to add a variable called Max:int for all nodes. 

#include <iostream>

using namespace std;

int max(int a, int b) { return a < b ? b : a;};

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;
	int Max; //This gives the max sum from this node, its sign indicates direction: - is left + is right. Since max branch sum can not be smaller than 0 we can use this.

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr), Max(0) {}
};

int InsertToTree(Node*& pRoot, Node* pNew)	//O(logn)		
{
	if (!pRoot)
	{
		pRoot = pNew;
		return pNew->i;
	}

	bool Direction = rand() % 2;   //To not have a sorted and to have an approximately balanced tree the direction is chosen randomly. 
	int CCD;		//CumulativeDirectedDistance
	if (Direction)	//left 
	{
		CCD = -InsertToTree(pRoot->pLeft, pNew);	//Take negative of the return value since it comes from the left node.
		
		if (pRoot->Max < 0)			//If maximum root is already from the left, then we can just put the improved or the same CCD to the root max.
		{
			pRoot->Max = CCD;		
		}
		else 
		{
			if (pRoot->Max + CCD < 0)	//If Max is from the right then we have to look if this new CCD is better than the max. If the sum is minus then left sum is better than right sum.
			{
				pRoot->Max = CCD;
			};
		}
	}
	else //right
	{
		CCD = InsertToTree(pRoot->pRight, pNew);	//Take positive since it comes from right node.

		if (pRoot->Max > 0)		//If maximum root is already from the right, then we can just put the improved or the same CCD to the root max.
		{
			pRoot->Max = CCD;
		}
		else
		{
			if (pRoot->Max + CCD > 0)	//If Max is from the left then we have to look if this new CCD is better than the max. If the sum is plus then right sum is better than left sum.
			{
				pRoot->Max = CCD;
			};
		}
	}
	
	return abs(pRoot->Max) + pRoot->i;	//This part is crucial, we take abs of Max but return index normally. By returning index normally and having those if's up there, this algorithm also works for minus numbers.
}

void PrintTree(Node* pRoot, int Level)	//O(n)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void PrintMaxRouteSum(Node*& pRoot)	//O(1)
{
	int result = pRoot->i + abs(pRoot->Max);
	std::cout << result << std::endl;
}

void PrintMaxRoute(Node*& pRoot)	//O(logn)
{
	if (!pRoot)
		return;

	std::cout << pRoot->i << " ";
	if (pRoot->Max < 0)
	{
		PrintMaxRoute(pRoot->pLeft);
	}
	else
	{
		PrintMaxRoute(pRoot->pRight);
	}
}

void PrintAnswerFormat(Node*& pRoot, bool PrintTree_B = 1)
{
	if(PrintTree_B)
		PrintTree(pRoot, 1);

	cout << "Branch with the largest sum is: ";
	PrintMaxRoute(pRoot);
	cout << "-> SUM = ";
	PrintMaxRouteSum(pRoot);
}

void main()
{
	Node* pRoot = nullptr;

	int i = 16;
	while (true)
	{
		Node* p = new Node(i);
		InsertToTree(pRoot, p);
		i -= 1;
		if (i == 0)
			break;
	}

	i = -256;
	while (true)
	{
		Node* p = new Node(i);
		InsertToTree(pRoot, p);
		i += 1;
		if (i == 1)
			break;
	}

	i = 0;
	while (true)
	{
		Node* p = new Node(i);
		InsertToTree(pRoot, p);
		i += 1;
		if (i == 256)
			break;
	}

	PrintAnswerFormat(pRoot, 1);
}