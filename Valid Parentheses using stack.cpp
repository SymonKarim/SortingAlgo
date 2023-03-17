bool isValidParenthesis(string &expression)
{
   stack<char>stack;
   for(int j = 0 ; j<expression.size();j++){
       char ch = expression[j];
       if(ch=='(' or ch=='{' or ch=='['){
           stack.push(ch);
       }else{
         if (!stack.empty()) {
           char top = stack.top();
           if (( ch == ')' and top == '(') or 
           (ch == '}' and top == '{') or
               (ch == ']' and top == '[')) {
             stack.pop();
           } else
             return false;
         } else
           return false;
       }
   }
   if(stack.empty()) return true;
   else return false;
}
