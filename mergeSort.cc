#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int compareTimes = 0;
    vector<int> aux;
    void merge(vector<int> &arr, int start, int end) {
        for (int i = start; i <= end; i++) {
            aux[i] = arr[i];
        }
        int mid = start + (end - start) / 2;
        int ptr1 = start;
        int ptr2 = mid + 1;
        int idx = start;
        for (int idx = start; idx <= end; idx++) {
            if (ptr1 > mid) {
                arr[idx] = aux[ptr2++];
            } else if (ptr2 > end) {
                arr[idx] = aux[ptr1++];
            } else if (aux[ptr1] <= aux[ptr2]) {
                arr[idx] = aux[ptr1++];
            } else {
                arr[idx] = aux[ptr2++];
            }
            compareTimes++;
        }
    }

    void sort(vector<int> &arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        sort(arr, start, mid);
        sort(arr, mid + 1, end);
        merge(arr, start, end);
    }

public:
    void mergeSort(vector<int> &arr) {
        int len = arr.size();
        aux = vector<int>(len, 0);
        sort(arr, 0, len - 1);
    }
    int getCompareTimes() { return compareTimes; }
};

int main() {
    vector<int> arr{9, 8, 7, 6, 5, 5, 3, 2, 1};
    Solution s;
    s.mergeSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << s.getCompareTimes() << endl;
    return 0;
}