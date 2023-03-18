#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char>stack;
    for(auto i:s){
         if( i=='(' or i == '*' or i == '/' or i == '+' or i =='-'){
             stack.push(i);
         }else if(i==')'){
             bool check = false;
             while(!stack.empty()){
                 char ii = stack.top(); 
                 stack.pop(); 
                  if (ii == '(') {
                   break;
                 }
                 else if(ii == '*' or ii == '/' or ii == '+' or ii =='-'){
                     check  = true;
                 }
             }
             if (!check)
               return true;
         }
    }
 return false;
}
