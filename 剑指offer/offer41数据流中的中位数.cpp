/*
大顶堆 保存小于等于中位数的数字
小顶堆 保存大于中位数的数字
每次加入新数字 先加到大顶堆中 再将大顶堆的top值放到小顶堆中 最后比较两者长度 
如果小顶堆较长 将小顶堆的top值放到大顶堆中 维持平衡

查找时 如果两个堆长度不同 则中位数为大顶堆的top值
                 长度相同 则为两个堆的top值平均数
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> large;
    priority_queue<int, vector<int>, greater<int>> little;
    MedianFinder() {

    }
    
    void addNum(int num) {
        large.push(num);
        little.push(large.top());
        large.pop();
        if(little.size() > large.size()){
            large.push(little.top());
            little.pop();
        }
    }
    
    double findMedian() {
        if(large.size() > little.size()){
            return large.top();
        }
        else{
            return (large.top() + little.top()) * 0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
