#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Leetcode 86: 分隔链表

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return NULL;
        ListNode *bigHead = new ListNode(0);
        ListNode *smallHead = new ListNode(0);
        ListNode *ptr = head, *bigPtr = bigHead, *smallPtr = smallHead;
        while (ptr != NULL) {
            if (ptr->val < x) {
                smallPtr->next = ptr;
                smallPtr = ptr;
            } else {
                bigPtr->next = ptr;
                bigPtr = ptr;
            }
            ptr = ptr->next;
        }
        bigPtr->next = NULL;
        smallPtr->next = bigHead->next;
        return smallHead->next;
    }
};