#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int compareTimes = 0;

public:
    void selectionSort(vector<int> &arr) {
        int len = arr.size();
        int swapIdx = 0;
        for (int start = 0; start < len; start++) {
            swapIdx = start;
            for (int i = start + 1; i < len; i++) {
                if (arr[start] > arr[i]) {
                    swapIdx = i;
                }
                compareTimes++;
            }
            swap(arr[start], arr[swapIdx]);
        }
    }
    int getCompareTimes() { return compareTimes; }
};

int main() {
    vector<int> arr{9, 8, 7, 6, 5, 5, 3, 2, 1};
    Solution s;
    s.selectionSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << s.getCompareTimes() << endl;
    return 0;
}