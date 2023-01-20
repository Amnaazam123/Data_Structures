#include<iostream>
#include"LinkedList.cpp"
using namespace std;
int main()
{
	cout << "\t\t\t\t\t__Check My Linklist by making some nodes__\n\n";
	cout << "\t\t\t\t__________________	Here is Menu	__________________\n\n";
	cout << "\t\t\t\t\tEnter 1 for if you want to insert node At Head.\n";
	cout << "\t\t\t\t\tEnter 2 if you want to insert node at tail.\n";
	cout << "\t\t\t\t\tEnter 3 if you want to delete node at Head.\n";
	cout << "\t\t\t\t\tEnter 4 if you want to delete node at Tail.\n";
	cout << "\t\t\t\t\tEnter 5 if you want to print your Linked List.\n";
	cout << "\t\t\t\t\tEnter 6 if you want to get specific node at certain position.\n";
	cout << "\t\t\t\t\tEnter 7 if you want to insert a node AFTER any node.\n";
	cout << "\t\t\t\t\tEnter 8 if you want to insert a node Before any node.\n";
	cout << "\t\t\t\t\tEnter 9 if you want to delete a node AFTER any node.\n";
	cout << "\t\t\t\t\tEnter 10 if you want to delete a node Before any node.\n";
	cout << "\t\t\t\t\tEnter 11 if you want to get number of nodes in your linked List.\n";
	cout << "\t\t\t\t\tEnter 12 if you want to search any node data in link list.\n";
	char resume;
	int key;
	int choice;
	LinkedList<int> list;
	cout << "\n\tAfter reading above instructions carefully::\n";
	do{
		cout << "\tEnter number against you want to perform functionality on LINKED LIST:: ";
		cin >> choice;
		bool getval;
		int inputVal;
		int num;
		if (choice == 1)
		{
			cout << "\tHow many values you want to insert at head:: ";
			cin >> num;
			cout << "\n\n";
			for (int i = 0; i < num; i++)
			{
				cout << "\tEnter a value to insert at HEAD:: ";
				cin >> inputVal;
				list.insertAtHead(inputVal);
			}
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 2)
		{
			cout << "\tHow many values you want to insert at TAIL:: ";
			cin >> num;
			cout << "\n\n";
			for (int i = 0; i < num; i++)
			{
				cout << "\tEnter a value to insert at tail: ";
				cin >> inputVal;
				list.insertAtTail(inputVal);
			}
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 3)
		{
			cout << "\n\n\t\t__After Deleting head__\n";
			getval = list.deleteAtHead();
			if (getval)
				cout << "\tDeleted head successfully...\n";
			else
				cout << "\tSorry, Head is not found. Your list is empty...\n";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 4)
		{
			cout << "\n\n\t\t__After Deleting Tail__\n";
			getval = list.deleteAtTail();
			if (getval)
				cout << "\tDeleted Tail successfully...\n";
			else
				cout << "\tSorry, Tail is not found. Your list is empty...\n";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 5)
		{
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 6)
		{
			cout << "\n\n\t\t__GET NODE Function call__ \n";
			cout << "\tWhich node you want to get. Enter position of that node: "; cin >> inputVal;
			Node<int>* get = list.getNode(inputVal);
			if (get)
			{
				cout << "\tYour Node data:: " << get->data << "\n";
				cout << "\tYou node's Next pointer holding address:: " << get->next << "\n";
				cout << "\tYou node Address:: " << get << "\n";
			}
		}
		else if (choice == 7)
		{
			cout << "\n\n\t\t__INSERT AFTER function call__\n";
			cout << "\tEnter key or node value against this function call works: ";
			cin >> key;
			cout << "\tEnter the value to be inserted: ";
			cin >> inputVal;
			getval = list.insertAfter(inputVal, key);
			if (getval)
				cout << "\tInserted successfully...\n";
			else
				cout << "\tSorry, here Node is not Found...\n";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 8)
		{
			cout << "\n\n\t\t__INSERT BEFORE function call__\n";
			cout << "\tEnter key or node value against this function call works: ";
			cin >> key;
			cout << "\tEnter the value to be inserted: ";
			cin >> inputVal;
			getval = list.insertBefore(key, inputVal);
			if (getval)
				cout << "\tInserted successfully...\n";
			else
				cout << "\tSorry, INVALID Node...\n";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 9)
		{
			cout << "\n\n\t\t__DELETE AFTER function call__\n";
			cout << "\tEnter key or node value against this function call works: "; cin >> inputVal;
			getval = list.deleteAfter(inputVal);
			if (getval)
				cout << "\tDeleted successfully...\n";
			else
				cout << "\tSorry, here Node is not Found...\n";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 10)
		{
			cout << "\n\n\t\t__DELETE BEFORE function call__\n";
			cout << "\tEnter key or node value against this function call works: "; cin >> inputVal;
			getval = list.deleteBefore(inputVal);
			if (getval)
				cout << "\tDeleted successfully...\n";
			else
				cout << "\tNode is not Found...";
			cout << "\n\n\tLinkedList looks like:: \n\t";
			list.printList();
		}
		else if (choice == 11)
		{
			cout << "\n\n\t\t__GET LENGTH function call__\n";
			cout << "\tNumber of nodes in your list are " << list.getLength() << "\n";
		}
		else if (choice == 12)
		{
			cout << "\n\n\tEnter value which you want to find in list: ";
			cin >> inputVal;
			Node<int>* found = list.search(inputVal);
			if (found)
				cout << "\tFOUNDED! at address: " << found << "\n";
			else
				cout << "\tNOT Founded! Sorry\n";
		}
		else
		{
			cout << "\t\noops! Invalid choice...\nYou have no any functionaliy against this number.\n";
		}
		cout << "\n\n\tWould you like to perform any other functionality on this LINKED LIST!!\n";
		cout << "\n\tIf Yes! Enter 'y' to resume\n\tElse Enter 'q'or any other caharacter to Quit\n";
		cout << "\tEnter choice :: "; cin >> resume;
	}while (resume == 'y' || resume == 'Y');
	cout << "Program ended successfully.....\n";
	cout << endl;
	return 0;
}