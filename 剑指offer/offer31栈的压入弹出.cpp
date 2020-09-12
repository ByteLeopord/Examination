class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int index = 0, popindex = 0;
        int len = pushed.size();
        while(index < len){
            sk.push(pushed[index++]);
            while(!sk.empty() && sk.top() == popped[popindex]){
                sk.pop();
                popindex++;
            }
        }
        return sk.empty();
    }
};
