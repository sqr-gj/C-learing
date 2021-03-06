/*长键按入
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例 1：
输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：
输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

示例 3：
输入：name = "leelee", typed = "lleeelee"
输出：true

示例 4：
输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/long-pressed-name
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

//                      2021/8/17
bool question_925(string name, string typed){
    string name_short;
    string typed_short;
    name_short += name[0];
    typed_short += typed[0];
    if(name_short != typed_short)
        return false;

    vector<int> name_cnt, typed_cnt;

    int cnt = 1;
    for(int i = 1; i < name.size(); ++i){
        if(name[i] != name_short[name_short.size() - 1]){
            name_short += name[i];
            name_cnt.push_back(cnt);
            cnt = 1;
        }
        else {
            ++cnt;
        }
    }
    name_cnt.push_back(cnt);

    cnt = 1;
    for(int i = 1; i < typed.size(); ++i){
        if(typed[i] != typed_short[typed_short.size() - 1]){
            typed_short += typed[i];
            typed_cnt.push_back(cnt);
            cnt = 1;
        }
        else {
            ++cnt;
        }
    }
    typed_cnt.push_back(cnt);

    if(name_short != typed_short){
        return false;
    }
    else {
        for(int i = 0; i < name_cnt.size(); ++i){
            if(name_cnt[i] > typed_cnt[i])
                return false;
        }
    }
    return true;
}
