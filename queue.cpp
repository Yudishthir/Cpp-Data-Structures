#include <bits/stdc++.h>
using namespace std;
#define MAX 3

class Queue
{
	int queue[MAX];
	int front;
	int back;
	unsigned int size;

public:
	Queue() {
		front = 0;
		back = 0;
		size = 0;
	}	

	void print();
	void enqueue(int value);
	void dequeue();
	unsigned int length();
};

void Queue::print() {
	if(front == back && size != MAX) {
		cout << "Queue is empty\n";
		return;
	}

	int i = back;

	do
	{
		cout << queue[i] << " ";
		i=(i+1)%MAX;
	} while (i != front);
	cout << endl;
}

void Queue::enqueue(int value) {
	if (size == MAX)
		cout << "Queue is full\n";
	else {
		queue[front] = value;
		front = (front+1)%MAX;
		size++;
	}
}

void Queue::dequeue() {
	if (size == 0 && front == back)
		cout << "Queue is empty\n";
	else {
		back = (back+1)/MAX;
		size--;
	}
}

unsigned int Queue::length() {
	return size;
}

int main(int argc, char const *argv[])
{
	Queue q;
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.enqueue(70);
	q.print();
	cout << q.length() << endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout << q.length() << endl;
	q.enqueue(20);
	q.enqueue(0);
	cout << q.length() << endl;
	q.enqueue(10);
	q.print();

	return 0;
}