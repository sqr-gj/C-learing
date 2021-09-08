/*删除链表的倒数第N个节点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
进阶：你能尝试使用一趟扫描实现吗？

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//                      2021/7/25
ListNode* question_19(ListNode* head, int n) {
    ListNode *first = head;
    ListNode *second = head;
    while(n-- > 0){
        second = second->next;
    }

    if(second == nullptr)       //删除第一个结点
        return head->next;

    while (second->next != nullptr) {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return head;
}
