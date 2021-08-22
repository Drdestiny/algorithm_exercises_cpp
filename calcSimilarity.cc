#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

/*
    携程3.18笔试第一道：缘分
    输入两个人名的拼音，如Zhang San，Zhan
   Ai，它们的缘分值等于每个对应位置的字的拼音的缘分值之和
    每个字拼音的缘分值计算方法如下：通过删减使得两个拼音完全相等，最小的删除的字母ASCII值之和
   即为这对字的缘分值
    如Zhang和Zhan，前者删去一个g，两者就相等，这两个字的缘分值就是g的ascii值：103
    再比较San和Ai，无法通过删减使两者相等，所以这两个字的缘分值就是S、a、n、A、i的ascii值之和：460
    所以这两个名字的缘分值为103+460=563
    如果两个名字的字数不相等，在得到对应位置的缘分值之后，再加上剩下的所有拼音中的所有字符的ascii值之和，就得到最后
    的缘分值
*/
bool stringEqual(string &str1,
                 string &str2,
                 int start1,
                 int end1,
                 int start2,
                 int end2) {
    if (end1 - start1 == end2 - start2) {
        for (int i = 0; i <= end1 - start1; i++) {
            if (str1[start1 + i] != str2[start2 + i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

int deal(string &str, int start, int end) {
    int res = 0;
    for (int i = start; i <= end; i++) {
        res += str[i];
    }
    return res;
}

int recurse(string &pinyin1,
            string &pinyin2,
            int start1,
            int end1,
            int start2,
            int end2,
            int similarity) {
    if (start1 > end1) {
        return similarity + deal(pinyin2, start2, end2);
    }
    if (start2 > end2) {
        return similarity + deal(pinyin1, start1, end1);
    }
    if (stringEqual(pinyin1, pinyin2, start1, end1, start2, end2)) {
        return similarity;
    }
    vector<int> vec{4, 0};
    vec[0] = recurse(pinyin1, pinyin2, start1 + 1, end1, start2, end2,
                     similarity + pinyin1[start1]);
    vec[1] = recurse(pinyin1, pinyin2, start1, end1 - 1, start2, end2,
                     similarity + pinyin1[end1]);
    vec[2] = recurse(pinyin1, pinyin2, start1, end1, start2 + 1, end2,
                     similarity + pinyin2[start2]);
    vec[3] = recurse(pinyin1, pinyin2, start1, end1, start2, end2 - 1,
                     similarity + pinyin2[end2]);
    int min = INT32_MAX;
    for (int i = 0; i < 4; i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    return min;
}

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int calcSimilarity(vector<string> name1, vector<string> name2) {
    int len1 = name1.size();
    int len2 = name2.size();
    if (len1 == 0 && len2 == 0) {
        return 0;
    } else if (len1 == 0) {
        int res = 0;
        for (int i = 0; i < len2; i++) {
            res += deal(name2[i], 0, name2[i].size() - 1);
        }
        return res;
    } else if (len2 == 0) {
        int res = 0;
        for (int i = 0; i < len1; i++) {
            res += deal(name1[i], 0, name1[i].size() - 1);
        }
        return res;
    }
    int minLen;
    int maxLen;
    if (len1 > len2) {
        minLen = len2;
        maxLen = len1;
    } else {
        minLen = len1;
        maxLen = len2;
    }
    vector<string> &shorterName = len1 > len2 ? name2 : name1;
    int res = 0;
    for (int i = 0; i < minLen; i++) {
        res += recurse(name1[i], name2[i], 0, name1[i].size() - 1, 0,
                       name2[i].size() - 1, 0);
    }
    for (int i = minLen; i < maxLen; i++) {
        string tmp = shorterName[i];
        for (int j = 0; j < tmp.size(); j++) {
            res += tmp[j];
        }
    }
    return res;
}
/******************************结束写代码******************************/

int main() {
    int res;

    int _name1_size = 0;
    cin >> _name1_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _name1;
    string _name1_item;
    for (int _name1_i = 0; _name1_i < _name1_size; _name1_i++) {
        getline(cin, _name1_item);
        _name1.push_back(_name1_item);
    }
    int _name2_size = 0;
    cin >> _name2_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _name2;
    string _name2_item;
    for (int _name2_i = 0; _name2_i < _name2_size; _name2_i++) {
        getline(cin, _name2_item);
        _name2.push_back(_name2_item);
    }

    res = calcSimilarity(_name1, _name2);
    cout << res << endl;

    return 0;
}
