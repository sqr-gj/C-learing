///*在元素数组中查找元素的第一个和最后一个位置
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回 [-1, -1]。
//进阶：
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

//示例 1：
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4]

//示例 2：
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1]

//示例 3：
//输入：nums = [], target = 0
//输出：[-1,-1]

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>

//using namespace std;

////二分查找                  2021/7/16
//vector<int> question_34(vector<int>& nums, int target) {
//    vector<int> result;

//    if(!nums.size())
//        return {-1, -1};
//    int left = 0;
//    int right = nums.size() - 1;
//    int mid = right  / 2;
//    int find;

//    while (true) {
//        //不存在目标值
//        if(left > right ){
//            return {-1, -1};
//        }

//        if(nums[mid] < target){
//            left = mid + 1;
//            mid = (left + right ) / 2;
//        }
//        else if(nums[mid] > target){
//            right  = mid - 1;
//            mid = (left + right ) / 2;
//        }
//        else {
//            find = mid;
//            break;
//        }
//    }

//    //查找target第一次出现位置
//    for(size_t i = find; i >= 0; --i){
//        if(nums[i] == target && i == 0){
//            result.push_back(i);
//            break;
//        }

//        if(nums[i] != target){
//            result.push_back(i + 1);
//            break;
//        }
//    }

//    //查找target最后一次出现位置
//    for(size_t i = find; i < nums.size(); ++i){
//        if(nums[i] == target && i == nums.size() - 1){
//            result.push_back(i);
//            break;
//        }
//        if(nums[i] != target){
//            result.push_back(i - 1);
//            break;
//        }
//    }

//    return result;
//}
