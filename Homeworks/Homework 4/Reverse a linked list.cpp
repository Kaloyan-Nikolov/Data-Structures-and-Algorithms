// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* next = nullptr;   
   
    while(curr != nullptr)
    {        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    
    return head;
}
