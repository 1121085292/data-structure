#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct Pair {
    int key;
    std::string val;
    Pair(int key, std::string val){
        this->key = key;
        this->val = val;
    }
};
/* 基于数组简易实现的哈希表 */
class ArrayHashMap {
  public:
    ArrayHashMap(){
        buckets_ = std::vector<Pair *> (100);
    }
    ~ArrayHashMap(){
        for(const auto& bucket : buckets_){
            delete bucket;
        }
        buckets_.clear();
    }
    /* 哈希函数 */
    int hashFunc(int key){
        int index = key % 100;
        return index;
    }
    /* 查询操作 */
    std::string get(int key){
        int index = hashFunc(key);
        Pair* pair = buckets_[index];
        if(pair == nullptr) return nullptr;
        return pair->val;
    }
    /* 添加操作 */
    void put(int key, std::string val){
        Pair* pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets_[index] = pair;
    }
    /* 删除操作 */
    void remove(int key){
        int index = hashFunc(key);
        delete buckets_[index];
        buckets_[index] = nullptr;
    }
    /* 获取所有键值对 */
    std::vector<Pair*> pairSet(){
        std::vector<Pair*> vec;
        for(const auto& bucket : buckets_){
            if(bucket != nullptr){
                vec.push_back(bucket);
            }
        }
        return vec;
    }
    /* 打印哈希表 */
    void print(){
        for(const auto& kv : buckets_){
            std::cout << kv->key << "->" << kv->val << std::endl;
        }
    }
  private:
    std::vector<Pair *> buckets_;
};


int main(){
    std::unordered_map<int, std::string> map; 
    map[123] = "xiao";
    std::string name  = map[123];
    map.erase(123);
    /* 遍历哈希表 */
    // 遍历键值对 key->value
    for(const auto& kv : map){
        std::cout << kv.first << "->" << kv.second << std::endl;
    }
    return 0;
}