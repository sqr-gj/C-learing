/* 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//                                      2021/11/9
vector<vector<int>> question_56 (vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    int sz = intervals.size();
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (int i = 1; i < sz; ++i) {
        if (right < intervals[i][0]) {
            result.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
        else {
            right = max(intervals[i][1], right);
        }
    }
    if (result.empty() || right != result[result.size() - 1][1])
        result.push_back({left, right});
    return result;
}
