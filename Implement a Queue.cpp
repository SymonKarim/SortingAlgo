#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int Front;
    int rear;
public:
    Queue() {
       size = 100001;
       arr = new int[size];
       Front = 0;
       rear = 0;
    }
    bool isEmpty() {
        if(rear == Front) return true; else return false;
    }

    void enqueue(int data) {
       if(rear == size){
        cout<<"Queue is full"<<endl;
       }else{
            arr[rear] = data;
            rear++;
       }
    }

    int dequeue() {
        if(rear == Front) return -1;
        else{
            int ans = arr[Front];
            arr[Front ] = -1;
            Front++;
            if(Front == rear){Front=0;rear = 0;}
            return ans;
        }
        
    }

    int front() {
        if(Front == rear) return -1;
        return arr[Front];
    }
};
