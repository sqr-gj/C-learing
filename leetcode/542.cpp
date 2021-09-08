/*01矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。

示例 1：
输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]

示例 2：
输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <deque>

using namespace std;

//                              2021/8/21
vector<vector<int>> question_542(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    deque<pair<int, int>> coor;
    vector<vector<bool>> sign(m,vector<bool>(n));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n ; ++j){
            if(!mat[i][j]){
                coor.push_back({i,j});
                sign[i][j] = true;         //访问过的坐标置为true
            }
        }
    }

    while (!coor.empty()) {
        auto [i, j] = coor.front();
        int des = mat[i][j];
        coor.pop_front();

        if(i > 0 && !sign[i - 1][j]){        //上
            mat[i - 1][j] = des + 1;
            sign[i - 1][j] = true;
            coor.push_back({i - 1, j});
        }
        if(i < m - 1 && !sign[i + 1][j]){    //下
            mat[i + 1][j] = des + 1;
            sign[i + 1][j] = true;
            coor.push_back({i + 1, j});
        }
        if(j > 0 && !sign[i][j - 1]){    //左
            mat[i][j - 1] = des + 1;
            sign[i][j - 1] = true;
            coor.push_back({i, j - 1});
        }
        if(j < n - 1 && !sign[i][j + 1]){    //右
            mat[i][j + 1] = des + 1;
            sign[i][j + 1] = true;
            coor.push_back({i, j + 1});
        }
    }
    return mat;
}
