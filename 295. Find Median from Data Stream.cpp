//
// Created by bhc on 2022/2/9.
//
#include<queue>
#include<iostream>
class MedianFinder {
    priority_queue<int> que;
    int size;
    int medium_index;
public:
    MedianFinder():size(0),medium_index(-1) {}

    void addNum(int num) {
        que.push(num);
        if(num>)
    }

    double findMedian() {

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */