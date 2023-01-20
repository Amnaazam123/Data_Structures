#pragma once
//dangling pointer: abi b udar hi point krna jo ab delete ho gaya huwa
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(T putData, Node<T>* ptr = NULL)      //Node cons 
	{
		data = putData;
		next = ptr;
	}
};
template<class T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;
// Methods...
public:
	 LinkedList();
	 ~LinkedList();
	 LinkedList(const LinkedList& old_obj);
	 void insertAtHead(T value);
	 void insertAtTail(T value);
	 bool deleteAtHead();
	 bool deleteAtTail();
	 void printList();
	 Node<T>* search(T x);
	 bool insertAfter(T value, T key);
	 int getLength();
	 Node<T>* getNode(int n);
	 bool deleteAfter(T value);
	 bool deleteBefore(T key);
	 bool insertBefore(T value, T key);
};

