/* 子集Ⅱ
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//40题 组合Ⅱ  同模板
//void combine_(vector<int> candidates, vector<vector<int>> &result, vector<int> &re) {
//    int sz = candidates.size();
//    result.push_back(re);
//    for (int i = 0; i < sz; ++i) {
//        re.push_back(candidates[i]);
//        combine_(vector<int>(candidates.begin() + i + 1, candidates.end()), result, re);
//        re.pop_back();

//        //防止重复子集
//        while (i < sz - 1 && candidates[i] == candidates[i + 1]) {
//            ++i;
//        }
//    }
//}

////                              2021/10/25
//vector<vector<int>> question_90(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    vector<vector<int>> result;
//    vector<int> re;
//    combine_(nums, result, re);
//    return result;
//}
