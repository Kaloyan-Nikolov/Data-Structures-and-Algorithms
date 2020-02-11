// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedList result;    
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            result.insert_node(head1->data);
            head1 = head1->next;
        }
        else
        {
            result.insert_node(head2->data);
            head2 = head2->next;
        }
    }

    while (head1 != nullptr)
    {
        result.insert_node(head1->data);
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        result.insert_node(head2->data);
        head2 = head2->next;
    }
    
    return result.head;
}
