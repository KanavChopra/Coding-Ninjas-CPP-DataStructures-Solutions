/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

// Here I have used the approach of n-th node from end of LL taught by Striver

Node *appendLastNToFirst(Node *head, int n) {
    if (!head || n == 0) {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < n; ++i) {
        fast = fast -> next;
    }
    while (fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }
    Node *temp = slow -> next;
    slow -> next = NULL;
    fast -> next = head;
    head = temp;
    return head;
}