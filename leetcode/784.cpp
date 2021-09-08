/*字母大小写全排列
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例：
输入：S = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]

输入：S = "3z4"
输出：["3z4", "3Z4"]

输入：S = "12345"
输出：["12345"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <cctype>

using namespace std;

//                          2021/8/24
vector<string> question_784(string s) {
    vector<int> coor_alpha;
    int sz = s.size();
    for(int i = 0; i < sz; ++i){
        if(isalpha(s[i]))
            coor_alpha.push_back(i);
    }
    vector<string> re;
    if(coor_alpha.size() == 0){
        re.push_back(s);
        return re;
    }

    //截取第一个字母之前字符串
    int sz_alpha = coor_alpha.size();
    string s1;
    for(int i = 0; i <= coor_alpha[0]; ++i){
        s1 += s[i];
    }
    //递归剩余字符串
    string s2;
    for(int i = coor_alpha[0] + 1; i < sz; ++i){
        s2 += s[i];
    }

    vector<string> let = question_784(s2);
    for(int i = 0; i < let.size(); ++i){
        string s1_1 = s1;
        s1_1[coor_alpha[0]] = tolower(s1[coor_alpha[0]]);         //小写字母
        s1_1 += let[i];
        re.push_back(s1_1);

        string s1_2 = s1;
        s1_2[coor_alpha[0]] = toupper(s1[coor_alpha[0]]);         //大写字母
        s1_2 += let[i];
        re.push_back(s1_2);
    }
    return re;
}
