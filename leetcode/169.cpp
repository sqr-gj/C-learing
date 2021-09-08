/* 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
输入：[3,2,3]
输出：3

示例 2：
输入：[2,2,1,1,1,2,2]
输出：2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>

using namespace std;

//                      2021/8/16
int question_169(vector<int>& nums) {
    map<int, size_t> num_size;
    int max = 0;
    int k;

    for(auto num : nums){
        ++num_size[num];
        if(num_size[num] > max){
            max = num_size[num];
            k = num;
        }
    }
    return k;
}
