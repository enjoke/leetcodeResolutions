#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * 641. 设计循环双端队列
 * 设计实现双端队列。
 * 你的实现需要支持以下操作：
 * MyCircularDeque(k)：构造函数,双端队列的大小为k。
 * insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
 * insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
 * deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
 * deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
 * getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
 * getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
 * isEmpty()：检查双端队列是否为空。
 * isFull()：检查双端队列是否满了。
 * 示例：
 * 
 * MyCircularDeque circularDeque = new MycircularDeque(3);  
 * circularDeque.insertLast(1);			 
 * circularDeque.insertLast(2);			 
 * circularDeque.insertFront(3);			 
 * circularDeque.insertFront(4);			 
 * circularDeque.getRear();  				 
 * circularDeque.isFull();				 
 * circularDeque.deleteLast();			 
 * circularDeque.insertFront(4);			 
 * circularDeque.getFront();				 
 * 
 * 
 * 
 * 提示：
 * 
 * 所有值的范围为 [1, 1000]
 * 操作次数的范围为 [1, 1000]
 * 请不要使用内置的双端队列库。
 * 
 */
typedef struct {
    int front[1000];
    int rear[1000];
    int cap;
    int size;
    int head;
    int tail;
    int front_frist;
    int rear_first;
} MyCircularDeque;
/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* p = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    if(NULL == p)
        return p;
    p->size = 0;
    p->head = 0;
    p->tail = 0;
    p->cap = k;
    p->front_frist = 0;
    p->rear_first = 0;
    return p;
}
/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->cap == obj->size)
        return false;
    obj->front[obj->head++] = value;
    obj->size++;
    return true;
}
/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
     if(obj->cap == obj->size)
        return false;
    obj->rear[obj->tail++] = value;
    obj->size++;
    return true;
}
/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;
    if(obj->head>0){
        obj->head--;
    }
    else{
        obj->rear_first++;
    }
    obj->size--;
    return true;
}
/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;
    if(obj->tail>0){
        obj->tail--;
    }
    else {
        obj->front_frist++;
    }
    obj->size--;
    return true;
}
/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    if(obj->head > 0  && obj->front_frist < obj->head)
        return obj->front[obj->head-1];
    return obj->rear[obj->rear_first];
}
/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    if(obj->tail > 0  && obj->rear_first < obj->tail)
        return obj->rear[obj->tail-1];
    return obj->front[obj->front_frist];
}
/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}
/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->cap;
}
void myCircularDequeFree(MyCircularDeque* obj) {
    if(NULL != obj) 
        free(obj);
}
void print(bool boolean){
    if(boolean)
        printf("true,");
    else
        printf("false,");
}
#define insertFront(x)  print(myCircularDequeInsertFront(obj, x))
#define insertLast(x)   print(myCircularDequeInsertLast(obj, x))
#define getFront        printf("%d,", myCircularDequeGetFront(obj)) 
#define getRear         printf("%d,", myCircularDequeGetRear(obj))
#define isEmpty         print(myCircularDequeIsEmpty(obj))
#define isFull          print(myCircularDequeIsFull(obj))
#define deleteFront     print(myCircularDequeDeleteFront(obj))
#define deleteLast      print(myCircularDequeDeleteLast(obj))
int main(int argc, char **argv)
{
    MyCircularDeque* obj = myCircularDequeCreate(43);
    if(NULL == obj){
        printf("create failed!\n");
        return -1;
    }
    printf("null,");  
    insertFront(86);  
    getFront;         
    insertLast(98);   
    deleteLast;      
    getFront;
    insertLast(44);
      printf("%s,", myCircularDequeInsertLast(obj, 69));
    insertLast(69);
    deleteLast;
    isFull;
    deleteLast;
    isFull;
    getFront;
    deleteLast;
    getFront;
    isEmpty;
    insertLast(85);
    insertLast(46);
    insertLast(56);
    getRear;
    insertFront(52);
    getFront;
    deleteFront;
    isEmpty;
    insertLast(59);
    deleteFront;
    getRear;
    isEmpty;
    insertLast(18);
    insertLast(31);
    insertFront(60);
    getFront;
    getFront;
    insertFront(58);
    insertLast(84);
    deleteLast;
    getRear;
    isFull;
    getRear;
    insertFront(91);
    insertFront(76);
    isEmpty;
    insertFront(90);
    deleteFront;
    getRear;
    insertFront(35);
    deleteFront;
    getRear;
    getFront;
    getRear;
    insertLast(91);
    insertLast(24);
    getRear;
    isFull;
    insertFront(28);
    getFront;
    isFull;
    getFront;
    insertLast(2);
    deleteFront;
    insertLast(23);
    insertLast(40);
    deleteFront;
    getRear;
    insertFront(10);
    getRear;
    getFront;
    deleteFront;
    deleteFront;
    insertLast(53);
    deleteFront;
    getRear;
    deleteFront;
    deleteFront;
    insertFront(26);
    isEmpty;
    insertLast(11);
    insertLast(23);
    insertFront(38);
    isEmpty;
    deleteLast;
    getFront;
    insertLast(63);
    getRear;
    insertLast(87);
    getFront;
    myCircularDequeFree(obj);
    return 0;
}