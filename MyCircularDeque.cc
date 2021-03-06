#include <iostream>
#include <vector>

using namespace std;

// Leetcode 641: 设计循环双端队列

class MyCircularDeque {
private:
    vector<int> dq;
    int cap;
    int front;
    int rear;

public:
    /** Initialize your data structure here. Set the size of the deque to be k.
     */
    MyCircularDeque(int k) {
        cap = k + 1;
        front = 0;
        rear = 0;
        dq.resize(cap);
    }

    /** Adds an item at the front of Deque. Return true if the operation is
     * successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        } else {
            front = (front + cap - 1) % cap;
            dq[front] = value;
        }
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is
     * successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        } else {
            dq[rear] = value;
            rear = (rear + 1) % cap;
        }
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is
     * successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        } else {
            front = (front + 1) % (cap - 1);
        }
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is
     * successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        } else {
            rear = (rear + cap - 1) % cap;
        }
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() { return dq[front]; }

    /** Get the last item from the deque. */
    int getRear() { return dq[(rear + cap - 1) % cap]; }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() { return front == rear; }

    /** Checks whether the circular deque is full or not. */
    bool isFull() { return rear == (front + cap - 1) % cap; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */