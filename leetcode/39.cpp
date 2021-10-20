/* 组合总和
给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。
candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。
对于给定的输入，保证和为 target 的唯一组合数少于 150 个。


示例 1：
输入: candidates = [2,3,6,7], target = 7
输出: [[7],[2,2,3]]

示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
输入: candidates = [2], target = 1
输出: []

示例 4：
输入: candidates = [1], target = 1
输出: [[1]]

示例 5：
输入: candidates = [1], target = 2
输出: [[1,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//
void combine_(vector<int> candidates, int target, vector<vector<int>> &result, vector<int> &re) {
    int sz = candidates.size();
    if (sz == 0 || candidates[0] > target)
        return;

    for (int i = 0; i < sz; ++i) {
        if (candidates[i] == target) {              //相等即找到一组
            re.push_back(candidates[i]);
            result.push_back(re);
            re.pop_back();
            return;
        }
        else if (candidates[i] < target) {          //小于则可能再增加一位数或增大当前数
            re.push_back(candidates[i]);
            combine_(vector<int>(candidates.begin() + i, candidates.end()), target - candidates[i], result, re);    //can从i开始防止重复
            re.pop_back();
        }
        else {                  //can已经排序，故当当前数大于tar时  后面数不可能组合完成
            return;
        }
    }
}

//                                          2021/10/20
vector<vector<int>> question_39(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target)
        return result;
    vector<int> re;
    combine_(candidates, target, result, re);
    return result;
}
