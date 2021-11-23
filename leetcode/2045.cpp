/* 到达目的地的第二短时间
城市用一个 双向连通 图表示，图中有 n 个节点，从 1 到 n 编号（包含 1 和 n）。
图中的边用一个二维整数数组 edges 表示，其中每个 edges[i] = [ui, vi] 表示一条节点 ui 和节点 vi 之间的双向连通边。
每组节点对由最多一条边连通，顶点不存在连接到自身的边。穿过任意一条边的时间是 time 分钟。

每个节点都有一个交通信号灯，每 change 分钟改变一次，从绿色变成红色，再由红色变成绿色，循环往复。所有信号灯都 同时 改变。
你可以在 任何时候 进入某个节点，但是 只能 在节点 信号灯是绿色时 才能离开。如果信号灯是  绿色 ，你 不能 在节点等待，必须离开。

第二小的值 是 严格大于 最小值的所有值中最小的值。
例如，[2, 3, 4] 中第二小的值是 3 ，而 [2, 2, 4] 中第二小的值是 4 。
给你 n、edges、time 和 change ，返回从节点 1 到节点 n 需要的 第二短时间 。

注意：
你可以 任意次 穿过任意顶点，包括 1 和 n 。
你可以假设在 启程时 ，所有信号灯刚刚变成 绿色 。

示例 1：
输入：n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
输出：13
解释：
上面的左图展现了给出的城市交通图。
右图中的蓝色路径是最短时间路径。
花费的时间是：
- 从节点 1 开始，总花费时间=0
- 1 -> 4：3 分钟，总花费时间=3
- 4 -> 5：3 分钟，总花费时间=6
因此需要的最小时间是 6 分钟。

右图中的红色路径是第二短时间路径。
- 从节点 1 开始，总花费时间=0
- 1 -> 3：3 分钟，总花费时间=3
- 3 -> 4：3 分钟，总花费时间=6
- 在节点 4 等待 4 分钟，总花费时间=10
- 4 -> 5：3 分钟，总花费时间=13
因此第二短时间是 13 分钟。

示例 2：
输入：n = 2, edges = [[1,2]], time = 3, change = 2
输出：11
解释：
最短时间路径是 1 -> 2 ，总花费时间 = 3 分钟
最短时间路径是 1 -> 2 -> 1 -> 2 ，总花费时间 = 11 分钟
*/

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//找出begin -> end 的路径  深度优先
void find_road_dep (vector<vector<int>> &all_roads, int begin, int end, vector<vector<int>>& edges, vector<int> pre_road,
                unordered_set<int> throughed) {
    int sz = edges.size();
    for (int i = 0; i < sz; ++i) {
        if (edges[i][0] == begin) {
            int next = edges[i][1];
            pre_road.push_back(next);
            if (next == end) {       //终边
                all_roads.push_back(pre_road);
                continue;
            }
            else {
                if (!throughed.count(next)){         //未经过此节点  避免环路死循环
                    throughed.insert(next);
                    find_road_dep (all_roads, next, end, edges, pre_road, throughed);
                }
            }
            pre_road.pop_back();
        }
    }
}

//广度优先      还是超时？？？             2021/10/25
void find_road_ext (vector<vector<int>>& edges, int n, vector<int> pre_road, bool &is_find_short, int &road_len, int shortest,
                    unordered_set<int> throughed) {
    ++road_len;
    if (road_len == shortest) {
        return;
    }

    int sz = edges.size();
    vector<int> next_road;
    int j = 0;
    for (int begin : pre_road) {
        for (int i = j; i < sz; ++i) {
            if (edges[i][0] == begin) {
                if (throughed.count(edges[i][1]))
                    continue;
                throughed.insert(edges[i][1]);
                next_road.push_back(edges[i][1]);
                if (edges[i][1] == n) {
                    if (is_find_short) {        //非第一次路径
                        if (road_len != shortest)
                            return;
                    }
                    else {                      //第一次到达  最短路径
                        shortest = road_len;
                        is_find_short = true;
                    }
                }
            }
            else if (edges[i][0] > begin) {
                j = i;
                break;
            }
        }
    }

    //去除重复节点并有序化
    sort(next_road.begin(), next_road.end());
    auto end_unique = unique(next_road.begin(), next_road.end());
    next_road.erase(end_unique, next_road.end());
    find_road_ext(edges, n, next_road, is_find_short, road_len, shortest, throughed);
}

//->超时   看看最短路径再来                       2021/10/23
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    //edge[0] < edge[1]   去除环路
//    for(auto &edge :edges) {
//        if (edge[0] > edge[1])
//            swap(edge[0], edge[1]);
//    }
    int sz_edgs = edges.size();
    //填充为双向边
    for (int i = 0; i < sz_edgs; ++i) {
        edges.push_back({edges[i][1], edges[i][0]});
    }
    sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b) {return a[0] < b[0];});

//    vector<vector<int>> all_roads;          //所有1->n的路径
    vector<int> pre_road = {1};
    unordered_set<int> throughed = {1};
//    find_road_dep (all_roads, 1, n, edges, pre_road, throughed);

//    //按路径长度排序
//    sort(all_roads.begin(), all_roads.end(), [] (vector<int> &a, vector<int> &b) {return a.size() < b.size();});

    //找出第二短路径的节点数
//    size_t road_len = all_roads[0].size();
//    if (road_len == all_roads[all_roads.size() - 1].size()) {    //所有路径长度相同
//        road_len += 2;
//    }
//    else {
//        for (auto &road : all_roads) {
//            if (road.size() != road_len) {
//                road_len = road.size() < (all_roads[0].size() + 2) ? road.size() : (all_roads[0].size() + 2);
//                break;
//            }
//        }
//    }

    int road_len = 1;
    bool is_find_short = false;
    find_road_ext(edges, n, pre_road, is_find_short, road_len, 100000, throughed);

    //计算通过该路径长度的时间
    int all_time = 0;
    while (road_len != 1) {
        int n = all_time / change;
        if ((n & (n - 1)) == (n - 1)) {               //n为奇数  当前节点为红灯
            all_time = (n + 1) * change + time;
        }
        else {
            all_time += time;
        }
        --road_len;
    }
    return all_time;
}
