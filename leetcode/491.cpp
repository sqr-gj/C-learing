/* 递增子序列
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。



示例 1：

输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>

using namespace std;

//40题 组合Ⅱ  同模板
//void combine_(vector<int> candidates, vector<vector<int>> &result, vector<int> &re) {
//    int sz = candidates.size();

//    for (int i = 0; i < sz; ++i) {
//        if (re[re.size() - 1] <= candidates[i]){
//            re.push_back(candidates[i]);
//            result.push_back(re);
//            combine_(vector<int>(candidates.begin() + i + 1, candidates.end()), result, re);
//            re.pop_back();
//        }
//    }
//}

////                             2021/10/25
//vector<vector<int>> question_491(vector<int>& nums) {
//    vector<vector<int>> result;
//    vector<int> re;
//    int sz = nums.size();
//    for (int i = 0; i < sz - 1; ++i) {
//        re.push_back(nums[i]);
//        combine_(vector<int>(nums.begin() + i + 1, nums.end()), result, re);
//        re.pop_back();
//    }
//    //不想动脑子的LJ办法了
//    sort(result.begin(), result.end());
//    auto unique_end = unique(result.begin(), result.end());
//    result.erase(unique_end, result.end());
//    return result;
//}
