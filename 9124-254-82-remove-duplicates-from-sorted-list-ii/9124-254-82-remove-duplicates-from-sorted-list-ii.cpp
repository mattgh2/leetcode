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
typedef ListNode * node;
    ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr) {
        return head;
    }

    node prev_prev = nullptr, prev = head, current = head->next;

    while (current != nullptr) {
        bool ok = false;
        if (prev->val == current->val) {
            ok = true;
            while (current != nullptr && prev->val == current->val) {
                current = current->next;
            }
            if (current == nullptr) {
                if (prev_prev == nullptr) {
                    return nullptr;
                }
                prev_prev->next = current;
            }
            else {

                if (prev_prev == nullptr) {
                    head = current;
                }
                else {
                    prev_prev->next = current;

                }
            }

        }
        prev_prev = ((!ok) ? prev : prev_prev);
        prev = current;
        if (current) current=current->next;
    }
    return head;

    }
};