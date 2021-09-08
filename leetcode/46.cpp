/*全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                                  2021/8/24
vector<vector<int>> question_46(vector<int>& nums) {
    vector<vector<int>> re;
    if(nums.size() == 1){
        re.push_back(nums);
        return re;
    }
    int sz = nums.size();
    vector<vector<int>> r;
    for(int i = sz - 1; i >= 0; --i){
        int pop = nums[i];
        nums.pop_back();
        r = question_46(nums);

        for(int j = 0; j < sz; ++j){        //将pop出的元素插入第j个位置上
            for(int k = 0; k < r.size(); ++k){
                vector<int> a = r[k];
                vector<int> add(sz);

                for(int m = 0; m < sz; ++m){
                    if(m < j)
                        add[m] = a[m];
                    else if(m == j)
                        add[j] = pop;
                    else
                        add[m] = a[m - 1];
                }
                re.push_back(add);
            }
        }
    }
    return re;
}
