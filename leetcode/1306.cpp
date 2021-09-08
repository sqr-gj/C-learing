///*跳跃游戏Ⅲ
//这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。
//请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。
//注意，不管是什么情况下，你都无法跳到数组之外。

//示例 1：
//输入：arr = [4,2,3,0,3,1,2], start = 5
//输出：true
//解释：
//到达值为 0 的下标 3 有以下可能方案：
//下标 5 -> 下标 4 -> 下标 1 -> 下标 3
//下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3

//示例 2：
//输入：arr = [4,2,3,0,3,1,2], start = 0
//输出：true
//解释：
//到达值为 0 的下标 3 有以下可能方案：
//下标 0 -> 下标 4 -> 下标 1 -> 下标 3

//示例 3：
//输入：arr = [3,0,2,1,2], start = 2
//输出：false
//解释：无法到达值为 0 的下标 1 处。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/jump-game-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//*/

//#include <vector>
//#include <queue>

//using namespace std;

////广度优先          2021/7/6
////bool question_1306(vector<int> &arr, int start){
////    vector<bool> mark(arr.size());      //标记搜索过的点
////    queue<int> point;           //待搜索点

////    if(arr[start] == 0)
////        return true;
////    else{
////        point.push(start);
////        mark[start] = true;
////    }

////    while (!point.empty()) {
////        int i = point.front();
////        point.pop();

////        if(i - arr[i] >= 0 && !mark[i - arr[i]]){
////            if(arr[i - arr[i]] == 0)
////                return true;
////            else{
////                point.push(i - arr[i]);
////                mark[i - arr[i]] = true;
////            }
////        }

////        if(i + arr[i] < int(arr.size()) && !mark[i + arr[i]]){
////            if(arr[i + arr[i]] == 0)
////                return true;
////            else{
////                point.push(i + arr[i]);
////                mark[i + arr[i]] = true;
////            }
////        }

////    }

////    return false;
////}

////深度优先
//bool check(const vector<int> &arr, vector<bool> &mark, int i){
//    if(i < 0 || i >= int(arr.size()) || mark[i])
//        return false;

//    if(arr[i] == 0)
//        return true;
//    else
//        mark[i] = true;

//    return check(arr, mark, i - arr[i]) || check(arr, mark, i + arr[i]);
//}

//bool question_1306(vector<int> &arr, int start){
//    vector<bool> mark(arr.size());

//    return check(arr, mark, start);
//}
