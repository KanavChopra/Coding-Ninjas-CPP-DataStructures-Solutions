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

int length(Node *head) {
    if (!head) {
        return 0;
    }
    return 1 + length(head -> next);
}
Node *deleteNodeRecHelper(Node *head, int pos, int length) {
    if (!head || pos > length) {
        return head;
    }
    if (pos == 0) {
        Node *temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node *newHead = deleteNodeRecHelper(head -> next, pos - 1, length - 1);
    head -> next = newHead;
    return head;
}
Node *deleteNodeRec(Node *head, int pos) {
    int len = length(head);
    return deleteNodeRecHelper(head, pos, len);
}