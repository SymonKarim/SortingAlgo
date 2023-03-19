#include <bits/stdc++.h> 
class Deque
{
    int *arr;
    int size;
    int Front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        Front = -1;
        rear= -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
       if(isFull()) return false;
       else if(isEmpty()){
            Front = rear = 0;
            arr[Front] = x;
        }
        else if(Front == 0 and rear !=size-1){
            Front = size-1;
        }else{
            Front--;
        }
        arr[Front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
       if(isFull()) return false;
       else if(isEmpty()){
            Front = rear = 0;
        }
        else if(Front != 0 and rear ==size-1){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        int ans = arr[Front];
        arr[Front] = -1;
        if(Front == rear){
            Front = rear = -1;
        }
        else if(Front == size-1){
            Front = 0;
        }else Front++;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(Front == rear){
            Front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }else rear--;
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(Front == -1 ) return -1;
        return arr[Front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty() ) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(Front == -1) return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((Front == 0 and rear == size-1) || (Front!=0 and rear == (Front-1)%(size-1))) return true;
        else return false;
    }

};
