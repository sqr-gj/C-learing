/* 找出临界点之间的最小和最大距离
链表中的 临界点 定义为一个 局部极大值点 或 局部极小值点 。
如果当前节点的值 严格大于 前一个节点和后一个节点，那么这个节点就是一个  局部极大值点 。
如果当前节点的值 严格小于 前一个节点和后一个节点，那么这个节点就是一个  局部极小值点 。
注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 局部极大值点 / 极小值点 。
给你一个链表 head ，返回一个长度为 2 的数组 [minDistance, maxDistance] ，
其中 minDistance 是任意两个不同临界点之间的最小距离，maxDistance 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 [-1，-1] 。

示例 1：
输入：head = [3,1]
输出：[-1,-1]
解释：链表 [3,1] 中不存在临界点。

示例 2：
输入：head = [5,3,1,2,5,1,2]
输出：[1,3]
解释：存在三个临界点：
- [5,3,1,2,5,1,2]：第三个节点是一个局部极小值点，因为 1 比 3 和 2 小。
- [5,3,1,2,5,1,2]：第五个节点是一个局部极大值点，因为 5 比 2 和 1 大。
- [5,3,1,2,5,1,2]：第六个节点是一个局部极小值点，因为 1 比 5 和 2 小。
第五个节点和第六个节点之间距离最小。minDistance = 6 - 5 = 1 。
第三个节点和第六个节点之间距离最大。maxDistance = 6 - 3 = 3 。

示例 3：
输入：head = [1,3,2,2,3,2,2,2,7]
输出：[3,3]
解释：存在两个临界点：
- [1,3,2,2,3,2,2,2,7]：第二个节点是一个局部极大值点，因为 3 比 1 和 2 大。
- [1,3,2,2,3,2,2,2,7]：第五个节点是一个局部极大值点，因为 3 比 2 和 2 大。
最小和最大距离都存在于第二个节点和第五个节点之间。
因此，minDistance 和 maxDistance 是 5 - 2 = 3 。
注意，最后一个节点不算一个局部极大值点，因为它之后就没有节点了。

示例 4：
输入：head = [2,3,3,2]
输出：[-1,-1]
解释：链表 [2,3,3,2] 中不存在临界点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

//题解：https://leetcode-cn.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/solution/yi-ci-bian-li-by-cao-mu-hui-d-kpx5/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//                                          2021/12/21
void get_CriticalPoints(ListNode *node, int coor, vector<int> &CriticalPoints) {
    if (!node->next->next)
        return;
    if ((node->next->val > node->val && node->next->val > node->next->next->val) || (node->next->val < node->val && node->next->val < node->next->next->val))
        CriticalPoints.push_back(coor);
    get_CriticalPoints(node->next, coor + 1, CriticalPoints);

}

vector<int> question_2058(ListNode* head) {
    vector<int> CriticalPoints;
    get_CriticalPoints(head, 1, CriticalPoints);

    int sz = CriticalPoints.size();
    if (sz < 2)
        return {-1, -1};

    int max = CriticalPoints[sz - 1] - CriticalPoints[0];
    int min = 100000;
    for (int i = sz - 1; i > 0; --i) {
        min = (CriticalPoints[i] - CriticalPoints[i - 1]) < min ? (CriticalPoints[i] - CriticalPoints[i - 1]) : min;
    }
    return {min, max};

    //                          2021/10/31
//    vector<int> max_or_min;
//    int cnt = 1;
//    int pre = head->val;
//    head = head->next;
//    while (head) {
//    ++cnt;
//    int now = head->val;
//    if (head->next) {
//        if ((now > pre && head->next->val < now) || (now < pre && head->next->val > now))
//            max_or_min.push_back(cnt);
//        pre = now;
//        head = head->next;
//    }
//    else {
//        break;
//    }
//    }
//    int sz = max_or_min.size();
//    if (sz < 2)
//        return {-1, -1};
//    int min = 1000000;
//    for (int i = 1; i < sz; ++i) {
//        if ((max_or_min[i] - max_or_min[i - 1]) < min)
//            min = max_or_min[i] - max_or_min[i - 1];
//    }
//    return {min, max_or_min[sz - 1] - max_or_min[0]};

    //                          2021/12/21
//    int first = 0;
//    int pre = 0;
//    int min = 100000;
//    int coor = 1;

//    while (true) {
//        if (!head->next->next)
//            break;
//        //  head->next为临界点
//        if ((head->next->val > head->val && head->next->val > head->next->next->val) || (head->next->val < head->val && head->next->val < head->next->next->val)) {
//            if (first == 0) //第一个临界点
//                first = coor;
//            else {
//                min = (coor - pre) < min ? (coor - pre) : min;
//            }
//            pre = coor;
//        }
//        head = head->next;
//        ++coor;
//    }
//    if (first == pre)
//        return {-1, -1};
//    return {min, pre - first};
}
