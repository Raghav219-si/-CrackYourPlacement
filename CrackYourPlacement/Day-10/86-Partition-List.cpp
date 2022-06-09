// O(n) O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *smallh = small, *bigh = big;
        ListNode *curr = head;
        
        while(curr){
            
            if(curr->val < x){
                smallh->next = curr;
                smallh = smallh->next;
            }
            else{
                bigh->next = curr;
                bigh = bigh->next;
            }
            curr =curr->next;
        }
        smallh->next = big->next;
        bigh->next = NULL;
        return small->next;
    }
};