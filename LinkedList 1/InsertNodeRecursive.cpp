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
Node *insertNodeHelper(Node *head, int pos, int data, int length) {
    if (!head || pos > length) {
        return head;
    } 
    if (pos == 0) {
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node *newHead = insertNodeHelper(head -> next, pos - 1, data, length - 1);
    head -> next = newHead;
    return head;
}
Node* insertNode(Node *head, int pos, int data) {
    int len = length(head);
    return insertNodeHelper(head, pos, data, len);
}
