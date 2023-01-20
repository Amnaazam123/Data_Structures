//BSEF19M009
//AMNA AZAM
//DSA-LAB#05

#include<iostream>
using namespace std;
#include "Queue.h"
template<class T>
Queue<T>::Queue(int sizeOfQueue)
{
	size = sizeOfQueue;
	myQueue = new T[size];
	front = -1;
	rear = -1;
	count = 0;
}

//Queue is empty
template<class T>
bool Queue<T>::isEmpty()
{
	return count == 0;
}

template<class T>
Queue<T>::Queue(const Queue<T>& old_obj)
{
	count = old_obj.count;
	myQueue = new T[old_obj.size];
	size = old_obj.size;
	front = old_obj.front;
	rear = old_obj.rear;
	for (int i = 0; i < old_obj.size; i++)
		myQueue[i] = old_obj.myQueue[i];
}

//Queue is full
template<class T>
bool Queue<T>::isFull()
{
	return count == size;
}

//insert element
template<class T>
void Queue<T>::enqueue(T val)
{
	if (isFull())
	{
		if(count>=10)
		rear = count - rear + 2;
		resize(size);
	}
	if (!isFull())
	{
		rear = (rear + 1) % size;
		myQueue[rear] = val;
		count++;
	}
}

//remove element
template<class T>
T Queue<T>::dequeue()
{
	if (isEmpty())
		resize(size);
	if (!isEmpty())
	{
		front = (front + 1) % size;
		count--;
		return myQueue[front];
	}	
}

template<class T>
T Queue<T>::peek()
{
	if (!isEmpty())
		return myQueue[front];
}

template<class T>
int Queue<T>::noOfElements()
{
	return count;
}

template<class T>
int Queue<T>::resize(int x)
{
	size = x;
	T* temp;
	temp = new T[count];
	int j = 0;
	int front1 = front;
	int count1 = count;
	while (j<count)
	{
		front1 = (front1 + 1) % size;
		count1--;
		temp[j++]= myQueue[front1];
		front = -1;
	}
		rear = count - 1;
	if (isFull())                            //if queue is full?
		size = size * 2;
	else if (count <= size / 4)              //if 3/4th part of queue is empty?
		size = size / 2;

	delete[] myQueue;
	myQueue = new T[size];                   //new array
	for (int i = 0; i < count; i++)
		myQueue[i] = temp[i];
	delete[] temp;
	return size;
}

template<class T>
void Queue<T>::showStructure()
{
	for (int i = front+1; i != rear+1; i++)
		cout << myQueue[i]<<"\n";
	cout << endl;
}