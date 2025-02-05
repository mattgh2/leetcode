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
    auto soln(node prev, node current) -> node {

        if (current == nullptr) {
            return prev;
        }

        node nxt = current->next;
        current->next = prev;

        node head = soln(current, nxt);

        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return soln(nullptr, head);
    }
};