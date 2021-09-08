/*矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。
幸运数是指矩阵中满足同时下列两个条件的元素：
在同一行的所有元素中最小
在同一列的所有元素中最大

示例 1：
输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。

示例 2：
输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。

示例 3：
输入：matrix = [[7,8],[1,2]]
输出：[7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>

using namespace std;

//暴力解  怕超时——>竟然没超时              2021/7/20
int vector_min(vector<int> row){
    int min = row[0];
    int min_line = 0;
    for(int i = 1; i < row.size(); ++i){
        if(min > row[i]){
            min = row[i];
            min_line = i;
        }
    }
    return min_line;
}

bool line_max(vector<vector<int>>& matrix, int m, int k){
    int min = matrix[m][k];
    for(auto i = 0; i < matrix.size(); ++i){
        if(min < matrix[i][k])
            return false;
    }
    return true;
}

vector<int> question_1380(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       vector<int> lucky_nums;

       for(int i = 0; i < m; ++i){
            int k = vector_min(matrix[i]);         //第i行的最小值所在列数
            if(line_max(matrix, i, k))
                lucky_nums.push_back(matrix[i][k]);
       }
       return lucky_nums;
}
