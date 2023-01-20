//BSEF19M009
//AMNA AZAM
//DSA-LAB#05

#include<iostream>
#include"Queue.cpp"
using namespace std;
int main()
{
	Queue<double> QueueObj(5);
	QueueObj.enqueue(5.0);
	QueueObj.enqueue(6.5);
	QueueObj.showStructure();
	QueueObj.enqueue(-3.0);
	QueueObj.enqueue(-8.0);
	QueueObj.showStructure();
	QueueObj.dequeue();
	QueueObj.dequeue();
	QueueObj.showStructure();
	cout << endl;
	return 0;
}