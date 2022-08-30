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

// We always store that node which we want to delete

int length(Node *head) {
    if (!head) {
        return 0;
    }
    return 1 + length(head -> next);
}
Node *deleteNode(Node *head, int pos) {
    // base case
    if (!head || (pos >= length(head))) {
        return head;
    }
    if (pos == 0) {
        Node *temp = head; // store the node which we want to delete
        head = head -> next; // update the head
        delete temp; // delete the node
        return head;
    }
    Node *curr = head;
    // consider the sample input 1:
    // linked list : 3 4 5 2 6 1 9 -1
    // pos : 2 (I have to delete the node 2)
    // why i iterate one position before the required ? 
    // because when i delete the i-th node i have to establish the link between 
    // the previous node and next node to the i-th node. 
    for (int i = 0; curr && i < pos - 1; ++i) {
        curr = curr -> next;
    }
    Node *temp = curr -> next;
    Node *nextNode = temp -> next;
    delete temp;
    curr -> next = nextNode;
    return head;
}