void insertBottom(stack<int> &stack, int x){
     if(stack.empty()){
        stack.push(x);
        return;
    }
    int ans = stack.top();
    stack.pop();
    insertBottom(stack,x);
    stack.push(ans);

}
void reverseStack(stack<int> &stack) {
    if(stack.size()==0){
        return;
    }
    int ans = stack.top();
    stack.pop();
    reverseStack(stack);
    insertBottom(stack,ans);
}
