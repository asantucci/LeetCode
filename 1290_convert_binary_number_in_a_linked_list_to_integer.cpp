/* Given head which is a reference node to a singly-linked list. 
   The value of each node in the linked list is either 0 or 1. 
   The linked list holds the binary representation of a number.

   Return the decimal value of the number in the linked list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // First step is to figure out how large the list is, that way we can
    // start with the first node and know what's the magnitude of the MSB. 
    int getLength(ListNode* head) {
        int len{};
        for (ListNode* cur = head; cur != NULL; cur = cur->next)
            len++;
        return len;
    }
    int getDecimalValue(ListNode* head) {
        int len = getLength(head);
        int sum = {};
        // Iterate over the collection, and for each list-element we increment
        // our sum by val * 2^i.
        ListNode* cur = head;
        for (int i = len-1; i >= 0; --i) {
            sum += cur->val * pow(2, i);
            cur = cur->next;
        }
        return sum;
    }
};
