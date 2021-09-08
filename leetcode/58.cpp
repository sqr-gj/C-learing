/*最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

示例 1：
输入：s = "Hello World"
输出：5

示例 2：
输入：s = "   fly me   to   the moon  "
输出：4

示例 3：
输入：s = "luffy is still joyboy"
输出：6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

using namespace std;

//                      2021/8/16
int question_58(string s){
    int sz = s.size();
    while(s[sz - 1] == ' '){
        --sz;
    }
    for(int sec = sz - 2; sec >= 0; --sec){
        if(s[sec] == ' ')
            return sz - sec;
    }
    return sz;
}
