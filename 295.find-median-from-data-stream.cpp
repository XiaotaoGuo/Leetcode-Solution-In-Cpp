/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start

#include <queue>

using namespace std;


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smallerHalf.empty() || num < smallerHalf.top()){
            smallerHalf.push(num);
        }
        else{
            largerHalf.push(num);
        }
        
        if(smallerHalf.size() < largerHalf.size()){
            smallerHalf.push(largerHalf.top());
            largerHalf.pop();
        }
        else if(smallerHalf.size() - largerHalf.size() == 2){
            largerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        }
    }
    
    double findMedian() {
        double l = smallerHalf.top();
        if(smallerHalf.size() == largerHalf.size()){
            double r = largerHalf.top();
            return (l + r) / 2;
        }
        return l;
    }

private:
    priority_queue<int, vector<int>, less<int>> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> largerHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

