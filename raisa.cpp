#include <iostream>
#include <stack>
#include <queue>

using namespace std;
void generate(int n){
    if (n ==0){
        cout<<n<<" ";
        return;
    }
    else{
        int a = n;
        generate(--n);
        cout<<a<<" ";
    }

}
int main (){
    queue<int> q;
    for (int i = 1; i <= 6; i++) {
        q.push(i);
    }
    for (int i = 0; i < q.size(); i++) {
        cout << q.front() << endl;
		q.pop();
    }

    cout<< "  size " << q.size() << endl;
    return 0;

}
