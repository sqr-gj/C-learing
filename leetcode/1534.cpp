/*统计好三元组
给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。
如果三元组 (arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
其中 |x| 表示 x 的绝对值。

返回 好三元组的数量 。

示例 1：
输入：arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
输出：4
解释：一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。

示例 2：
输入：arr = [1,1,2,2,3], a = 0, b = 0, c = 1
输出：0
解释：不存在满足所有条件的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-triplets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//三重循环没超时->离大谱                  2021/8/31
int question_1534(vector<int>& arr, int a, int b, int c) {
    int cnt = 0;
    int sz = arr.size();
    for(int i = 0; i < sz - 2; ++i){
        int max_j = arr[i] + a;
        int min_j = arr[i] - a;
        for(int j = i + 1; j < sz - 1; ++j){
            if(arr[j] >= min_j && arr[j] <= max_j){
                int max_k = ((arr[j] + b) > (arr[i] + c)) ? (arr[i] + c) : (arr[j] + b);
                int min_k = ((arr[j] - b) > (arr[i] - c)) ? (arr[j] - b) : (arr[i] - c);
                if(min_k > max_k)
                    continue;
                else{
                    for(int k = j + 1; k < sz; ++k){
                        if(arr[k] >= min_k && arr[k] <= max_k)
                            ++cnt;
                    }
                }
            }

        }
    }
    return cnt;
}
