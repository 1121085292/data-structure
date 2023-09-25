#include <iostream>

#include <stack>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListQueue {
  public:
    LinkedListQueue() : queue_size_(0), front_(nullptr), rear_(nullptr) {}
    ~LinkedListQueue(){}

    /* 获取队列的长度 */
    int getSize(){
        return queue_size_;
    }
    /* 判断队列是否为空 */
    bool isEmpty(){
        return queue_size_ == 0;
    }
    /* 入队 */
    void push(int num){
        // 尾节点后添加 num
        ListNode* node = new ListNode(num);
        // 如果队列为空，则令头、尾节点都指向该节点
        if(isEmpty()){
            front_ = node;
            rear_ = node;
        }
        // 如果队列不为空，则将该节点添加到尾节点后
        else {
            rear_->next = node;
            rear_ = node;
        }
        queue_size_++;
    }
    /* 出队 */
    void pop(){
        front_ = front_->next;
        queue_size_--;
    }
    /* 访问队首元素 */
    int peek(){
        if(isEmpty()){
            throw std::out_of_range("空队列");
        }
        return front_->val;
    }
    /* 将链表转化为 Vector 并返回 */
    std::vector<int> toVector(){
        std::vector<int> vec(getSize());
        ListNode* node = front_;
        for(int i = 0; i < getSize(); i++){
            vec[i] = node->val;
            node = node->next;
            // vec[i] = peek();
            // pop();
        }
        return vec;
    }
  private:
    ListNode* front_;
    ListNode* rear_;
    int queue_size_;
};

int main(){

    return 0;
}