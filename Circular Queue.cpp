#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int size;
    int rear;
    int Front;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
       size = n;
       arr = new int[n];
       rear = -1;
       Front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((Front ==0 and rear == size-1) ||(rear ==(Front-1)%(size-1))){
          return false;
        }
        else if(Front==-1){
            Front = rear = 0;
            arr[Front] =value;
        } else if(rear == size-1 and Front!=0){
            rear = 0;
            arr[rear] = value;
        }else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(Front ==-1){
            return -1;
        }
        int ans = arr[Front];
        arr[Front] = -1;
        
        if(Front == rear){
            rear = Front = -1;
        }else if(Front == size-1){
          Front = 0;
        }else{
            Front++;
        }
        return ans;
    }
};
