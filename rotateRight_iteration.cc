#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Leetcode 61: 旋转链表
// 迭代

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *cur = head;
        int len = 1;
        while (cur->next != NULL) {
            len++;
            cur = cur->next;
        }
        ListNode *last = cur;
        int newK = k % len;
        if (newK == 0)
            return head;
        cur = head;
        for (int i = 0; i < len - newK - 1; i++) {
            cur = cur->next;
        }
        ListNode *newHead = cur->next;
        cur->next = NULL;
        last->next = head;
        return newHead;
    }
};