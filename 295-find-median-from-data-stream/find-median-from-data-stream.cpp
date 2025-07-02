class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    double median;

    MedianFinder() {
        this -> median = 0;
    }
    
    void addNum(int num) {
        if(minHeap.size() == maxHeap.size()){
            if(num < median){
                maxHeap.push(num);
                // update median
                median = maxHeap.top();
            }
            else{
                minHeap.push(num);
                median = minHeap.top();
            }
        }
        else if(maxHeap.size() == minHeap.size()+1){
            if(num < median){
                int element = maxHeap.top();
                maxHeap.pop();
                // insert element in minHeap
                minHeap.push(element);
                // insert actual num in max heap
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
            median = (maxHeap.top()+minHeap.top())/2.0;
        }
        else{
            if(num < median){
                maxHeap.push(num);
            }
            else{
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                minHeap.push(num);
            }
            median = (maxHeap.top() + minHeap.top())/2.0;         
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */