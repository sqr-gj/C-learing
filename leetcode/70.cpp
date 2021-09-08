/* 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

using namespace std;

//Cm n 排列       (有误-
int arr(int m, int n){
    double C = 1;
    n = ((m - n) > n) ? n : (m - n);
    while (n != 0) {
        C *= double(m-- / n--);
    }

    return C;
}

//int question_70(int n){
//    int cnt = 1;

//    for(int i = 1; n - 2*i > -1; ++i){
//        if(n - 2*i == 0){
//            return cnt + 1;
//        }
//        else if(n - 2*i == 1){
//            return cnt + i + 1;
//        }
//        else {
//            cnt += arr(n - 2*i + i, i);
//        }
//    }

//    return cnt;
//}

//fx = fx-1 + fx-2          2021/8/17
int question_70(int n){
    int f_1 = 1, f_2 = 1;
    int cnt = 1;
    for(int i = 2; i <= n; ++i){
        cnt = f_1 + f_2;
        f_2 = f_1;
        f_1 = cnt;
    }
    return cnt;
}
