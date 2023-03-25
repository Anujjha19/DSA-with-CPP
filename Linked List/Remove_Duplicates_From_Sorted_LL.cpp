ListNode *deleteDuplicates(ListNode *head)
{

    if (head == NULL)
        return NULL;

    ListNode *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->val != curr->next->val)
        {
            curr = curr->next;
        }
        else
        {
            ListNode *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        }
    }
    return head;
}

/* Node * uniqueSortedList(Node * head) {
    // Write your code here.
    //Empty List
    if(head == NULL){
return NULL;
    }
    Node* curr =head;
    //Non-Empty List
    while(curr != NULL){
    if((curr -> next != NULL ) &&  curr-> data == curr -> next -> data){
        Node* next_next= curr ->  next -> next ;
        Node * nodeToDelete = curr -> next;
        delete( nodeToDelete);
        curr -> next = next_next;
    }else{
        //Not Equal
        curr = curr -> next;
    }
}
    return head;
}
 */