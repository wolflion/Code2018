/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL, *iter, *node;
    int carry = 0, sum, op1, op2;
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            op1 = l1->val;
            l1 = l1->next;
        }
        else {
            op1 = 0;
        }
        if (l2 != NULL) {
            op2 = l2->val;
            l2 = l2->next;
        }
        else {
            op2 = 0;
        }
        sum = (op1 + op2 + carry)%10;
        carry = (op1 + op2 + carry)/10;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;
        if (result == NULL) {
            result = node;
            iter = result;
        }
        else {
            iter->next = node;
            iter = node;
        }
    }
    if (carry == 1) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        iter->next = node;
    }
    return result;
}
