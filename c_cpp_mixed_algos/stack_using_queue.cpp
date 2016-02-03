#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Stack {
public:
    queue<int> Q;
 
    void push(int x) {
        Q.push(x);
    }
 
     //roatate queue elements to right
    void roatateQ(int times){
        for(int i = 0; i!= times; ++i)
        {
            int front = Q.front();
            Q.pop();
            Q.push(front);
        }
 
    }
 
    void pop() {
        if(Q.size()==0) return;

        for(int i = 0; i!= Q.size() -1; ++i)
        {
            int front = Q.front();
            Q.pop();
            Q.push(front);
        }
        Q.pop();
    }
 
    int top() {
        if(Q.size()==0) return 0;
        roatateQ(Q.size() -1);
        int ans = Q.front();
        roatateQ(1);
        return ans;
    }
 
    bool empty() {
        if(Q.size()==0) return true;
        else return false;
 
    }
};

int main(){
    Stack S;
    S.push(1);
    S.push(2);
    cout << S.top() << endl;
    
    S.pop();
    S.push(3);
    S.push(4);
    
    cout << S.top() << endl;
    S.pop();
    cout << S.top() << endl;
}