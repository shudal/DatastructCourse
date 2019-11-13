#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "SqStack.cpp"
using namespace std;

const int maxsize = 100;

int getType(char c) {
    if (c=='+' || c=='-' || c== '*' || c=='/') {
        return 2;
    }
    if (c=='(' || c==')') {
        return 3;
    }
    return 1;
}

int getLevel(char c) {
    if (c=='+' || c=='-') {
        return 1;
    }
    if (c=='*' || c=='/') {
        return 2;
    }
}
int calFromSufExp(string s) {
    int result = 0;
    SqStack<int> sqStack;
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        int cType = getType(c);
        if (cType == 1) {
            int n = c - '0';
            sqStack.push(n);
        }
        if (cType == 2) {
            int n1, n2, r;
            sqStack.pop(n1);
            sqStack.pop(n2);
            switch (c) {
                case '+':
                    r = n1 + n2; break;
                case '-':
                    r =  n2 - n1; break;
                case '*':
                    r = n1 * n2; break;
                case '/':
                    r = n2 / n1; break;
            }
            sqStack.push(r);
        }
    }
    sqStack.pop(result);
    return result;
}
int main() {
    SqStack<char> sqStack(maxsize);
    string s;
    cin>>s;
    string sufExp = "";
    int flag = 0;
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        if (c=='=') {
            break;
        }

        int cType = getType(c);
        if (cType == 1) {
            sufExp += c;
            continue;
        }
        if (cType == 2) {
            char topC;
            int level1 = getLevel(c);
            sqStack.getTop(topC);
            while (! sqStack.isEmpty()) {
                sqStack.getTop(topC);
                if (topC == '(') {
                    break;
                }
                int level2 = getLevel(topC);
                if (level2 < level1) {
                    break;
                }
                sqStack.pop(topC);
                sufExp += topC;
            }
            sqStack.push(c);
        }
        if (cType == 3) {
            if (c == ')') {
                char cTop;
                sqStack.pop(cTop);
                while (cTop != '(') {
                    sufExp += cTop;
                    sqStack.pop(cTop);
                }
            }
            if (c == '(') {
                sqStack.push(c);
            }
        }
    }
    while (! sqStack.isEmpty()) {
        char c;
        sqStack.pop(c);
        sufExp += c;
    }

    cout<<"后缀表达式："<<sufExp<<endl;

    int result = calFromSufExp(sufExp);
    cout<<"结果为"<<result<<endl;;
}
