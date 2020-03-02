#pragma once
template <typename T>
class Queue
{
private:
	T* ptr;
	int size;
	T head;
	T tail;
public:
	Queue(int = 10);
	~Queue() {
		while (head) {
			tail=head->
		}
	}
	bool push(const T);
	bool pop();
	bool empty() const {
		return head = 0;
	}
	int front() {
		return ptr[head + 1];
	}
	void Print();
	void Union(Queue<T>& q1, Queue<T>& q2, Queue<T>& q3);
};

