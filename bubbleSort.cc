#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int compareTimes = 0;

public:
    void bubbleSort(vector<int> &arr) {
        int len = arr.size();
        bool isSwap = false;
        for (int i = 0; i < len; i++) {
            isSwap = false;
            for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    isSwap = true;
                }
                compareTimes++;
            }
            if (!isSwap) {
                return;
            }
        }
    }
    int getCompareTimes() { return compareTimes; }
};

int main() {
    vector<int> arr{9, 8, 7, 6, 5, 5, 3, 2, 1};
    Solution s;
    s.bubbleSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << s.getCompareTimes() << endl;
    return 0;
}