#include "Queue.h"
#include <iostream>
using namespace std;
template <typename T>
Queue<T>::Queue(int q) {
	size = q > 0 ? q : 10;
	ptr = new T[size];
	head = 0;
	tail = 0;
}
template <typename T>
Queue<T>::~Queue() {
	delete[] ptr;
}
template <typename T>
bool Queue<T>::push(const T value) {
	if (tail + 1 == head || (tail + 1 == size && !head)) {
		cout << "Queue is full" << endl;
		return 0; 
	}
	tail++;
	if (tail == size) tail = 0;
	ptr[tail] = value;
}
template <typename T>
bool Queue<T>::pop() {
	if (head==tail) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	head++;
	if (head == size) head = 0;
}
template <typename T>
void Queue<T>::Union(Queue<T>& q1, Queue<T>& q2, Queue<T>& q3) {
	while (q1.head!=0 && q2.head!=0) {
		if (q2.front() < q1.front()) {
			q3.push(q2.front());
			q2.pop();
		}
		else {
			q3.push(q1.front());
			q1.pop();
		}
	}
	while (q1.head != 0) {
		q3.push(q1.front());
		q1.pop();
	}
	while (q2.head != 0) {
		q3.push(q2.front());
		q2.pop();
	}
}
template<typename T>
void Queue<T>::Print() {
	if (head == 0 && tail == 0) cout << "Queue is empty" << endl;
	else {
		for (int i = tail; i > head; i--) {
			cout << ptr[i] << ' ';
		}
		cout << endl;
	}
}
int main() {
	Queue<int> q(3);
	Queue<int> q1(3);
	Queue<int> q2(6);
	//q.Print();
	q.push(15);
	//q.Print();
	q.push(8);
	//q.Print();
	q.pop();
	//q.Print();
	//q1.push(4);
	//q1.push(7);
	q2.Union(q, q1, q2);
	q2.Print();
	return 0;
}