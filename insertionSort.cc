#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int compareTimes = 0;

public:
    void insertionSort(vector<int> &arr) {
        int len = arr.size();
        for (int start = 1; start < len; start++) {
            int i = start;
            int tmp = arr[start];
            while (i > 0 && tmp < arr[i - 1]) {
                compareTimes++;
                arr[i] = arr[i - 1];
                i--;
            }
            arr[i] = tmp;
        }
    }
    int getCompareTimes() { return compareTimes; }
};

int main() {
    vector<int> arr{9, 8, 7, 6, 5, 5, 3, 2, 1};
    Solution s;
    s.insertionSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << s.getCompareTimes() << endl;
    return 0;
}