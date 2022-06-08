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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1, *curr2 = l2, *curr;
        ListNode *head = new ListNode(0);
        curr = head;
        int carry = 0, sum = 0;
        int v1 = 0, v2 = 0;
        while(curr1 || curr2){
            if(curr1){
                v1 = curr1->val;
                curr1 = curr1->next;
            }
            else
                v1 = 0;
            if(curr2){
                v2 = curr2->val;
                curr2 = curr2->next;
            }
            else
                v2 = 0;
            sum = carry+v1+v2;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};