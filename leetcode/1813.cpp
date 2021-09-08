/*句子相似性Ⅲ
一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，"Hello World" ，"HELLO" ，"hello world hello world"
都是句子。每个单词都 只 包含大写和小写英文字母。
如果两个句子 sentence1 和 sentence2 ，可以通过往其中一个句子插入一个任意的句子（可以是空句子）而得到另一个句子，那么我们称这两个句子是相似的 。
比方说，sentence1 = "Hello my name is Jane" 且 sentence2 = "Hello Jane" ，我们可以往 sentence2 中 "Hello" 和 "Jane" 之间插入
"my name is" 得到 sentence1 。
给你两个句子 sentence1 和 sentence2 ，如果 sentence1 和 sentence2 是相似的，请你返回 true ，否则返回 false 。

示例 1：
输入：sentence1 = "My name is Haley", sentence2 = "My Haley"
输出：true
解释：可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1。

示例 2：
输入：sentence1 = "of", sentence2 = "A lot of words"
输出：false
解释：没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。

示例 3：
输入：sentence1 = "Eating right now", sentence2 = "Eating"
输出：true
解释：可以往 sentence2 的结尾插入 "right now" 得到 sentence1。

示例 4：
输入：sentence1 = "Luky", sentence2 = "Lucccky"
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sentence-similarity-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

//              2021/7/19
bool question_1813(string sentence1, string sentence2) {
    //第一句为长句子
    if(sentence1.size() < sentence2.size())
        swap(sentence1, sentence2);

    vector<string> sentence_1, sentence_2;          //存储句子中的单词

    istringstream s1(sentence1);
    istringstream s2(sentence2);
    string word;

    while (s1 >> word) {
        sentence_1.push_back(word);
    }

    while (s2 >> word) {
        sentence_2.push_back(word);
    }

    //存在空句子
    if(!sentence_1.size() || !sentence_2.size())
        return true;

    int k;
    for(size_t left_2 = 0; left_2 < sentence_2.size(); ++left_2){
        k = left_2;
        if(sentence_2[left_2] != sentence_1[left_2])
            break;
    }

    if(sentence_2[k] == sentence_1[k])
        return true;

    int right_1 = sentence_1.size() - 1;
    for(int right_2 = sentence_2.size() - 1; right_2 >= k; --right_2){
        if(sentence_2[right_2] != sentence_1[right_1--])
            return false;
    }

    return true;
}
