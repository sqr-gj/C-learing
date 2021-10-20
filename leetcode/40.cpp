/* 组合总和Ⅱ
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
注意：解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//
void combine_(vector<int> candidates, int target, vector<vector<int>> &result, vector<int> &re) {
    int sz = candidates.size();

    for (int i = 0; i < sz; ++i) {
        if (candidates[i] == target) {
            re.push_back(candidates[i]);
            result.push_back(re);
            re.pop_back();
        }
        else if (candidates[i] < target) {
            re.push_back(candidates[i]);
            combine_(vector<int>(candidates.begin() + i + 1, candidates.end()), target - candidates[i], result, re);
            re.pop_back();
        }
        while (i < sz - 1 && candidates[i] == candidates[i + 1]) {          //防止重复组合
            ++i;
        }
    }
}

//                                          2021/10/20
vector<vector<int>> question_40(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> re;
    combine_(candidates, target, result, re);
    return result;
}
