/*移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//                              2021/9/7
ListNode* question_203(ListNode* head, int val) {
    if(head == nullptr)
        return head;
    ListNode *new_head = nullptr;
    while (head->val == val) {
        if(head->next == nullptr)
            return new_head;
        head = head->next;
    }
    new_head = head;

    while (head->next != nullptr) {
        while (head->next->val == val) {
            if(head->next->next == nullptr) {
                head->next = nullptr;
                return new_head;
            }
            head->next = head->next->next;
        }
        head = head->next;
    }
    return new_head;
}
