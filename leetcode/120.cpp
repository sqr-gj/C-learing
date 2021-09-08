/*三角形最小路径和
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，
如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
输入：triangle = [[-10]]
输出：-10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>

using namespace std;

//  ->超时                            2021/8/24
//int question_120(vector<vector<int>>& triangle) {
//    int sz = triangle.size();
//    vector<int> pre = triangle[0];
//    vector<int> next = pre;
//    vector<int> coor = {0};         //标定pre中元素最后一个相加元素位置

//    //暴力写出到最后层的所有路径和
//    for(int i = 1; i < sz; ++i){
//        vector<int> tri_i = triangle[i];
//        int sz_pre = pre.size();
//        next.clear();
//        vector<int> next_coor;
//        for(int j = 0; j < sz_pre; ++j){
//            next.push_back(pre[j] + tri_i[coor[j]]);
//            next_coor.push_back(coor[j]);
//            next.push_back(pre[j] + tri_i[coor[j] + 1]);
//            next_coor.push_back(coor[j] + 1);
//        }
//        coor = next_coor;
//        pre = next;
//    }

//    //找出最小值
//    int min = 2000001;
//    for(auto n : next)
//        min = (n < min) ? n : min;
//    return min;
//}

//动态规划                      2021/8/27
int question_120(vector<vector<int>>& triangle) {
    int sz = triangle.size();
    vector<int> pre = triangle[0];
    vector<int> next;

    for(int i = 1; i < sz; ++i){
        next.push_back(pre[0] + triangle[i][0]);
        for(int j = 1; j < i; ++j){
            int min_pre = (pre[j] > pre[j - 1]) ? pre[j - 1] : pre[j];
            next.push_back(min_pre + triangle[i][j]);
        }
        next.push_back(pre[i - 1] + triangle[i][i]);
        pre = next;
        next.clear();
    }

    int min = 2000001;
    for(auto n : pre)
        min = (n < min) ? n : min;
    return min;
}
