#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        int len = S.size();
        if (len == 0)
            return S;
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string retStr;
        if (K == 1) {
            int curPtr, minPtr, minPtrHead = 0;
            for (int offset = 1; offset < len; offset++) {
                for (int i = 0; i < len; i++) {
                    curPtr = (offset + i) % len;
                    minPtr = (minPtrHead + i) % len;
                    if (S[curPtr] > S[minPtr]) {
                        break;
                    } else if (S[curPtr] < S[minPtr]) {
                        minPtrHead = offset % len;
                        break;
                    } else {
                        continue;
                    }
                }
            }
            for (int i = 0; i < len; i++) {
                retStr += S[(minPtrHead + i) % len];
            }
        }
        return retStr;
    }
};

int main() {
    string str1 = "cba";
    string str2 = "baaca";
    Solution s;
    cout << s.orderlyQueue(str1, 1) << endl;
    cout << s.orderlyQueue(str2, 3) << endl;
    return 0;
}