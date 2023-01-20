#include<iostream>
#include "LinkedList.h"
using namespace std;
template <class T>
LinkedList<T>::LinkedList() :head(NULL), tail(NULL)   //constructor
{}
template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = head;
	while (head != NULL)
	{
		head = head->next;
		delete(temp);
		temp = head;
	}
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList& old_obj)            //copy cons
{
	if (old_obj.head == NULL)
	{
		head = tail = NULL;
		return;
	}
	Node<T>* readNode = old_obj.head;
	while (readNode != NULL)
	{
		Node<T>* makeNode = new Node<T>(readNode->data); //make a new nameless node who is pointed by makenode pointer.
			//head always point 1st node, if we do not have first node then linkList is empty.
			//if it is empty then we point head and tail both to 1st node.
		if (readNode == old_obj.head)
			head = tail = makeNode;       //head and tail are pointing to new node
		else
		{
			tail->next = makeNode;  //tail jis node ko point kr ra hai us node k next ko new node py point krwa dein.
			//makeNode->next = NULL; //constructor is doing this
			tail = makeNode;      //make the tail, last node bcz tail should always point to last.
		}
		readNode = readNode->next;
	}
	
}
template<class T>
void LinkedList<T>::insertAtTail(T value)
{
	Node<T>* makeNode = new Node<T>(value);//make a new nameless node who is pointed by makenode pointer.
	//head always point 1st node, if we do not have first node then linkList is empty.
	//if it is empty then we point head and tail both to 1st node.
	if (head == NULL)
		head = tail = makeNode;   //head and tail are pointing to new node
	else
	{
		tail->next = makeNode;  //tail jis node ko point kr ra hai us node k next ko new node py point krwa dein.
		//makeNode->next = NULL; //constructor is doing this
		tail = makeNode;      //make the tail, last node bcz tail should always point to last.
	}
}
template <class T>
void LinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode = new Node<T>(value);     //node to be inserted
	if (head == NULL)                         //if linkedlist was empty before this insertion
		head = tail = newNode;               //head and tail are both pointing to 1st node
	else
	{
		newNode->next = head;            //newNode's Next will point to that node which was firslty head.
		head = newNode;                 //update your head with new node
	}
}
template<class T>
void LinkedList<T>::printList()
{
	//ab mai ny head sy list print krwana shuru krni hai
	Node<T>* temp = head;
	while (temp != NULL)      //print each node untill linkedList ends.
	{
		cout << temp->data << " --> ";
		temp = temp->next;            //move next pointer frwrd. 
	}
	cout << "NULL" << endl;
}
template<class T>
Node<T>* LinkedList<T>::search(T searchVal)
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		if (temp->data == searchVal)
			return temp;         //returning the address of searched node
		else
			temp = temp->next;     //else iterate your linked list
	}
	return NULL;
}
template<class T>
bool LinkedList<T>::insertAfter(T placeValue, T at)
{
	Node<T>* found = search(at);      //find that address after that you are to enter insert
	if (found)
	{
		Node<T>* insertNode = new Node<T>(placeValue);     //make new node
		insertNode->next = found->next;                //insertion with proper pointers
		found->next = insertNode; 
		if (found == tail)           //if it wes last node
			tail = insertNode;
		return true;
	}
	return false;
}
template<class T>
bool LinkedList<T>::deleteAtHead()
{
	if (head != NULL)
	{
		Node<T>* temp = head;      //pehlay waley node ko delete krny k liey usay stor krwa lo
		head = head->next;
		delete temp;       //yahan delete head to nai likh skti thi na ab
		if (head == NULL)    //mtlb bs aik hi node tha wo b del kr dia
		{
			//tail dangling bn gaya
			tail = NULL;
		}
		return true;
	}
	return false;
}
template<class T>
bool LinkedList<T>::deleteAtTail()
{
	if (head == NULL)
		return false;
	Node<T>* temp = head;  //temp jis jaga ko point kr ra wo to heap py hi bni hai na
	if (head == tail)      //only one node
	{
		head = tail = NULL;
		delete temp;    //delete node
		return true;
	}
	else      //more than one node
	{
		while (temp)
		{
			if (temp->next->next == NULL)       //get the address of second last node bcz it is going to be last now.    
			{
				tail = temp;                  //update your tail
				tail->next = NULL;            //update tail's next
				delete temp->next;            //deleting last node.
				break;
			}
			temp = temp->next;
		}
		return true;
	}
	return false;
}
template<class T>
int LinkedList<T>::getLength()
{
	int count = 0;
	Node<T>* temp = head;
	while (temp != NULL)        //iterate linked LIst untill you reach at end.
	{
		temp = temp->next;     //move frwrd in linked list
		count++;                //counting nodes
	}
	return count;
}
template <class T>
Node<T>* LinkedList<T>::getNode(int n)
{
	int count = 1;
	Node<T>* temp = head;
	while (temp != NULL)
	{
		if (count == n)          //to get node position on which node is locating
			return temp;
		temp = temp->next;
		count++;                 //find node's position
	}
	if (tail != NULL)     //means tail exists in linked list
	{
		cout << "\tTail node is found because your node was not here.\n";
		return tail;
	}
	else {
		cout << "\tOOps! Tail is also not found in linkList to be returned.\n";
		return NULL;
	}
}
template<class T>
bool LinkedList<T>::deleteBefore(T val)
{
	Node<T>* temp = head;
	Node<T>* temp1 = head;      //to get the address of node to be deleted
	Node<T>* found = NULL;
	while (temp1 != NULL)
	{
		if (temp1->next != NULL)
		{
			if (temp1->next->data == val)         //finding the node before, to be deleted
			{
				found = temp1; //returning the address of node to be deleted
				break;
			}
		}
			temp1 = temp1->next;
	}
		if (found)
		{
			if (found == tail)    //check if it is tail?
				deleteAtTail();
			else if (found == head)   //check if it is head?
				deleteAtHead();
			else
			{
				while (temp != NULL)
				{
					if (temp->next == found)         //if you find node to be deleted
					{
						temp->next = found->next;      //insert it and update your pointers accordingly
						delete found;                 //delete node
						break;
					}
					temp = temp->next;
				}
			}
			return true;
		}
		else
			cout << "\tSorry , INVALID node value.\n";
		return false;
}
//same as deleteBefore() function but with different node deletion
template<class T>
bool LinkedList<T>::deleteAfter(T val)
{
	Node<T>* temp = head;
	Node<T>* temp1 = head;          //to get the address of node to be deleted
	Node<T>* found = NULL;
	while (temp1 != NULL)
	{
		if (temp1->data == val)     //finding the node before, to be deleted
		{
			found = temp1->next;   //returning the address of node to be deleted
			break;
		}
		else
			temp1 = temp1->next;
	}
	if (found)
	{
		if (found == tail)          //if tail is going to be delete
			deleteAtTail();
		else if (found == head)     //if head is going to be delete
			deleteAtHead();
		else
		{
			while (temp != NULL)
			{
				if (temp->next == found) //if you find node to be deleted
				{
					temp->next = found->next;    //insert it and update your pointers accordingly
					delete found;                 //delete node
					break;
				}
				temp = temp->next;
			}
		}
		return true;
	}
	if(head == NULL)
		cout << "\tThe list is Empty.\n";
	return false;
}
template<class T>
bool LinkedList<T>::insertBefore(T key, T value)
{
	if (head == NULL)        //if linked list is empty?
		return false;
	Node<T>* temp1 = head;    //to get the address of node to be inserted
	Node<T>* found = NULL;
	if (temp1->data == key)    //is inserted node is going to be the first of your list?             
	{
		Node<T>* insertNode = new Node<T>(value);    //make node
		insertNode->next = head;      //make link
		head = insertNode;          //update head
		return true;
	}
	else
	{
		while (temp1 != NULL)         //finding the node before, to be inserted
		{
			if (temp1->next->data == key)
			{
				found = temp1;          //returning the address of node before that to be inserted
				break;
			}
			else
				temp1 = temp1->next;
		}
		if (found)            //insert that Node at founded address
		{
			Node<T>* insertNode = new Node<T>(value);
			insertNode->next = found->next;
			found->next = insertNode;
			if (found == tail)            //if it is tail then make it tail.
				tail = insertNode;
			return true;
		}
		else
			cout << "\tSorry this node does not exits in your list.\n";
		return false;
	}
}