#include <vector>
#include <iostream>
using namespace std;

struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
    void delHead()
    {
        if(head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }        
    }
    
    void delTail()
    {
        if(!head)
            return;
        if(!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* prev = head;
            while(prev->next->next)
            {
                prev = prev->next;
            }
            
            Node* temp = prev->next;
            prev->next = nullptr;
            delete temp;            
        }        
    }
    
    void delAtPos(int pos, int size)
    {
        if(pos == 0)
        {
            delHead();            
        }
        else if(pos == size - 1)
        {
            delTail();            
        }
        else
        {
            Node* prev = head;
            for(int i = 0; i < pos - 1; i++)
            {
                prev = prev->next;
            }
            
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }
        size--;
    }  
    
    void removeComplex(int devidedBy){
        int size = 0;
        Node* temp = head;
        while(temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        
        temp = head;        
        
        int cnt = 0;
        while(temp != nullptr)
        {
            if(temp->data % devidedBy == 0)
            {
                temp = temp->next;
                delAtPos(cnt, size);                
            }
            else
            {
                cnt++;
                temp = temp->next;
            }
        }     
    } // end removeComplex
    private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}
