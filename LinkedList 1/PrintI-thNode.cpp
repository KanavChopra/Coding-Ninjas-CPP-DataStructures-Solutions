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
void printIthNode(Node *head, int pos) {
    int len = length(head);
    if (!head) {
        return;
    }
    if (pos > len) {
        return;
    }
    Node *curr = head;
    for (int i = 0; i < pos - 1; ++i) {
        curr = curr -> next;
    }
    cout << curr -> next -> data << endl;
}