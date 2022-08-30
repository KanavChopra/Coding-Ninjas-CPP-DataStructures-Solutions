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
    // Revursive Solution
    if (!head) {
        return 0;
    }
    return 1 + length(head -> next);
    
    // Iterative Solution
    // if (!head) {
    //     return 0;
    // }
    // Node *curr = head;
    // int len = 0;
    // while (curr) {
    //     len++;
    //     curr = curr -> next;
    // }
    // return len;
}