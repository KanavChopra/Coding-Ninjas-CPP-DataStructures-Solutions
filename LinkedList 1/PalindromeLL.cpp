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

// After finding middle
//     s     f
// 1 2 3 3 2 1

// Now, slow -> next contains linekd list 3 2 1
// reversedLL(slow -> next) = 1 2 3
// so, slow -> next = reversedLL(slow -> next) is as follow
//     s     f
// 1 2 3 1 2 3

// After, slow = slow -> next
//       s   f
// 1 2 3 1 2 3

Node *reversedLL(Node *head) {
    if (!head || !head -> next) {
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr) {
        Node *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head) {
    if (!head || !head -> next) {
        return true;
    }
    Node *slow = head;
    Node *fast = head -> next;
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    slow -> next = reversedLL(slow -> next);
    slow = slow -> next;
    Node *curr = head;
    while (slow) {
        if (slow -> data != curr -> data) {
            return false;
        }
        slow = slow -> next;
        curr = curr -> next;
    }
    return true;
}
