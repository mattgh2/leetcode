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
    typedef ListNode* node;
    node soln(node T1, node T2) {
        if (T1 == nullptr && T2 == nullptr) {
            return nullptr;
        }

        int val = 0;
        if (T1 && !T2) {
            val = T1->val;
            T1 = T1->next;
        } else if (!T1 && T2) {
            val = T2->val;
            T2 = T2->next;
        } else {
            if (T1->val < T2->val) {
                val = T1->val;
                T1 = T1->next;
            } else {
                val = T2->val;
                T2 = T2->next;
            }
        }
        node head = new ListNode(val);

        head->next = soln(T1, T2);

        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return soln(list1, list2);
    }
};