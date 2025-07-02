class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        priority_queue<int>maxHeap;

        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        // main logic

        while(maxHeap.size() >= 2){
            int element1 = maxHeap.top(); maxHeap.pop();
            int element2 = maxHeap.top(); maxHeap.pop();

            score++;

            element1--;
            element2--;

            if(element1 != 0) maxHeap.push(element1);
            if(element2 != 0) maxHeap.push(element2);
        }
        return score;
    }
};