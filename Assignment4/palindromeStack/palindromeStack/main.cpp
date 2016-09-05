/*
 ** Colin Walsh
 ** cjw254@psu.edu
 ** Assignment 5,
 ** Program that sees if a word or sentence is a palidrome
 */

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(string);
int main(int argc, const char * argv[]) {
    string st;
    cout << "Enter a string you want to check if it is a palindrome ";
    getline(cin, st);
    
    if (isPalindrome(st)){
        cout << "This is a palidrome\n";
    }else{
        cout << "This is not a palidroms \n";
    }
}
bool isPalindrome(string str){
    stack<char> charStack;
    bool flag = false;
    str.erase(remove( str.begin(), str.end(),' '), str.end() );//removes whitespace
    
    for (int i = 0; i < str.length(); i++) {
        charStack.push(tolower(str[i])); //pushes string onto the stack
        
    }
    for (int i = 0; i < str.length(); i++) {
        if (charStack.top() == tolower(str[i])) {//checks top of stack to first element of string
            flag = true;
            charStack.pop();
        }else{
            return false;
        }
    }
    return flag;
}

