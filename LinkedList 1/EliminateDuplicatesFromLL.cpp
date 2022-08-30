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

Node *removeDuplicates(Node *head) {

	// Approach 1
    // if (!head || !head -> next) {
    //     return head;
    // }
    // Node *prev = head;
    // Node *curr = head -> next;
    // while (curr) {
    //     if (curr -> data == prev -> data) {
    //         curr = curr -> next;
    //     } else {
    //         prev -> next = curr;
    //         prev = curr;
    //         curr = curr -> next;
    //     }
    // }
    // // consider the case:
    // // 1 2 3 4 5 5 5 N
    // // 		   p     c
    // // in this case when curr == NULL
    // // loop breaks and thus we simply
    // // put prev -> next = curr.
    // prev -> next = curr;
    // return head;
    

    // Approach 2
    // if (!head || !head -> next) {
    // 	return head;
    // }
    // Node *curr = head;
    // while (curr -> next) {
    //     if (curr -> data == curr -> next -> data) {
    //         curr -> next = curr -> next -> next;
    //     } else {
    //         curr = curr -> next;
    //     }
    // }
    // return head;
    
    
    // Approach 3
    if (!head || !head -> next) {
        return head;
    }
    while (head -> next && head -> data == head -> next -> data) {
        head -> next = head -> next -> next;
    }
    removeDuplicates(head -> next);
    return head;
}