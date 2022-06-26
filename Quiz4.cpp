#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

void print (queue<int>s) {
    while (!s.empty()) {
        cout << s.front() << " ";
        s.pop();
    }
    cout << endl;
}
void sortQ(queue<int> &q){
    if(q.empty() || q.size()==1){
        return;
    }
    queue<int> s;
    int size = q.size();
    int arr[size];
    for(int i= 0; i < size; i++){
        int prev = q.front();
        arr[i]=prev;
        q.pop();
    }
    for(int i=0; i<size; i++){
        for (int j=0; j<size-1; ++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0; i<size; i++){
            q.push(arr[i]);
    }
}

int main(){
    queue <int> q;

    q.push(3);
    q.push(-9);
    q.push(19);
    q.push(20);
    q.push(4);
    q.push(15);
    q.push(20);

    print(q);
    sortQ(q);
    print(q);
}
