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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> v(k);
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        
        bool flag = true;
        while(flag){
            flag = false;
            int mi = INT_MAX;
            int ind;
            for(int i = 0;i<k;i++){
                if(lists[i] && lists[i]->val<mi){
                    mi = lists[i]->val;
                    ind = i;
                    flag = true;
                }
            }
            
            if(flag){
                curr->next = lists[ind];
                curr = curr->next;
                lists[ind] = lists[ind]->next;
            }
        }
        
        return head->next;
    }
};