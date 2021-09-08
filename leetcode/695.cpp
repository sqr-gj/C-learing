/*岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0
（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <deque>

using namespace std;

//                                  2021/8/20
int queetion_695(vector<vector<int>>& grid) {
    int max = 0;
    int cnt = 0;
    deque<vector<int>> grids;

    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1){
                grids.push_back({i, j});
                grid[i][j] = 0;
                while (grids.size() > 0) {
                    vector<int> now_coor = grids[0];
                    ++cnt;
                    grids.pop_front();
                    if(now_coor[0] > 0 && grid[now_coor[0] - 1][now_coor[1]] == 1){
                        grids.push_back({now_coor[0] - 1, now_coor[1]});
                        grid[now_coor[0] - 1][now_coor[1]] = 0;
                    }
                    if(now_coor[1] > 0 && grid[now_coor[0]][now_coor[1] - 1] == 1){
                        grids.push_back({now_coor[0], now_coor[1] - 1});
                        grid[now_coor[0]][now_coor[1] - 1] = 0;
                    }
                    if(now_coor[0] < m - 1 && grid[now_coor[0] + 1][now_coor[1]] == 1){
                        grids.push_back({now_coor[0] + 1, now_coor[1]});
                        grid[now_coor[0] + 1][now_coor[1]] = 0;
                    }
                    if(now_coor[1] < n - 1 && grid[now_coor[0]][now_coor[1] + 1] == 1){
                        grids.push_back({now_coor[0], now_coor[1] + 1});
                        grid[now_coor[0]][now_coor[1] + 1] = 0;
                    }
                }
                max = (max > cnt) ? max : cnt;
                cnt = 0;
            }
        }
    }
    return max;
}
