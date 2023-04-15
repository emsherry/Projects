#include <iostream>
using namespace std;

int N = 0;
int Count = 0;
int RowMax = 3;
int ColMax = 3;



struct Node
{
	int Phone;
	/*string Name;
	string Address;
	string Email;*/

	Node* Next;
	Node* Back;
	Node* Up;
	Node* Down;
};



Node* CreateNode()
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		cout << "No memory left!" << endl;;
		return NULL;
	}

	NewNode->Phone = NULL;
	/*NewNode->Name = "\0";
	NewNode->Address = "\0";
	NewNode->Email = "\0";*/
 
	NewNode->Next = NULL;
	NewNode->Back = NULL;
	NewNode->Up = NULL;
	NewNode->Down = NULL;

	return NewNode;
}



Node* AddInfo(Node* HeadPtr)
{
	if (N == (RowMax * ColMax))
	{
		cout << "No more data can be stored in this directory!" << endl;
		return NULL;
	}

	Node* NewData = CreateNode();
	cin >> NewData->Phone;

	if (N == 0)
	{
		HeadPtr = NewData;
		return HeadPtr;
	}

	Node* Curr = HeadPtr;
	Node* Prev = CreateNode();

	int CurrRow = N / ColMax;
	for (int i = 0; i < CurrRow; i++)
	{
		Prev = Curr;
		Curr = Curr->Down;
	}

	int CurrCol = N % ColMax;
	for (int j = 1; j < CurrCol; j++)
		Curr = Curr->Next;

	if (CurrCol == 0)
	{
		NewData->Up = Prev;
		Curr = NewData;
		Prev->Down = Curr;
	}
	else
	{
		NewData->Back = Curr;
		Curr->Next = NewData;
	}

	return HeadPtr;
}



void VerticalLinks(Node* HeadPtr)
{
	int CurrRow = N / ColMax;
	int CurrCol = N % ColMax;
	
	if (CurrRow > 0 && CurrCol > 0)
	{
		Node* UpperRow = HeadPtr;
		Node* LowerRow = HeadPtr->Down;

		for (int i = 1; i < CurrRow; i++)
		{
			UpperRow = UpperRow->Down;
			LowerRow = LowerRow->Down;
		}
		for (int j = 0; j < CurrCol; j++)
		{
			UpperRow = UpperRow->Next;
			LowerRow = LowerRow->Next;
		}

		UpperRow->Down = LowerRow;
		LowerRow->Up = UpperRow;;
	}
}



void SearchInfo(Node* HeadPtr, int SearchPtr)
{
	Node* Curr = HeadPtr;
	
	int CurrRow = Count / ColMax;

	for (int i = 0; i < CurrRow; i++)
		Curr = Curr->Down;

	for (int j = 0; j < ColMax; j++)
	{
		if (Curr->Phone == SearchPtr)
		{
			cout << Curr->Phone << endl;
			Count = 0;
			return;
		}

		Curr = Curr->Next;
		Count++;

		if (Count == N)
		{
			cout << "This phone number does not exist in the directory!" << endl;
			Count = 0;
			return;
		}
	}

	SearchInfo(HeadPtr, SearchPtr);
}



void DisplayInfo(Node* HeadPtr)
{
	Node* Curr = HeadPtr;
	
	int CurrRow = Count / ColMax;
	for (int i = 0; i < CurrRow; i++)
		Curr = Curr->Down;
	
	for (int j = 0; j < ColMax; j++)
	{
		cout << Curr->Phone << endl;
		Curr = Curr->Next;
		Count++;

		if (Count == N)
		{
			Count = 0;
			return;
		}
	}
	
	DisplayInfo(HeadPtr);
}



int main()
{
	Node* Head = CreateNode();
	int Instruction;

	do
	{
		cout << "MAIN MENU:" << endl;
		cout << "0: Exit." << endl;
		cout << "1: Add Phone Number." << endl;
		cout << "2: Delete Phone Number." << endl;
		cout << "3: Search Phone Number." << endl;
		cout << "4: Display Phone Numbers." << endl;

		cout << endl << "Enter a number to perform its corresponding action: ";
		cin >> Instruction;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "You can only enter a number!" << endl;
			cout << endl << "Enter a number to perform its corresponding action: ";
			cin >> Instruction;
		}

		switch (Instruction)
		{
		case 0:
			cout << "SYSTEM IS SHUTTING DOWN!" << endl;
			break;

		case 1:
			Head = AddInfo(Head);
			VerticalLinks(Head);
			N++;
			break;

		case 2:
			//DeleteInfo();
			break;

		case 3:
			int Search;
			cin >> Search;
			SearchInfo(Head, Search);
			break;

		case 4:
			DisplayInfo(Head);
			break;

		default:
			cout << "This number has no corresponding action!" << endl;
			break;
		}

		cout << endl;
		system("pause");
		system("cls");

	} while (Instruction != 0);

	return 0;
}