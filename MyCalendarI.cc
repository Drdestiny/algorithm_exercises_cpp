#include <iostream>
#include <map>

using namespace std;

// Leetcode 729: 我的日程安排表I
// 用map储存起点终点，key是起点，value是终点，只有不与之前存储的日程安排冲突才会push进去

class MyCalendar {
    map<int, int> calendar;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        int orderedStart, orderedEnd;
        for (auto iter = calendar.begin(); iter != calendar.end(); iter++) {
            orderedStart = iter->first;
            orderedEnd = iter->second;
            if (start <= orderedStart && end > orderedStart ||
                start >= orderedStart && start < orderedEnd) {
                return false;
            }
        }
        calendar[start] = end;
        return true;
    }
};