class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);          // dummy head
        ListNode* curr = &dummy;    // tail pointer

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;     // attach l1 node
                list1 = list1->next;
            } else {
                curr->next = list2;     // attach l2 node
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // attach remaining list
        curr->next = list1 ? list1 : list2;

        return dummy.next;
    }
};