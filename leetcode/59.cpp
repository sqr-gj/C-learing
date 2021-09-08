/*螺旋矩阵Ⅱ
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//模拟进程                          2021/9/7
vector<vector<int>> question_59(int n) {
    vector<vector<int>> re(n, vector<int>(n));
    int begin_i = 0;
    int begin_j = 0;

    //边界
    int line_left = 0;
    int line_right = n;
    int row_high = 0;
    int row_low = n;

    int sz = n * n;
    int cnt = 1;
    while (cnt <= sz) {
        for(;begin_j < line_right; ++begin_j) {
            re[begin_i][begin_j] = cnt++;
            if(cnt > sz)
                return re;
        }
        --line_right;
        --begin_j;

        for(++begin_i; begin_i < row_low; ++begin_i) {
            re[begin_i][begin_j] = cnt++;
            if(cnt > sz)
                return re;
        }
        --row_low;
        --begin_i;

        for (--begin_j; begin_j >= line_left; --begin_j) {
           re[begin_i][begin_j] = cnt++;
           if(cnt > sz)
               return re;
        }
        ++line_left;
        ++begin_j;

        for(--begin_i; begin_i > row_high; --begin_i) {
           re[begin_i][begin_j] = cnt++;
           if(cnt > sz)
               return re;
        }
        ++row_high;
        ++begin_i;
        ++begin_j;
    }
    return re;
}
