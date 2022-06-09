/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* helper(Node *head){
        if(!head){
            return head;
        }
        Node *curr = head, *flast = NULL;
        while(curr){
            Node *last = helper(curr->child);
            if(last){
                Node *temp = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                if(temp)
                    temp->prev = last;
                last->next = temp;
                curr->child = NULL;
            }
            if(curr->next);
                flast = curr;
            curr = curr->next;
        }
        return flast;
    }
    
    Node* flatten(Node* head) {
        Node *last = helper(head);
        return head;
    }
};