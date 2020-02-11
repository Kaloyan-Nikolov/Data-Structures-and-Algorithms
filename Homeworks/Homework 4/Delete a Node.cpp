// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) 
{
    if(position == 0) // delete head
    {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    SinglyLinkedListNode* prev = head;
    for(int i = 0; i < position - 1; i++)
    {
        prev = prev->next;
    }
    
    if(prev->next->next == nullptr) // delete tail
    {
        SinglyLinkedListNode* temp = prev->next;
        prev->next = nullptr;
        delete temp;
        return head;
    }
    else
    {
        SinglyLinkedListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        return head;
    }
}
