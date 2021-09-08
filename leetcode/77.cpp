/*组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

示例 2：
输入：n = 1, k = 1
输出：[[1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

vector<vector<int>> combi(int begin, int end, int k){
    vector<vector<int>> com_r;
    if(k == 1){
        for(int l = begin; l <= end; ++l){
            vector<int> cur = {l};
            com_r.push_back(cur);
        }
        return com_r;
    }
    vector<vector<int>> result;
    for(int i = begin; i < end; ++i){
        com_r = combi(i + 1, end, (k == 1) ? k : k - 1);
        for(auto &a : com_r){
            a.push_back(i);
            result.push_back(a);
        }
    }
    return result;
}
//                              2021/8/23
vector<vector<int>> question_77(int n, int k) {
    vector<vector<int>> result;
    vector<vector<int>> com;

    if(k == 1){
        for(int l = 1; l <= n; ++l){
            vector<int> cur = {l};
            result.push_back(cur);
        }
        return result;
    }

    for(int i = 1; i < (n - k + 2); ++i){
        com = combi(i + 1, n, (k == 1) ? k : k - 1);
        for(auto &a : com){
            a.push_back(i);
            result.push_back(a);
        }
    }
    return result;
}
