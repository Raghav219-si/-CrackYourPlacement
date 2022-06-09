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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL, *slow = head, *fast = head;
        int i = 1;
        while(i <= n && fast){
            fast = fast->next;
            i++;
        }
        
        while(fast){
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        if(!prev)
            return head->next;
        prev->next = slow->next;
        delete slow;
        slow = NULL;
        return head;
    }
};