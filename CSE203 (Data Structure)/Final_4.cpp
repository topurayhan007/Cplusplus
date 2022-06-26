#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void collectionMystery10(stack<int>& s, int n) {
    stack<int> st;
    queue<int> q;
​    int size = s.size();
    while (size > n) {
        int d = s.top();
        q.push(d);
        s.pop();
    }
    while (!s.empty()) {
        int element = s.top(); 
        s.pop();
        st.push(element);
        if (element % 2 == 0) {
            q.push(element);
        }
    }
    while (!q.empty()) {
        int b = q.front();
        s.push(b);
        q.pop();
    }
    while (!st.empty()) {
        int a = st.top();
        s.push(a);
        st.pop();
    }
​     while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
    }
   
}

int main(){
    //{2, 4, 6, 8, 10}
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    collectionMystery10(s, 3);
    

}