/* 猫和老鼠
两位玩家分别扮演猫和老鼠，在一张 无向 图上进行游戏，两人轮流行动。

图的形式是：graph[a] 是一个列表，由满足 ab 是图中的一条边的所有节点 b 组成。

老鼠从节点 1 开始，第一个出发；猫从节点 2 开始，第二个出发。在节点 0 处有一个洞。

在每个玩家的行动中，他们 必须 沿着图中与所在当前位置连通的一条边移动。例如，如果老鼠在节点 1 ，那么它必须移动到 graph[1] 中的任一节点。

此外，猫无法移动到洞中（节点 0）。

然后，游戏在出现以下三种情形之一时结束：

如果猫和老鼠出现在同一个节点，猫获胜。
如果老鼠到达洞中，老鼠获胜。
如果某一位置重复出现（即，玩家的位置和移动顺序都与上一次行动相同），游戏平局。
给你一张图 graph ，并假设两位玩家都都以最佳状态参与游戏：

如果老鼠获胜，则返回 1；
如果猫获胜，则返回 2；
如果平局，则返回 0 。

示例 1：


输入：graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
输出：0
示例 2：


输入：graph = [[1,3],[0],[3],[0,2]]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cat-and-mouse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <mem.h>

using namespace std;

//cv                    2022/1/4
class Solution {
public:
    int sz = 0;
    vector<vector<int>> graph;
    int dp[51][51][102];
    int catMouseGame(vector<vector<int>>& graph) {
        this->sz = graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof(dp));
        getResult(1, 2, 0);
        return dp[1][2][0];
    }

    void getResult(int mouse, int cat, int turn) {
        if (turn == 2 * sz)
            dp[mouse][cat][turn] = 0;
        if (dp[mouse][cat][turn] < 0){
            if (mouse == 0)
                dp[mouse][cat][turn] = 1;
            else if (mouse == cat)
                dp[mouse][cat][turn] = 2;
            else
                getnextResult(mouse, cat, turn);
        }
    }

    void getnextResult(int mouse, int cat, int turn) {
        int now = turn % 2 == 0 ? mouse : cat;
        int nowResult = turn % 2 == 0 ? 2 : 1;  //设为当前玩家输
        int result = nowResult;
        for (auto &next : graph[now]) {
            if (next == 0 && turn % 2 == 1)
                continue;
            int nextM = turn % 2 == 0 ? next : mouse;
            int nextC = turn % 2 == 1 ? next : cat;
            getResult(nextM, nextC, turn + 1);
            int nextResult = dp[nextM][nextC][turn + 1];
            if (nextResult != nowResult) {
                result = nextResult;
                if (nextResult != 0)
                    break;
            }
        }
        dp[mouse][cat][turn] = result;
    }
};


