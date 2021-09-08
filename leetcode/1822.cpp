///*数组元素积的符号
//已知函数 signFunc(x) 将会根据x的正负返回特定值：
//如果x是正数，返回1 。
//如果x是负数，返回-1 。
//如果x是等于0,返回0 。
//给你一个整数数组 nums 。令product为数组nums中所有元素值的乘积。
//返回signFunc(product) 。

//示例 1：

//输入：nums = [-1,-2,-3,-4,3,2,1]
//输出：1
//解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1

//示例 2：
//输入：nums = [1,5,0,2,-3]
//输出：0
//解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0

//示例 3：
//输入：nums = [-1,1,-1,1,-1]
//输出：-1
//解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sign-of-the-product-of-an-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>

//using namespace std;

////              2021/7/5
//int question_1822(vector<int>& nums) {
//    bool sign = true;       //表示正负：true为 + ， false为 -
//    for(auto num : nums){
//        if(num == 0)
//            return 0;
//        else if (num < 0)
//            sign = !sign;
//    }

//    if(sign)
//        return  1;

//    return -1;
//}
