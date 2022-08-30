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



int findNode(Node *head, int n) {
    if (!head) {
        return -1;
    }
    Node *curr = head;
    int i = 0;
    while (curr) {
        if (curr -> data == n) {
            return i;
        }
        curr = curr -> next;
        ++i;
    }
    return -1;
}