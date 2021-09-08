/*设计链表
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。
如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

示例：
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//                          2021/9/8
class MyLinkedList {
public:
    int get(int index) {            //获取第index个节点的值
        if(index < 0 || index > (_size - 1))
            return -1;
        LinkedNode *cur = _dummyHead->next;
        while (index) {
            cur = cur->next;
            --index;
        }
        return cur->val;
    }
    void addAtHead(int val) {       //添加头结点
        LinkedNode *Node = new LinkedNode(val);
        Node->next = _dummyHead->next;
        _dummyHead->next = Node;
        ++_size;
    }
    void addAtTail(int val) {       //添加尾节点
        LinkedNode *Node = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = Node;
        ++_size;
    }
    void addAtIndex(int index, int val) {           //在第index个节点前添加节点
        if(index > _size)
            return;
        if(index <= 0)
            return addAtHead(val);

        LinkedNode *Node = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (index) {
            cur = cur->next;
            --index;
        }

        Node->next = cur->next;
        cur->next = Node;
        ++_size;
    }
    void deleteAtIndex(int index) {         //删除第index个节点
        if(get(index) == -1)
            return;

        LinkedNode *cur = _dummyHead;
        while (index) {
            cur = cur->next;
            --index;
        }
        cur->next = cur->next->next;
        --_size;
    }
    struct LinkedNode {
            int val;
            LinkedNode *next;
            LinkedNode() : val(0), next(nullptr){}
            LinkedNode(int val) : val(val), next(nullptr){}
            LinkedNode(int val, LinkedNode *next) : val(val), next(next){}
        };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
private:
    int _size = 0;
    LinkedNode *_dummyHead;         //虚拟头结点
};
