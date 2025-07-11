class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    unordered_map<int,int>mp;

    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            pq.push(i);
            mp[i]++;
        }
    }
    
    int popSmallest() {
        int ans = pq.top();
        pq.pop();
        mp[ans]--;
        return ans;
    }
    
    void addBack(int num) {
        if(mp[num]<=0){
            // nahi hai
            //cout<<num;
            mp[num] = 1;
        pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */