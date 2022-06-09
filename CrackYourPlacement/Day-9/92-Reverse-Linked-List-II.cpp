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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 1;
        if(!head)
            return head;
        ListNode *prev = NULL, *curr = head;
        ListNode *start = head, *sstart = head;
        
        while(pos <= right){
            if(pos == left){
                start = curr;
                sstart = prev;
            }
            if(pos > left){
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }else{
                prev = curr;
                curr = curr->next;
            }
            pos++;
        }
        if(left != 1){
            sstart->next = prev;
            start->next = curr;
        }
        else{
            start->next = curr;
        }
        if(left != 1)
            return head;
        return prev;
    }
};