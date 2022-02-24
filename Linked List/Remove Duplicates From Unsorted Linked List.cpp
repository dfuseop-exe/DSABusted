/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where N is the number of nodes in the Linked list.
*/

Node *removeDuplicates(Node *head)
{
    Node *p, *q;
    p = head;

    // Outer loop to pick element.
    while (p != NULL)
    {
        // Initialize the inner loop pointer.
        q = p->next;

        // Keep track of previous node.
        Node *prev = p;

        while (q != NULL)
        {
            if (p->data == q->data)
            {
                // Found a duplicate of node 'p'. Now, we need to remove it.
                // Firstly update the next pointer of the previous node.
                prev->next =  

                // Delete the duplicate node.
                delete q;

                // Move the inner loop pointer to the next node.
                q = prev->next;
            }
            else
            {
                // Node 'q' is not a duplicate. So, move to the next node.
                prev = q;
                q = q->next;
            }
        }

        // Move the outer loop pointer to the next node.
        p = p->next;
    }

    return head;
}

