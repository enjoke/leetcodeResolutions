#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 706. 设计哈希映射
 * 
 * 不使用任何内建的哈希表库设计一个哈希映射
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
 * get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
 * remove(key)：如果映射中存在这个键，删除这个数值对。
 * 
 * 示例：
 * 
 * MyHashMap hashMap = new MyHashMap();
 * hashMap.put(1, 1);          
 * hashMap.put(2, 2);         
 * hashMap.get(1);            // 返回 1
 * hashMap.get(3);            // 返回 -1 (未找到)
 * hashMap.put(2, 1);         // 更新已有的值
 * hashMap.get(2);            // 返回 1 
 * hashMap.remove(2);         // 删除键为2的数据
 * hashMap.get(2);            // 返回 -1 (未找到) 
 * 
 * 注意：
 * 
 * 所有的值都在 [1, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希库。
 */

typedef struct {
    int key[1000001];
    int value[1000001];
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    if(NULL == obj)
        return NULL;

    memset(obj->key, 0, 1000001);
    memset(obj->value, 0, 1000001);
    return obj;
}

/** value will always be positive. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    if(NULL == obj)
        return;
    
    obj->key[key] = 1;
    obj->value[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    if(NULL == obj)
        return;

    if(0 == obj->key[key])
        return false;

    return obj->value[key];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    if(NULL == obj)
        return;

    obj->key[key] = 0;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * struct MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 * int param_2 = myHashMapGet(obj, key);
 * myHashMapRemove(obj, key);
 * myHashMapFree(obj);
 */
int main(int argc, char **argv)
{
    
    return 0;
}