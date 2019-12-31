//Simple implementation of queue using array
#include <iostream>

#define N 20 //array size

class Queue {
	int head;
	int tail;

public:
	int a[N];

	Queue() { head = 0; tail = 0; }
	bool enq(int x);
	int deq();
	int peek();
	bool isEmpty();
};

//DONE
bool Queue::enq(int x)
{
	if ((head == (tail + 1)) | ((head == 0) & (tail == (N - 1))))
	{
		std::cout << "Queue overflow";
		return false;
	}
	else if (tail > (N - 1))
	{
		tail = 0;
		a[tail++] = x;
		return true;
	}
	else
	{
		a[tail] = x;
		tail++;
		return true;
	}
}

//DONE
int Queue::deq()
{
	if (isEmpty())
	{
		std::cout << "Queue underflow\n";
		return -1;
	}
	else if (head >= (N - 1))
	{
		int x = a[head];
		head = 0;
		return x;
	}
	else
	{
		int x = a[head];
		head++;
		return x;
	}
	}

	//DONE
	int Queue::peek()
	{
		if (isEmpty())
		{
			std::cout << "Queue is empty\n";
			return -1;
		}
		else
		{
			int x = a[head];
			return x;
		}
	}

	//DONE
	bool Queue::isEmpty()
	{
		if (head == tail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}




	int main(int argc, char* argv[])
	{
		class Queue s;
		s.enq(10);
		s.enq(20);
		s.enq(30);
		std::cout << s.deq() << '\n' << s.deq() << '\n' << s.deq() << '\n';
		std::cout << s.deq() << '\n';
		s.enq(10);
		s.enq(20);
		s.enq(30);
		std::cout << s.deq() << '\n';
		std::cout << s.deq() << '\n';
		std::cout << s.deq() << '\n';
		
	}

