// 18300229_FIFO.cpp	P2.2 - COLA
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

template <class T>
class List	//Contains the activities of the list.
{
	class Node //Holds our nodes.
	{
	public:
		T data = NULL; //Holds a generic data value.
		Node* link; //Points to the next element.
		Node()
		{
			link = nullptr;
		}
	};

	Node* beginning;

public:
	List()
	{
		beginning = nullptr;
	}

	void enqueue(T data) //enqueue, adds element at the element.
	{
		Node* newNode, * cursor;
		newNode = new Node();
		newNode->data = data;

		if (beginning == nullptr)
			beginning = newNode;
		else
		{
			cursor = beginning;
			while (cursor->link) //while next link is not empty.
				cursor = cursor->link;
			cursor->link = newNode;
		}
	}

	int count() //Counts the elements in the list.
	{
		int elementCount = 0;
		Node* cursor = beginning;
		while (cursor)
		{
			elementCount++;
			cursor = cursor->link;
		}
		return elementCount;
	}

	void dequeue() //Deletes first (oldest) element.
	{
		Node* erase = beginning;
		beginning = beginning->link;	//Moves to next pointer or NULL.
		delete erase;	//deletes beginning.
	}

	void deleteAll() //Clears list.
	{
		Node* erase;

		while (beginning) //Deletes from first to last while link not null.
		{
			erase = beginning;
			beginning = beginning->link;
			delete erase;
		}
	}

	bool checkEmpty() //Checks if count is 0.
	{
		if (count() == 0)
		{
			cout << "List is empty." << endl;
			return true;
		}
		return false;
	}
};

int main()
{
	List<int> myCollection;
	int dataValue = 0;
	do
	{
		char choice = 0;
		system("cls");
		cout << "========LIFO=========" << endl;

		do //Loop until correct input
		{
			cout << endl << "Choose an option" << endl;
			cout << "[1] Push" << endl;
			cout << "[2] Count" << endl;
			cout << "[3] Pop" << endl;
			cout << "[4] Delete all" << endl;
			cout << "[5] Exit." << endl;
			cout << ">Answer: "; choice = _getch();
			system("cls");
		} while (choice < 49 or choice > 53); //ASCII from 1 to 5.

		switch (choice)
		{
		case '1':	//Pop -- add element
			cout << "Push:" << endl;
			cout << "Item [" << myCollection.count() + 1 << "]: ";
			cin >> dataValue;
			myCollection.enqueue(dataValue);
			cout << "\n >Item added." << endl;
			break;

		case '2': //Count
			if (myCollection.checkEmpty())
				break;
			cout << "\nThe element count is = " << myCollection.count() << " elements.\n";
			break;

		case '3':	//head
			if (myCollection.checkEmpty()) break;
			myCollection.dequeue();
			cout << "\nThe first element has been deleted.\n";
			break;

		case '4':	//Clear list
			if (myCollection.checkEmpty())
				break;
			myCollection.deleteAll();
			cout << "\n List is now clear, all elements deleted successfully\n";
			break;

		case '5':	//Exit
			cout << endl << "Successfully exited the program.\n";
			return 0;
			break;
		}

		cout << endl;
		system("pause");
	} while (1);	//Never ending loop
}