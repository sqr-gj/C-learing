/*快乐数
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

示例 1：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：
输入：n = 2
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_set>
#include <vector>

using namespace std;

//                          2021/9/11
bool question_202(int n) {
    unordered_set<int> calculated;
    int sum = 0;

    while (true) {
        calculated.insert(n);
        vector<int> num_bit;
        //读取每位的数
        while (n != 0) {
            int num = n % 10;
            num_bit.push_back(num);
            n /= 10;
        }
        //计算位平方和
        for(int num : num_bit) {
            sum += num * num;
        }
        if (sum == 1)
            return true;
        if (calculated.count(sum))
            return false;
        n = sum;
        sum = 0;
    }
    return false;
}
