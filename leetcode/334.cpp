///*递增三元子序列
//给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
//如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。


//示例 1：
//输入：nums = [1,2,3,4,5]
//输出：true
//解释：任何 i < j < k 的三元组都满足题意

//示例 2：
//输入：nums = [5,4,3,2,1]
//输出：false
//解释：不存在满足题意的三元组

//示例 3：
//输入：nums = [2,1,5,0,4,6]
//输出：true
//解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>

//using namespace std;

////连续3元递增子序列         2021/7/13
////bool question_334(vector<int>& nums) {
////    size_t i = 0;
////    while (i < nums.size() - 2) {
////        if(nums[i] < nums[i + 1]){
////            if(nums[i + 1] < nums[i + 2])
////                return true;
////            else
////                i += 2;
////        }
////        else
////            i += 1;
////    }
////    return false;
////}

////                  2021/7/13
//bool question_334(vector<int>& nums) {
//    int min = 2147483647, mid = 2147483647;
//    for(size_t i = 1; i < nums.size(); ++i){
//        if(nums[i] > mid)
//            return true;
//        else if(nums[i] < min)
//            min = nums[i];
//        else
//            mid = nums[i];
//    }
//    return false;
//}
