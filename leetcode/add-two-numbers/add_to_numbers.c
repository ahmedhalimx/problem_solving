#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new_list = calloc(1, sizeof(struct ListNode));
    size_t l1_number = 0, l2_number = 0, power = 1, sum = 0;

    for (struct ListNode* i = l1; i; i = i->next) {
        l1_number += i->val * power; power *= 10;
    }

    power = 1;
    for (struct ListNode* i = l2; i; i = i->next) {
        l2_number += i->val * power; power *= 10;
    }

    sum = l1_number + l2_number;
    for (struct ListNode* i = new_list; i; i = i->next) {
        i->val = sum % 10; sum /= 10;
        if (sum == 0) break;
        i->next = calloc(1, sizeof(struct ListNode));
    }

    return new_list;
}
