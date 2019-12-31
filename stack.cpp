//Simple implementation of stack using array
#include <iostream>

#define N 20 //array size
 
class Stack { 
    int top; 
  
public: 
    int a[N]; 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
 
bool Stack::push(int x)
{
	if (top >= (N - 1))
	{
		cout << "Stack overflow";
		return false;
	}
	else
	{
		top++;
		a[top] = x;
		return true;
	}
}
 
int Stack::pop()
{
	if (top == -1)
	{
		cout << "Stack underflow";
		return 0;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}

int Stack::peek()
{
	if (top == -1)
	{
		cout << "Stack is empty";
		return 0;
	}
	else
	{
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	if (top == -1)
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
	class Stack s; //defined an instance of Stack class called s
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << '\n' << s.pop() << '\n' << s.pop();
}

