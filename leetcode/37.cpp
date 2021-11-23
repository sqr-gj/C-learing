/* 解数独
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

示例：
输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int cnt = 0;                //计当前已经放置的字符数量
vector<char> nine_c = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

//检查i j位置放字符c是否合法
bool check (int i, int j, vector<vector<char>> &board, char c) {
    for (int k = 0; k < 9; ++k) {
        if (board[i][k] == c || board[k][j] == c)           //对应行列已经有字符c
            return false;
    }

    pair<int, int> center {i / 3 * 3 + 1, j / 3 * 3 + 1};              //i j 所在小方块的中心点

    //i j 所在小方块是否有字符c
    for (int p = -1; p < 2; ++p) {
        if (board[center.first + p][center.second - 1] == c ||board[center.first + p][center.second] == c
                || board[center.first + p][center.second + 1] == c)
            return false;
    }
    return true;
}

//在i j处放置字符
void put (int i, int j, vector<vector<char>> &board) {
    if (cnt == 81)
        return;

    if (board[i][j] == '.') {
        for (int k = 0; k < 9; ++k) {
            if (check(i, j, board, nine_c[k])) {
                board[i][j] = nine_c[k];
                ++cnt;
                if (cnt == 81)
                    return;
                if (j < 8)                          //当在棋盘某行最后一列时放置下一行  否则在当前行放置下一列
                    put (i, j + 1, board);
                else
                    put (i + 1, 0, board);

                if (cnt == 81)
                    return;
                else {
                    board[i][j] = '.';
                    --cnt;
                }
            }
        }
    }
    else {                                  //棋盘原本放置有数字
        ++cnt;
        if (j < 8)
            put (i, j + 1, board);
        else
            put (i + 1, 0, board);
        if (cnt == 81)
            return;
        --cnt;
    }
}

//对每个空格进行试探，当最后一格试探成功时返回  注意及时判断cnt == 81 防止错误的--           2021/10/29
void question_37(vector<vector<char>>& board) {
    put (0, 0, board);
}
