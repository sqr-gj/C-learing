/* 5899. 两个最好的不重叠活动
给你一个下标从 0 开始的二维整数数组 events ，其中 events[i] = [startTimei, endTimei, valuei] 。第 i 个活动开始于 startTimei ，
结束于 endTimei ，如果你参加这个活动，那么你可以得到价值 valuei 。你 最多 可以参加 两个时间不重叠 活动，使得它们的价值之和 最大 。

请你返回价值之和的 最大值 。

注意，活动的开始时间和结束时间是 包括 在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。
更具体的，如果你参加一个活动，且结束时间为 t ，那么下一个活动必须在 t + 1 或之后的时间开始。

示例 1:
输入：events = [[1,3,2],[4,5,2],[2,4,3]]
输出：4
解释：选择绿色的活动 0 和 1 ，价值之和为 2 + 2 = 4 。

示例 2：
Example 1 Diagram

输入：events = [[1,3,2],[4,5,2],[1,5,5]]
输出：5
解释：选择活动 2 ，价值和为 5 。

示例 3：
输入：events = [[1,5,3],[1,5,1],[6,6,5]]
输出：8
解释：选择活动 0 和 2 ，价值之和为 3 + 5 = 8 。
*/

#include <vector>
#include <algorithm>

using namespace std;

//未通过
int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());                 //排序保证前面活动先开始
    int sz = events.size();
//    for (int i = 0; i < sz; ++i) {                    //超时
//        for (int j = i + 1; j < sz; ++j) {
//            if (events[j][0] <= events[i][1])         //开始时间小于结束时间
//                continue;
//            max_value = (events[i][2] + events[j][2]) > max_value ? (events[i][2] + events[j][2]) : max_value;
//        }
//        max_value = (events[i][2]) > max_value ? (events[i][2]) : max_value;
//    }

    int left = 0;
    int right = sz - 1;
    int max_value = (events[left][2] > events[right][2]) ? events[left][2] : events[right][2];
    while (left < right) {
        if (events[left][1] < events[right][0]) {
           max_value = (events[left][2] + events[right][2]) > max_value ? (events[left][2] + events[right][2]) : max_value;
            if (events[left][2] < events[right][2])
                ++left;
            else
                --right;
        }
        else {
            ++left;
            max_value = (events[left][2] > max_value) ? events[left][2] : max_value;
        }
    }

    return max_value;
}
