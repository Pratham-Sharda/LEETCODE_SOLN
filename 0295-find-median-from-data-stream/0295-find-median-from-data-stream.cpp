class MedianFinder {
public:
    priority_queue<int> leftmax;
    priority_queue<int,vector<int>,greater<int>> rightmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftmax.empty() || num<leftmax.top()){
            leftmax.push(num);
        }else{
            rightmin.push(num);
        }


        if(leftmax.size()<rightmin.size()){
            leftmax.push(rightmin.top());rightmin.pop();
        }
        while(leftmax.size()-rightmin.size()>1){
            rightmin.push(leftmax.top());leftmax.pop();
        }
    }
    
    double findMedian() {
        if(rightmin.size()==leftmax.size()){
            double ans=(((double)rightmin.top()+(double)leftmax.top())/2);
            // cout<<rightmin.top()<<leftmax.top()<<ans;
            return ans;        
        }
        return leftmax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */