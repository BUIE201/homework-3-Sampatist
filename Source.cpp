#include <iostream>

using namespace std;

int max(int a, int b) { return a < b ? b : a;};


struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;
	int Max;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr), Max(0) {}
};

int InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return pNew->i;
	}

	bool Direction = rand() % 2;
	int CCD; //CumulativeDirectedDistance
	if (Direction) //left 
	{
		CCD = -InsertToTree(pRoot->pLeft, pNew);
		
		if (pRoot->Max < 0)
		{
			pRoot->Max = CCD;
		}
		else 
		{
			if (pRoot->Max + CCD < 0)
			{
				pRoot->Max = CCD;
			};
		}
	}
	else //right
	{
		CCD = InsertToTree(pRoot->pRight, pNew);

		if (pRoot->Max > 0)
		{
			pRoot->Max = CCD;
		}
		else
		{
			if (pRoot->Max + CCD > 0)
			{
				pRoot->Max = CCD;
			};
		}
	}
	
	return abs(pRoot->Max) + pRoot->i;
}

void DeleteNodeWithTwoChildren(Node*& q, Node*& p)
{
	if (p->pRight)
	{
		DeleteNodeWithTwoChildren(q, p->pRight);
		return;
	}

	p->i = q->i;
	q = p;
	p = p->pLeft;
}

void DeleteNodeFromTree(Node*& pRoot, int i)
{
	if (!pRoot)
		return;

	if (pRoot->i < i)
	{
		DeleteNodeFromTree(pRoot->pRight, i);
		return;
	}

	if (pRoot->i > i)
	{
		DeleteNodeFromTree(pRoot->pLeft, i);
		return;
	}

	Node* q = pRoot;
	if (!q->pRight)
		pRoot = q->pLeft;
	else if (!q->pLeft)
		pRoot = q->pRight;
	else
		DeleteNodeWithTwoChildren(q, q->pLeft);

	delete q;
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void Insert(Node*& pRoot, Node* pNewNode)
{
	if (!pRoot)
		pRoot = pNewNode;
	else
	{
		if (pNewNode->i < pRoot->i)
			Insert(pRoot->pLeft, pNewNode);
		else
			Insert(pRoot->pRight, pNewNode);
	}
}

void PrintMaxRouteSum(Node*& pRoot)
{
	int result = pRoot->i + abs(pRoot->Max);
	std::cout << result << std::endl;
}

void PrintMaxRoute(Node*& pRoot)
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

void main()
{
	int i = 0;
	Node* pRoot = nullptr;
	while (true)
	{
		//cin >> i;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
		i += 1;
		if (i == 20)
			break;
	}

	PrintTree(pRoot, 1);
	PrintMaxRouteSum(pRoot);
	PrintMaxRoute(pRoot);
	//IT EVEN WORKS ON NEGATIVE VALUES!!!! 
}