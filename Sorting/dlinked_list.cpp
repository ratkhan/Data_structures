//Implementation of doubly linked list as a class 
#include <iostream>



class Dlinked_list {
private:	
	struct Node
	{
		Node* pprev;
		Node* pnext;
		int info;
	};
	struct Node* head = new Node;
	struct Node* tail = new Node;

public:
	//Default constructor creates a Dlinked list with Head and Tail pointing to NULL
	Dlinked_list() {
		head->pprev = NULL; head->pnext = NULL; head->info = NULL;
		tail->pprev = NULL; tail->pnext = NULL; tail->info = NULL;
	};
	bool Inserthead(int n);
	bool deletenode(int n);
	void printnode();
};

bool Dlinked_list::Inserthead(int n)
{
	struct Node* newNode = new Node;
	//case for the first node
	if (head->info == NULL)
	{
		head->info = n;
		tail->info = n;
		//std::cout << "Inserted a new head";
		return true;
	}
	//if first node exists
	else
	{
		newNode->info = n;
		newNode->pnext = head;
		newNode->pprev = NULL;
		head->pprev = newNode;
		head = newNode;
		return true;
	}
}

void Dlinked_list::printnode()
{
	struct Node* printNode = head;
	if (head->info == NULL)
	{
		std::cout << "List empty";
		return;
	}
	while (printNode != NULL)
	{
		std::cout << printNode->info << "\n";
		printNode = printNode->pnext;
	}
	return;
}


bool Dlinked_list::deletenode(int n)
{
	Node* NodeDel = head;
	//if its a head and its the only member
	if (((NodeDel->info) == n) && ((NodeDel->pnext) == NULL))
	{
		head->info = NULL;
		tail->info = NULL;
		return true;
	}
	else if (((NodeDel->info) == n) && ((NodeDel->pnext) != NULL))
	{
		head->pnext->pprev = NULL;
		head = head->pnext;
		delete NodeDel;
		return true;
	}
	//if its in the middle
	while (((NodeDel->pnext) != NULL) || ((NodeDel->info) != NULL)) //its not the tail or the head
	{
		if (((NodeDel->info) == n) && ((NodeDel->pnext) == NULL)) //for the tail
		{
			NodeDel->pprev->pnext = NULL;
			delete NodeDel;
			return true;
		}
		if (((NodeDel->info) == n)) //if you found it
		{
			NodeDel->pprev->pnext = NodeDel->pnext;
			NodeDel->pnext->pprev = NodeDel->pprev;
			delete NodeDel;
			return true;
		}
		NodeDel = NodeDel->pnext;
	}
	return false;
}

int main(int argc, char* argv[]) {
	Dlinked_list list;
	list.Inserthead(50);
	list.Inserthead(40);
	list.Inserthead(30);
	list.deletenode(30);
	list.Inserthead(20);
	list.Inserthead(60);
	list.deletenode(50);
	list.deletenode(40);
	list.deletenode(60);
	list.deletenode(20);
	list.printnode();
}