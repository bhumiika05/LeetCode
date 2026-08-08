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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            int sum = carry;

            // Add digit from l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add digit from l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Create a new node with the current digit
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Calculate carry
            carry = sum / 10;
        }

        return dummy->next;

    }
};