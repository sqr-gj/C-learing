/*反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//                          2021/8/23
ListNode* question_206(ListNode* head) {
    if(head->next == nullptr)
        return head;
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur->next != nullptr) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return cur;
}
