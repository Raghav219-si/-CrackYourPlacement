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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *nhead = new ListNode(1000);
        nhead->next = head;
        ListNode *itr = nhead, *curr = head->next;
        bool flag = false;
        while(true){
            flag = false;
            while(curr && itr->next->val == curr->val){
                flag = true;
                curr = curr->next;
            }
            if(flag){
                itr->next = curr;
            }
            else{
                itr = itr->next;
            }
            if(!curr)
                break;
            curr = curr->next;
        }
        return nhead->next;
    }
};