#include<stdio.h>
queue(int) q1;
queue(int)q2;
int Top;
void push(int x) {
    q1.push(x);
    Top = x;
}
int top() {
    return Top;
}
bool empty() {
    return q1.empty();
}
int pop() {
    int n = q1.size();
    for (int i = 0; i < n - 1; i++) {
        int curr = q1.front();
        q1.pop();
        q2.push(curr);
        Top = curr;
    }
    int ele = q1.front();
    q1.pop();
    n = q2.size();
    for (int i = 0; i < n; i++) {
        q1.push(q2.front());
        q2.pop();
    }
    return ele;
}
int main() {
    push(1);
    push(2);
    cout<<top()<<endl;
    cout<<pop()<<endl;
    if (empty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    return 0;
}
