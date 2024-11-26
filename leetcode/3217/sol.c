#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool binary_search(int *arr, int size, int val) {
	int start = 0, end = size - 1;

	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] == val) return true;
		else if (arr[mid] < val) start = mid + 1;
		else if (arr[mid] > val) end = mid - 1;
	}

	return false;
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head)
{
        struct ListNode *new_head = NULL;

	for (struct ListNode *i = head; i; i = i->next) {
		if (linear_search(nums, numsSize, i->val)) continue;

		new_head = i;
		break;
	}

	for (struct ListNode *i = new_head, *j = new_head->next; j; j = j->next) {
		if (linear_search(nums, numsSize, i->val)) {
			i->next = j->next;
		} else {
			i = i->next;
		}
	}

	return (new_head);
}
