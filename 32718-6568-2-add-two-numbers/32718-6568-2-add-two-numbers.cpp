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

    node add(node l1, node l2, int carry_out) {
        if (l1 == nullptr && l2 == nullptr && carry_out == 0) 
            return nullptr;
            
        int val1 = (l1) ? l1-> val : 0;
        int val2 = (l2) ? l2->val : 0;

        int sum = val1 + val2 + carry_out;
        int carry = 0;

        if (sum >= 10)  {
            sum -= 10;
            carry = 1;
        }

        node head = new ListNode(sum);
               head->next = add((l1) ? l1->next : nullptr, (l2) ? l2->next : nullptr, carry);
 

        return head;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2, 0);
    }
};