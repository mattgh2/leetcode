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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;

        // Find the size of the LL.
        int n = 0;
        node tail = nullptr;
        for (node current = head; current != nullptr;) {
            tail = current;
            current = current->next;
            ++n;
        }
        // shrink k down.
        k = k % n;

        if (k == 0) {
            return head;
        }

        tail->next = head;
        tail = nullptr;

        for (int i = 0; i < n - k; ++i) {
            tail = head;
            head = head->next;
        }
        tail->next = nullptr;

        return head;
    }
};