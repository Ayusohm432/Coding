/*
Problem Link : https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28
*/

/*641. Design Circular Deque

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

*/

//Approach-1

class MyCircularDeque {
    vector<int> deque;
    int k; 
    int front;
    int rear;
    int currentCount;
public:
    MyCircularDeque(int k) {
        this->k = k;
        deque = vector<int> (k);
        front = 0;
        rear = k-1;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front - 1 + k) % k;
        deque[front] = value;
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % k;
        deque[rear] = value;
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % k;
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + k) % k;
        currentCount--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return deque[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return deque[rear];
    }
    
    bool isEmpty() {
        return currentCount == 0;
    }
    
    bool isFull() {
        return currentCount == k;
    }
};

//Approach-2
//Approach-2
class MyCircularDeque {
    list<int> deque;
    int k;
public:
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        deque.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        deque.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        deque.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        deque.pop_back();
        return true;      
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return deque.front();
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return deque.back();
    }
    
    bool isEmpty() {
        return deque.size() == 0;
    }
    
    bool isFull() {
        return deque.size() == k;
    }
};