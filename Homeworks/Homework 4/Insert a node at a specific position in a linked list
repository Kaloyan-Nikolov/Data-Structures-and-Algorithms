/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* addTail(SinglyLinkedListNode* head, int data) 
{   
        SinglyLinkedListNode* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
        }
        
        tail->next = new SinglyLinkedListNode(data);
        tail = tail->next;
        return head;         
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    if(position == 0) // add head;
    {        
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        newNode->next = head;
        head = newNode;        
        return head;
    }
    
    SinglyLinkedListNode* prev = head;
    for(int i = 0; i < position - 1; i++)
    {
        prev = prev->next;
    }
    
    if(prev->next == nullptr) // add tail;
    {
        return addTail(head, data);
    }
    else // add at specific position
    {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data); 
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }    
}
