/* n皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。



示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//八皇后改n皇后
#include <vector>
#include <string>

using namespace std;

//放置第i行皇后
void place(int i, const int n, vector<bool> &line, vector<bool> &f_dia, vector<bool> &s_dia, vector<string> &k, vector<vector<string>> &result){          //放置第i行皇后
    if(i == n){
        result.push_back(k);
        return;
    }

    for(int j = 0; j != n; ++j){
        if(!line[j] && !f_dia[n - i + j] && !s_dia[i + j + 1]){
            line[j] = true;
            f_dia[n - i + j] = true;
            s_dia[i + j + 1] = true;

            k[i][j] = 'Q';

            place(i + 1, n, line, f_dia, s_dia, k, result);

            line[j] = false;
            f_dia[n - i + j] = false;
            s_dia[i + j + 1] = false;

            k[i][j] = '.';
        }
    }
}

//                                      2021/10/27
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<bool> line(n);           //n列
    vector<bool> f_dia(2 * n - 1), s_dia(2 * n - 1);       //2n -1 主、从斜线
    vector<string> k(n, string(n,'.'));                //n * n棋盘
    place(0, n, line, f_dia, s_dia, k, result);
    return result;
}
