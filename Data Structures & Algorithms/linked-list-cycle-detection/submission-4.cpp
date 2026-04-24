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
    bool hasCycle(ListNode* head) {
        // fast and slow ptr i think
        ListNode* fast;
        ListNode* slow;

        fast = head;
        slow = head;

        while(fast && slow){
            if (fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return true;
            }
        }

        return false;
    }
};
