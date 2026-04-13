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

        ListNode *curr = head;
        int size = 0;
        
        while(curr){
            curr = curr->next;
            size++;
        }

        int target = size - n;

        if (target == 0) {
            return head->next;
        }

        int counter = 0;
        curr = head;
        ListNode *prev;

        while(counter!=target){
            prev = curr;
            curr = curr->next;
            counter++;
        }

        prev->next = curr->next;

        return head;
    }
};
