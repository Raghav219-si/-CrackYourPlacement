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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow, *curr = slow->next;
        slow->next = NULL;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = head, fast = prev;
        while(curr && curr->next != fast){
            ListNode *temp = curr->next;
            curr->next = fast;
            ListNode *temp2 = fast->next;
            fast->next = temp;
            curr = temp;
            fast = temp2;
        }
    }
};