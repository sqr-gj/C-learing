/* 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：
你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

进阶：
你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>

using namespace std;

//                      2021/9/22
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {


    }

    /** Push element x to the back of queue. */
    void push(int x) {
        sta_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sta_out.empty()) {
            while (!sta_in.empty()) {
                sta_out.push(sta_in.top());
                sta_in.pop();
            }
        }
        int result = sta_out.top();
        sta_out.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int result = pop();
        sta_out.push(result);
        return result;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return sta_in.empty() && sta_out.empty();
    }
private:
    stack<int> sta_in;
    stack<int> sta_out;
};
