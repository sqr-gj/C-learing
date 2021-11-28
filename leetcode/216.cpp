/* 组合总和Ⅲ
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：
所有数字都是正整数。
解集不能包含重复的组合。

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//回溯递归主函数
void combine_(int k, int n, int i, vector<vector<int>> &result) {
    if (n < 3)
        return;
    int sz1 = result.size();
    if (k == 2) {                            //只有两个数时开始组合
        int left = i + 1;
        int right = 9;
        while (left < right) {
            if (left + right > n)
                --right;
            else if (left + right < n)
                ++left;
            else
                result.push_back({left++, right--});
        }
    }
    else {
        for (int j = i + 1; j < 9; ++j) {
            if (3 * j + 1 < n) {            //剪枝
                combine_(k - 1, n - j, j, result);
                if (sz1 != result.size()) {     //有可行解
                    for (int sz = sz1; sz < result.size(); ++sz) {
                        result[sz].push_back(j);
                    }
                    sz1 = result.size();        //更新容器大小
                }
            }
        }
    }
}
//  接口函数                2021/10/19
vector<vector<int>> question_216(int k, int n) {
    vector<vector<int>> result;
    if(k == 0)
        return result;
    else if (k == 1)
        if (n < 10)
            return {{n}};;
    combine_(k, n, 0, result);
    return result;
}
