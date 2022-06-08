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
        ListNode *head = NULL;
        ListNode *curr1 = l1, *curr2 = l2;
        stack<int> num1, num2, num;
        
        while(curr1){
            num1.push(curr1->val);
            curr1 = curr1->next;
        }
        
        while(curr2){
            num2.push(curr2->val);
            curr2 = curr2->next;
        }
        
        curr1 = head;
        int carry = 0;
        while(!num1.empty() || !num2.empty()){
            int n1 = 0, n2 = 0;
            if(!num1.empty()){
                n1 = num1.top();
                num1.pop();
            }
            if(!num2.empty()){
                n2 = num2.top();
                num2.pop();
            }
            int sum = carry+n1+n2;
            carry = sum/10;
            curr1 = new ListNode(sum%10);
            curr1->next = head;
            head = curr1;
        }
        if(carry){
            curr1 = new ListNode(1);
            curr1->next = head;
            head = curr1;
        }
        
        return head;
    }
};