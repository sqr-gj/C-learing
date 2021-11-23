/* 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下

示例 3：
输入：m = 7, n = 3
输出：28

示例 4：
输入：m = 3, n = 3
输出：6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                              2021/11/16
int question_62(int m, int n) {
//    vector<vector<int>> map(m, vector<int>(n));
//    map[0][0] = 1;
//    //dp[i][j] = dp[i-1][j] + dp[i][j-1]
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (i > 0)
//                map[i][j] += map[i - 1][j];
//            if (j > 0)
//                map[i][j] += map[i][j - 1];
//        }
//    }
//    return map[m - 1][n - 1];

    //直接计算 C [min(m,n) - 1]  [m + n - 2]  处理好计算方式
    int max = m + n - 2;
    int k = min(m, n) - 1;
    long long result = 1;
    int res = k;
    while (k > 0) {
        result *= (max - k + 1);
        while (res > 0 && result % res == 0)
            result /= res--;
        --k;
    }
    return result;
}
