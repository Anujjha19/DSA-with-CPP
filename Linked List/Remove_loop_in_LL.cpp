/* ListNode *detectCycle(ListNode *head) {
        if( head == NULL || head -> next == NULL ) return NULL;
       ListNode * slow = head ;
        ListNode* fast = head;
        ListNode* tempEntry = head ;

        while( fast-> next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow -> next ;
            if( slow == fast ){
                while( slow != tempEntry ){
                        tempEntry = tempEntry -> next ;
                        slow = slow -> next ;
                }
                return slow;
            }
        }
            return NULL;

    } */

Node *intersection_FDM(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    if (head == NULL || head->next == NULL)
        return NULL;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return slow;
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = intersection_FDM(head);

    if (intersection == NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

/* Node *detect(Node *head)

{

    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
void removeLoop(Node *head)
{ //code here    just remove the loop without losing any nodes

if (head == NULL)
        return;
    Node *first = detect(head);
    if (first == NULL)
        return;
    Node *temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

 */