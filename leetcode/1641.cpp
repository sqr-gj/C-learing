/*统计字典序元音字符串的数目
给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。
字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。

示例 1：
输入：n = 1
输出：5
解释：仅由元音组成的 5 个字典序字符串为 ["a","e","i","o","u"]

示例 2：
输入：n = 2
输出：15
解释：仅由元音组成的 15 个字典序字符串为
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后

示例 3：
输入：n = 33
输出：66045

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-sorted-vowel-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//                  2021/7/21
int question_1641(int n) {
//    return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;            //找规律得杨辉三角
    vector<int> num(5, 1);          //长度为1的数目
    for(int i = 2; i <= n + 1; ++i){
        for(int j = 0; j < 4; ++j){
            num[j + 1] += num[j];
        }
    }
    return num[4];
}
