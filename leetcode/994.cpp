/*腐烂的橘子
在给定的网格中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4

示例 2：
输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。

示例 3：
输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

//                              2021/8/21
int question_994(vector<vector<int>>& grid) {
    int cnt = -1;
    int m = grid.size();
    int n = grid[0].size();
    bool need = false;      //全为0时不需要腐蚀

    deque<pair<int, int>> rot_ed;
    vector<vector<bool>> sign(m, vector<bool>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 2){
                rot_ed.push_back({i, j});
                sign[i][j] = true;
                continue;
            }
            if(grid[i][j] == 1)
                need = true;
        }
    }
    if(!need)
        return 0;
    if(rot_ed.empty())
        return -1;

    while (!rot_ed.empty()) {
        int sz = rot_ed.size();
        while (sz != 0) {
            auto [i, j] = rot_ed.front();
            rot_ed.pop_front();

            if(i > 0 && !sign[i - 1][j] && grid[i - 1][j] == 1){        //上
                grid[i - 1][j] = 2;
                rot_ed.push_back({i - 1, j});
                sign[i - 1][j] = true;
            }

            if(i < m - 1 && !sign[i + 1][j] && grid[i + 1][j] == 1){    //下
                grid[i + 1][j] = 2;
                rot_ed.push_back({i + 1, j});
                sign[i + 1][j] = true;
            }

            if(j > 0 && !sign[i][j - 1] && grid[i][j - 1] == 1){        //左
                grid[i][j - 1] = 2;
                rot_ed.push_back({i, j - 1});
                sign[i][j - 1] = true;
            }

            if(j < n - 1 && !sign[i][j + 1] &&grid[i][j + 1] == 1){    //右
                grid[i][j + 1] = 2;
                rot_ed.push_back({i, j + 1});
                sign[i][j + 1] = true;
            }

            --sz;
        }
        ++cnt;
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1)
                return -1;
        }
    }
    return cnt;
}
