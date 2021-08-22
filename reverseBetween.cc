#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *successor = NULL;
    // 反转链表前n个节点
    ListNode *reverseN(ListNode *head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode *newHead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return newHead;
    }

public:
    // 反转第m个节点到第n个节点
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};
