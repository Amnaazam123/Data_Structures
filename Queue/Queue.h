//BSEF19M009
//AMNA AZAM
//DSA-LAB#05

#pragma once
template<class T>
class Queue
{
private:
	T* myQueue;
	int size;
	int front;
	int rear;
	int count;
public:
	Queue(int);                //ok
	bool isEmpty();            //ok
	bool isFull();             //ok           
	void enqueue(T);            //push
	T dequeue();                //pop
	int noOfElements();          //count of elements        
	T peek();                    //ok
	int resize(int);             //resize
	Queue(const Queue<T>&);      //copyConstructor
	void showStructure();       //mam said to implement this function into ADT so it is here;)
};