/* 实现strStr()
实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

示例 1：
输入：haystack = "hello", needle = "ll"
输出：2

示例 2：
输入：haystack = "aaaaa", needle = "bba"
输出：-1

示例 3：
输入：haystack = "", needle = ""
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>

using namespace std;

//简单题写KMP，简直  暴力保命          2021/9/15
//int strStr(string haystack, string needle) {
//    int sz_hay = haystack.size();
//    int sz_nee = needle.size();
//    if(sz_nee == 0)
//        return 0;
//    if(sz_hay < sz_nee)
//        return -1;

//    for (int pre = 0; pre <= sz_hay - sz_nee; ++pre) {
//        if(haystack[pre] == needle[0]) {             //首字母匹配
//            int next = pre;
//            for (int i = 1; i < sz_nee; ++i) {
//                if(needle[i] != haystack[++next])
//                    break;
//            }
//            if((next - pre + 1) == sz_nee && haystack[next] == needle[sz_nee - 1])
//                return pre;
//        }
//    }
//    return -1;
//}

//KMP                               2021/9/16
int strStr(string haystack, string needle) {
    int sz_hay = haystack.size();
    int sz_nee = needle.size();
    if(sz_nee == 0)
        return 0;
    if(sz_hay < sz_nee)
        return -1;

    //预处理   前缀表
    vector<int> next(sz_nee);
    int j = 0;
    for (int i = 1; i < sz_nee; ++i) {
        while (j > 0 && needle[i] != needle[j]) {
            j = next[j - 1];
        }
        if(needle[i] == needle[j])
            ++j;
        next[i] = j;
    }

    //匹配
    j = 0;
    for (int i = 0; i < sz_hay; ++i) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) {
            if (j == sz_nee - 1)
                return i - sz_nee + 1;
            ++j;
            continue;
        }
    }
    return -1;

}
