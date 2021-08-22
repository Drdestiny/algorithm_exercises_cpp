#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *rhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rhead;
    }

public:
    bool validatePanlindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        while (fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode *newHead;
        if (fastPtr != NULL) {  // 奇数
            newHead = reverseList(slowPtr->next);
        } else {  // 偶数
            newHead = reverseList(slowPtr);
        }
        ListNode *cur1 = head;
        ListNode *cur2 = newHead;
        for (; cur2 != NULL; cur1 = cur1->next, cur2 = cur2->next) {
            if (cur1->val != cur2->val) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ListNode *oddHead = new ListNode(1);
    ListNode *evenHead = new ListNode(1);
    ListNode *oddSecond = new ListNode(2);
    ListNode *evenSecond = new ListNode(2);
    ListNode *oddThird = new ListNode(1);
    ListNode *evenThird = new ListNode(2);
    ListNode *evenFourth = new ListNode(1);
    oddHead->next = oddSecond;
    oddSecond->next = oddThird;
    evenHead->next = evenSecond;
    evenSecond->next = evenThird;
    evenThird->next = evenFourth;

    Solution s;
    cout << s.validatePanlindrome(oddHead) << endl;
    cout << s.validatePanlindrome(evenHead) << endl;

    // ListNode *newEvenHead = s.reverseList(evenHead);
    // ListNode *cur = newEvenHead;
    // for (; cur != NULL; cur = cur->next) {
    //     cout << cur->val << endl;
    // }
    return 0;
}