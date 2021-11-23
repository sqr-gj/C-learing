/* 重新安排行程
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

示例 1：
输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]

示例 2：
输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

//
void find_new (unordered_map<string, vector<string>> &begin_end, string begin, bool &is_find, const int len, vector<string> &result) {
    if (result.size() == len) {
        is_find = true;
        return;
    }

    auto &next = begin_end[begin];
    int sz = next.size();
    string temp_end;
    for (int i = 0; i < sz; ++i) {
        temp_end = next[i];
        next.erase(next.begin() + i);
        result.push_back(temp_end);
        find_new(begin_end, temp_end, is_find, len, result);
        if (is_find)
            return;
        result.pop_back();
        next.insert(next.begin() + i, temp_end);
    }
}

//第80测试用例疑有误                                    2021/10/27
//tickets = [["JFK","SFO"],["SFO","ATL"],["SFO","BOS"],["SFO","LHR"],["ATL","BOS"],["BOS","LHR"],["LHR","BOS"],["BOS","ATL"]]
//result = ["JFK","SFO","LHR","BOS","ATL","BOS","LHR","BOS","ATL"]
//按字典序排序进行搜索   找出的第一条行程即为最小的行程组合
vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result {"JFK"};
    unordered_map<string, vector<string>> begin_end;             //存储所有票  且按起点存储  该起点到达的终点置于队列中且按字典序排序
    bool is_find = false;
    int len = tickets.size() + 1;

    for (int ticket = 0; ticket + 1 < len; ++ticket) {
        begin_end[tickets[ticket][0]].push_back(tickets[ticket][1]);
    }

    for (auto &be : begin_end) {
        sort(be.second.begin(), be.second.end());
    }

    find_new(begin_end, "JFK", is_find, len, result);
    return result;
}
