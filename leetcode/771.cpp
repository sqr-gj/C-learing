/*宝石与石头
给定字符串J代表石头中宝石的类型,和字符串S代表你拥有的石头。S中每个字符代表了一种你拥有的石头的类型,你想知道你拥有的石头中有多少是宝石。
J中的字母不重复，J和S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

示例 1:
输入: J = "aA", S = "aAAbbbb"
输出: 3

示例 2:
输入: J = "z", S = "ZZ"
输出: 0

注意:
S 和 J 最多含有50个字母。
J 中的字符不重复。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jewels-and-stones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <iterator>
#include <iostream>

using namespace std;

//暴力搜索      2021/7/2
int question_771(string jewels, string stones) {
    int cnt = 0;

    for(auto j : jewels){
//        for(auto s : stones){
//            if(j == s)
//                ++cnt;
//        }
        //优化思路： 把已经计数的s从stones中删除
        for(size_t p = 0; p < stones.size(); ){
            if(stones[p] == j){
                ++cnt;
                stones.erase(p, 1);
            }
            else
                ++p;
        }
    }
    return cnt;
}
