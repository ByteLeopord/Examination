class CQueue {
    stack<int> s1, s2;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = -1;
        if(!s2.empty()){
            val = s2.top();
            s2.pop();
        }
        return val;
    }
};
