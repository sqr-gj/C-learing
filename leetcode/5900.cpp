/* 5900. 蜡烛之间的盘子
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。



示例 1:

ex-1

输入：s = "**|**|***|", queries = [[2,5],[5,9]]
输出：[2,3]
解释：
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
示例 2:

ex-2

输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
输出：[9,0,0,0,0]
解释：
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
*/

#include <vector>
#include <string>

using namespace std;

//未通过                       2021/10/31
vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int sz = s.size();
    vector<pair<int, int>> p_occ;
    int cnt_p = 0;

    for (int i = 0; i < sz; ++i) {
        if (s[i] == '|')
            p_occ.push_back({i, cnt_p});        //i之前有多少盘子
        else
            ++cnt_p;
    }

    vector<int> result;
    for (auto &querie : queries) {
        int sz_p = p_occ.size() - 1;
        int i = 0;
        int left = querie[0];
        int right = querie[1];

        while (i < sz_p && p_occ[i].first < left) {
            ++i;
        }
        if (i == sz_p || p_occ[i].first > right){           //left之后无蜡烛
            result.push_back(0);
            continue;
        }

        while (sz_p > i && p_occ[sz_p].first > right) {
            --sz_p;
        }
        if (sz_p == i){             //无第二根蜡烛
            result.push_back(0);
            continue;
        }
        else {
            result.push_back(p_occ[sz_p].second - p_occ[i].second);
        }

    }
    return result;
}
