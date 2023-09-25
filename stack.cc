#include <iostream>

#include <stack>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListStack {
  public:
    LinkedListStack() : stack_size_(0), stack_top_(nullptr) {}
    ~LinkedListStack(){
        // 遍历链表删除节点，释放内存
    }
    /* 获取栈的长度 */
    int getSize(){
        return stack_size_;
    }
    /* 判断栈是否为空 */
    bool isEmpty(){
        return getSize() == 0;
    }
    /* 入栈 */
    void push(int num){
        // 头插法
        ListNode* node = new ListNode(num);
        node->next = stack_top_;
        stack_top_ = node;
        stack_size_++;
    }
    void pop(){
        ListNode* tmp = stack_top_;
        stack_top_ = stack_top_->next;
        delete[] tmp;
        stack_size_--;
    }
    /* 访问栈顶元素 */
    int top(){
        if(isEmpty()){
            throw std::out_of_range("空栈");
        }
        return stack_top_->val;
    }
    /* 将 List 转化为 vector 并返回 */
    std::vector<int> toVector(){
        ListNode* node = stack_top_;
        std::vector<int> vec(getSize());
        for(int i = 0; i < getSize(); i++){
            vec[i] = node->val;
            node = node->next;
        }
    }
  private:
    int stack_size_;
    ListNode* stack_top_;
};

int main(){
    std::stack<int> stack;
    stack.emplace(1);

    return 0;
}
