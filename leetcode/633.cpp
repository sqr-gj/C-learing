///*平方数之和
//给定一个非负整数c，你要判断是否存在两个整数a和b，使得 a^2 + b^2 = c 。

//示例 1：
//输入：c = 5
//输出：true
//解释：1 * 1 + 2 * 2 = 5

//示例 2：
//输入：c = 3
//输出：false

//示例 3：
//输入：c = 4
//输出：true

//示例 4：
//输入：c = 2
//输出：true

//示例 5：
//输入：c = 1
//输出：true

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sum-of-square-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <math.h>

////暴力搜索      2021/7/4
//bool question_633(int c){
//    int c_sqrt = sqrt(c);
//    if(c_sqrt * c_sqrt == c)
//        return true;

//    for(int a = 1; a <= c_sqrt; ++a){
////        int b_sqrt = sqrt(c - a*a);
////        if(b_sqrt * b_sqrt == c - a*a)
////            return true;
//        //用int判断
//        double b_sqrt = sqrt(c - a*a);
//        if(b_sqrt == int(b_sqrt))
//            return true;
//    }

//    return false;
//}
