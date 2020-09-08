#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data = 0, Node* next = nullptr) :
		data(data), next(next) {}
};

class LinkedList
{
public:
	Node* head, *tail;
	int size;

	LinkedList()
	{
		head = tail = nullptr;
		size = 0;
	}

	~LinkedList()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		// tail = nullptr;
	}

	void addHead(int data)
	{
		head = new Node(data, head);
		size++;
		if (tail == nullptr)
		{
			tail = head;
		}
	}

	void addTail(int data)
	{
		if (tail != nullptr)
		{
			tail->next = new Node(data);
			tail = tail->next;
		}
		else
		{
			tail = head = new Node(data);
		}
		size++;
	}

	void addAtPos(int pos, int data)
	{
		if (pos <= 0)
		{
			addHead(data);
		}
		else if (pos >= size)
		{
			addTail(data);
		}
		else
		{
			Node* prev = head;
			for (int i = 0; i < pos - 1; i++)
			{
				prev = prev->next;
			}

			prev->next = new Node(data, prev->next);
			size++;
		}
	}

	void print() const
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void delHead()
	{
		if (head == nullptr)
			return;

		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
		if (head == nullptr)
			tail = nullptr;
	}

	void delTail()
	{
		if (head == nullptr)
			return;

		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			size--;
		}
		else
		{
			Node* prev = head;
			while (prev->next != tail)
			{
				prev = prev->next;
			}

			delete tail;
			prev->next = nullptr;
			tail = prev;
			size--;
		}
	}

	void delAtPos(int pos)
	{
		if (pos < 0 || pos >= size)
			return;

		if (pos == 0)
			delHead();
		else if (pos == size - 1)
			delTail();
		else
		{
			Node* prev = head;
			for (int i = 0; i < pos - 1; i++)
			{
				prev = prev->next;
			}

			Node* temp = prev->next;
			prev->next = temp->next;
			delete temp;
			size--;
		}
	}

	void isPalindrome()
	{
		if (size < 2)
		{
			cout << "true" << endl;
			return;
		}

		LinkedList S;
		Node* temp = head;
		for (int i = 0; i < size / 2; i++)
		{
			S.addHead(temp->data);
			temp = temp->next;
		}

		if (size & 1)
			temp = temp->next;

		while (S.size > 0)
		{
			if (S.head->data != temp->data)
			{
				cout << "false" << endl;
				return;
			}
			S.delHead();
			temp = temp->next;
		}

		cout << "true" << endl;
	}

	void reverse()
	{
		Node* prev = nullptr;
		Node* curr = head;
		Node* next = nullptr;

		while (curr != nullptr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

};

class Stack
{
	LinkedList S;
public:
	int size()
	{
		return S.size;
	}

	// the newest element in the stack
	int top()
	{
		if (S.size == 0)
			return -1;
		return S.head->data;
	}

	bool empty()
	{
		return S.size <= 0;
	}

	void push(int val)
	{
		S.addHead(val);
	}

	void pop()
	{
		S.delHead();
	}
};

class Queue
{
	LinkedList S;
public:
	int size()
	{
		return S.size;
	}

	// the oldest element in the queue
	int front()
	{
		if (S.size == 0)
			return -1;
		return S.head->data;
	}

	// the newest element in the queue
	int back()
	{
		if (S.size == 0)
			return -1;
		return S.tail->data;
	}

	bool empty()
	{
		return S.size <= 0;
	}

	void push(int val)
	{
		S.addTail(val);
	}

	void pop()
	{
		S.delHead();
	}
};

int main()
{
	LinkedList L;
	L.addAtPos(1, 20);
	L.addAtPos(2, 40);
	L.addAtPos(3, 75);
	L.addTail(12);
	L.addTail(100);
	L.addHead(5);

	L.print();

	//L.delAtPos(1);
	//L.delAtPos(1);
	//L.delAtPos(1);
	//L.delTail();
	//L.delAtPos(0);
	//L.delTail();

	//L.addHead(1);
	//L.addHead(2);
	//L.addHead(3);
	//L.addHead(2);
	//L.addHead(1);


	L.print();
	L.isPalindrome();
	L.reverse();

	L.print();

	Stack S;
	for (int i = 1; i < 6; i++)
		S.push(i);

	while (!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	cout << "\n";

	Queue Q;
	for (int i = 1; i < 6; i++)
		Q.push(i);

	cout << Q.back() << "\n";
	while (!Q.empty())
	{
		cout << Q.front() << " ";
		Q.pop();
	}
	cout << "\n";

	return 0;
}
