/*计数二进制子串
给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。
重复出现的子串要计算它们出现的次数。

示例 1 :
输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
请注意，一些重复出现的子串要计算它们出现的次数。
另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。

示例 2 :
输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

//将二进制字符串变为$0$1$0...累加相邻最小值                      2021/7/20
int question_696(string s) {
    if(s.size() == 1)
        return 0;

    int cnt_0 = 1;
    int cnt_1 = 1;
    int cnt = 0;
    int sign = 0;           //0、1交替次数
    for(auto i = 1; i < s.size(); ++i){
        if(sign){                   //出现不同后
            if(s[i] == s[i - 1]){
                if(sign % 2)
                    ++cnt_1;
                else
                    ++cnt_0;
            }
            else {
                ++sign;
                cnt += (cnt_0 > cnt_1) ? cnt_1 : cnt_0;
                if(sign % 2)
                    cnt_1 = 1;
                else
                    cnt_0 = 1;
            }
        }
        else {
            if(s[i] == s[i - 1])
                ++cnt_0;
            else
                ++sign;
        }
    }

    if(sign)
        cnt += (cnt_0 > cnt_1) ? cnt_1 : cnt_0;
    return cnt;
}
