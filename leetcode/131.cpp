/* 分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

////找出回文串后的进一步切分
////从i开始找出以i开头的回文串，找到前需将i之前的单字符存入临时容器中，找到后 删除i处单字符并存入回文串  递归传入剩下字符串，当遍历完之后，存入
//void next_part (vector<vector<string>> &result, string s, vector<string> one_str) {
//    if (s.empty()) {
//        result.push_back(one_str);
//        return;
//    }
//    int sz = s.size();
//    //依次找出以i开头的回文串
//    string str;
//    for (int i = 0; i < sz; ++i) {
//        int left = i;
//        str = s[i];
//        one_str.push_back(str);
//        for (int j = i + 1; j < sz; ++j) {
//            int right = j;
//            while (left < right) {
//                if (s[left] == s[right]) {
//                    ++left;
//                    --right;
//                }
//                else {
//                    break;
//                }
//            }
//            if (left >= right) {                    //i-j区间为回文串
//                one_str.pop_back();                 //弹出i处的单字符串 s[i]
//                one_str.push_back(string(s.begin() + i, s.begin() + j + 1));    //左闭右开
//                str = string(s.begin() + j + 1, s.end());
//                next_part(result, str, one_str);     //one_str传值  不会改变
//                one_str.pop_back();
//                str = s[i];
//                one_str.push_back(str);

//            }
//            left = i;           //以i开头 重置left   没有回文串也可能改变
//        }
//    }
//    result.push_back(one_str);      //剩下的单字符串
//}

////方案一                                  2021/10/21
//vector<vector<string>> question_131(string s) {
//    vector<vector<string>> result;
//    if (s.empty())
//        return result;

//    vector<string> one_str;
//    next_part(result, s, one_str);

//    return result;
//}

//
void next_pal(vector<vector<string>> & result, const vector<pair<int, int>> pal_str, int i, const string s, vector<string> one_str) {
    int sz_pal = pal_str.size();
    int right_i_pal = pal_str[i].second;
    if (right_i_pal == s.size() - 1) {          //当该回文串以最后一个字符结尾时即找到一个分割方案
        result.push_back(one_str);
        return;
    }

    string temp_str;
    vector<string> temp_one_str = one_str;
    for (int next_pal_num = i + 1; next_pal_num < sz_pal; ++next_pal_num) {
        if (pal_str[i].second < pal_str[next_pal_num].first) {
            //填入俩回文串之间的单字符
            int next_begin = pal_str[next_pal_num].first;
            for (int pre_end = right_i_pal + 1; pre_end < next_begin; ++pre_end) {
                temp_str = s[pre_end];
                one_str.push_back(temp_str);
            }
            right_i_pal = next_begin - 1;
            //填入回文串
            one_str.push_back(string(s.begin() + pal_str[next_pal_num].first, s.begin() + pal_str[next_pal_num].second + 1));
            next_pal(result, pal_str, next_pal_num, s, one_str);
            one_str.pop_back();
        }
    }

    //填入剩余单字符   后面字符不构成回文串即单独列出每个字符
    one_str = temp_one_str;
    for (int res_begin = pal_str[i].second + 1; res_begin < s.size(); ++res_begin) {
        temp_str = s[res_begin];
        one_str.push_back(temp_str);
    }
    result.push_back(one_str);
}

//方案二：先找出所有回文串，再对每个回文串分割出以其为第一个回文串的所有切割方法       2021/10/21
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    int sz = s.size();
    if (!sz)
        return result;

    vector<pair<int, int>> pal_str;         //存储所有回文串的<i, j>
    //找出所有回文串
    for (int i = 0; i < sz; ++i) {
        int left = i;
        for (int j = i + 1; j < sz; ++j) {
            int right = j;
            while (left < right) {
                if (s[left] == s[right]) {
                    ++left;
                    --right;
                }
                else {
                    break;
                }
            }
            if (left >= right) {                    //i-j区间为回文串
                pal_str.push_back({i, j});
            }
            left = i;           //以i开头 重置left   没有回文串也可能改变
        }
    }

    //依次遍历每个回文串，找出以此回文串构成的分割方案
    vector<string>  one_str;        //存储一种分割方案
    int sz_pal = pal_str.size();
    string temp_str;
    for (int i = 0; i < sz_pal; ++i) {
        auto first = pal_str[i];
        //存入回文串之前的单字符
        for (int b = 0; b < first.first; ++b) {
            temp_str = s[b];
            one_str.push_back(temp_str);
        }
        //存入回文串
        one_str.push_back(string(s.begin() + first.first, s.begin() + first.second + 1));
        next_pal(result, pal_str, i, s, one_str);
        one_str.clear();
    }

    //所有单字符
    for (int res_begin = 0; res_begin < s.size(); ++res_begin) {
        temp_str = s[res_begin];
        one_str.push_back(temp_str);
    }
    result.push_back(one_str);

    return result;
}
