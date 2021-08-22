#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int compareTimes = 0;
    int getPartition(vector<int> &arr, int begin, int end) {
        int root = arr[begin];
        int slow = begin;
        int fast = end + 1;
        while (true) {
            while (arr[++slow] <= root) {
                compareTimes++;
                if (slow == end) {
                    break;
                }
            }
            while (arr[--fast] > root) {
                compareTimes++;
                if (fast == begin) {
                    break;
                }
            }
            if (fast <= slow) {
                break;
            }
            swap(arr[slow], arr[fast]);
        }
        swap(arr[begin], arr[fast]);
        return fast;
    }
    void quickSort(vector<int> &arr, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int partition = getPartition(arr, begin, end);
        quickSort(arr, begin, partition - 1);
        quickSort(arr, partition + 1, end);
    }

public:
    void quickSort(vector<int> &arr) {
        int len = arr.size();
        quickSort(arr, 0, len - 1);
    }
    int getCompareTimes() { return compareTimes; }
};

int main() {
    vector<int> arr{9, 8, 7, 6, 5, 5, 3, 2, 1};
    Solution s;
    s.quickSort(arr);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << s.getCompareTimes() << endl;
    return 0;
}