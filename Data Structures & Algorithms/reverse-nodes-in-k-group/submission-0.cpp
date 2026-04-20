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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0,head);
        ListNode*  grouPrev = dummy;
        ListNode* kth = getKth(dummy, k);

        while(true){

            ListNode* kth = getKth(grouPrev, k);
            if(!kth){
                break;
            }
            ListNode* groupNext = kth->next;

            ListNode* prev = kth->next;
            ListNode* cur = grouPrev->next;

            while(cur!=groupNext){
                
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }

            ListNode* tmp = grouPrev->next;
            grouPrev->next = kth;
            grouPrev = tmp;
        }

        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* cur, int k){

        while(cur && k>0){
            cur = cur->next;
            k--;
        }
        return cur;
    }
};
