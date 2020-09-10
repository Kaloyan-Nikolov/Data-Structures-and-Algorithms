#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data = 0, Node* next = nullptr)
        : data(data), next(next) {}
};

class LinkedList
{
public:
    void addHead(int val)
    {
        Node* newNode = new Node(val, head);
        head = newNode;
        size++;
    }

    void addTail(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            size++;
            return;
        }

        Node* tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = new Node(val);
        tail = tail->next;
        size++;
    }

    void add(int val, int pos)
    {
        if (pos < 0 || pos > size)
        {
            cout << "add_last";
            addTail(val);
        }
        else if (pos == 0)
            addHead(val);
        else if (pos == size)
            addTail(val);
        else
        {
            Node* prev = head;
            for (int i = 0; i < pos - 1; i++)
            {
                prev = prev->next;
            }

            prev->next = new Node(val, prev->next);
            size++;
        }
    }

    void print()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "#";
            temp = temp->next;
        }
    }

    void delHead()
    {
        if (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void delTail()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            size--;
        }
        else
        {
            Node* prev = head;
            while (prev->next->next != nullptr)
            {
                prev = prev->next;
            }

            Node* temp = prev->next;
            delete temp;
            prev->next = nullptr;
            size--;
        }
    }

    void remove(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "remove_failed";
            return;
        }
        if (pos == 0)
        {
            delHead();
        }
        else if (pos == size - 1)
        {
            delTail();
        }
        else
        {
            Node* prev = head;
            for (int i = 0; i < pos - 1; i++)
            {
                prev = prev->next;
            }

            Node* temp = prev->next;
            prev->next = temp->next;
            size--;
            delete temp;
        }
    }

    void reverse()
    {
        Node* next = nullptr;
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void remove_all(int val)
    {
        Node* temp = head;
        int ind = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                temp = temp->next;
                remove(ind);
            }
            else
            {
                ind++;
                temp = temp->next;
            }
        }
    }

    void group(int a, int b)
    {
        if (a < 0 || b < 0 || a > size - 1 || b > size - 1 || b < a)
        {
            cout << "fail_grouping";
            return;
        }

        if (a == b)
            return;

        int sum = 0;
        Node* temp = head;
        int cnt = 0;
        while (cnt <= b)
        {
            if (cnt >= a && cnt <= b)
            {
                sum += temp->data;
                temp = temp->next;
                remove(cnt);
                b--;
            }
            else
            {
                cnt++;
                temp = temp->next;
            }
        }

        add(sum, a);
    }

    void count(int val)
    {
        Node* temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
                cnt++;
            temp = temp->next;
        }
        cout << cnt;
    }

    void is_palindrome()
    {
        if (size < 2)
        {
            cout << "true";
            return;
        }

        LinkedList l;
        Node* temp = head;
        for (int i = 0; i < size / 2; i++)
        {
            l.addHead(temp->data);
            temp = temp->next;
        }

        if (size & 1)
            temp = temp->next;

        while (l.size > 0)
        {
            if (l.head->data != temp->data)
            {
                cout << "false";
                return;
            }
            l.delHead();
            temp = temp->next;
        }

        cout << "true";
    }

    ~LinkedList()
    {
        Node* temp = head;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

private:
    int size;
    Node* head;
};

int main()
{
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) 
    {
        LinkedList ll;
        int ops;
        std::string op;
        std::cin >> ops;
        for (int j = 0; j < ops; j++) 
        {
            std::cin >> op;

            if (op == "count") 
            {
                int arg1;
                std::cin >> arg1;
                ll.count(arg1);
            }

            if (op == "add") 
            {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.add(arg1, arg2);
            }

            if (op == "print") 
            {
                ll.print();
            }

            if (op == "remove") 
            {
                int arg1;
                std::cin >> arg1;
                ll.remove(arg1);
            }

            if (op == "reverse")
            {
                ll.reverse();
            }

            if (op == "remove_all")
            {
                int arg1;
                std::cin >> arg1;
                ll.remove_all(arg1);
            }

            if (op == "group") 
            {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.group(arg1, arg2);
            }

            if (op == "is_palindrom") 
            {
                ll.is_palindrome();
            }
        }

        std::cout << std::endl;

    }
    return 0;
}
