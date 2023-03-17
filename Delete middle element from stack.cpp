#include <bits/stdc++.h> 
void solve(stack<int>&inputStack, int cnt,int &size){
   if(cnt == size/2){
      inputStack.pop();
      return;
   }
   int ans = inputStack.top(); 
   inputStack.pop();
   solve(inputStack,  cnt+1,size);
   inputStack.push(ans);
}
void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack, 0,N);
   return;  
}
