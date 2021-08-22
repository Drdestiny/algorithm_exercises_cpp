#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *successor;
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
    // 每个函数功能的分工要明确，返回值的分工也要明确
    // reverseN返回的是反转后的新head，而reverseBetween就返回总的head
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

public:
    // reverseKGroup返回的是将head之后的链表全部按k个一组反转过后得到的新head
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *nextGroupOldHead = head;
        for (int i = 0; i < k; i++) {
            if (nextGroupOldHead == NULL) {
                return head;
            }
            nextGroupOldHead = nextGroupOldHead->next;
        }
        ListNode *newHead = reverseN(head, k);
        head->next = reverseKGroup(nextGroupOldHead, k);
        return newHead;
    }
};

int main() {
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    first->next = second;
    second->next = third;
    third->next = fourth;
    Solution s;
    ListNode *newHead = s.reverseKGroup(first, 2);
    for (ListNode *cur = newHead; cur != NULL; cur = cur->next) {
        cout << cur->val << endl;
    }
    return 0;
}