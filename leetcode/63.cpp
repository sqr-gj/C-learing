/* 不同路径Ⅱ
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                  2021/11/16
int question_63(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0])
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    obstacleGrid[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) != 0 && obstacleGrid[i][j] == 1){
                obstacleGrid[i][j] = 0;
                continue;
            }
            if (i > 0)
                obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            if (j > 0)
                obstacleGrid[i][j] += obstacleGrid[i][j - 1];
        }
    }
    return obstacleGrid[m - 1][n - 1];
}
