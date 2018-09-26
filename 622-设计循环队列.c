#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 * 你的实现应该支持如下操作：
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 * 示例：
 * MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为3
 * circularQueue.enQueue(1);  // 返回true
 * circularQueue.enQueue(2);  // 返回true
 * circularQueue.enQueue(3);  // 返回true
 * circularQueue.enQueue(4);  // 返回false,队列已满
 * circularQueue.Rear();  // 返回3
 * circularQueue.isFull();  // 返回true
 * circularQueue.deQueue();  // 返回true
 * circularQueue.enQueue(4);  // 返回true
 * circularQueue.Rear();  // 返回4
 * 提示：
 * 所有的值都在 1 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 */

/**
 * 循环队列
 * 设有循环队列 queue, 其最大容量capacity, 队头front, 队尾 rear，则有以下属性
 * 空队列   front == rear;
 * 满队列   front = (rear + 1) % capacity
 * 队列长度 (front + rear + capacity) % capacity
 * 入队     rear = (rear + 1) % capacity
 * 出队     front = (front + 1) % capacity
 */

typedef struct {
    int *queue;
    int head;
    int tail;
    int maxsize;
    
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *circularqueue;
    circularqueue = malloc(sizeof(MyCircularQueue));
        
    if(circularqueue == NULL)
    {
        exit(-1);
    }
    
    k++;
    circularqueue->queue = malloc(k * sizeof(int));
    
    if(circularqueue->queue == NULL)
    {
        exit(-1);
    }
    
    circularqueue->head = circularqueue->tail = 0;
    circularqueue->maxsize = k;
    
    return circularqueue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->head == obj->tail);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->head == (obj->tail + 1) % obj->maxsize);
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;

    obj->queue[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->maxsize;
    return true;
    
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;

    obj->head = (obj->head + 1) % obj->maxsize;
    return true;    
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;

    return obj->queue[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;

    return obj->queue[(obj->tail + obj->maxsize - 1) % obj->maxsize];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    obj->queue = NULL;
    free(obj);
    obj = NULL;
}
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */