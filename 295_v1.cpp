/*
  295_v1.cpp
  Find Median from Data Stream

  My first submission always inserts the first element to the maxHeap and the
  second element to the minHeap. It was clearly wrong. My second, third and
  fourth submission got WA because I've mistakenly written if (numElements == 1)
  and if (numElements == 2) instead of == 0 and == 1.
*/

class MedianFinder {
 private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

 public:
  MedianFinder() {
    while (!maxHeap.empty()) maxHeap.pop();

    while (!minHeap.empty()) minHeap.pop();
  }
  // Adds a number into the data structure.
  void addNum(int num) {
    int numElements = maxHeap.size() + minHeap.size();

    if (numElements == 0) {
      maxHeap.push(num);
      return;
    }

    else if (numElements == 1) {
      if (num >= maxHeap.top()) {
        minHeap.push(num);
      } else {
        int val = maxHeap.top();
        maxHeap.pop();
        minHeap.push(val);
        maxHeap.push(num);
      }
      return;
    }

    if (num <= maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);

    if (minHeap.size() == maxHeap.size() + 1) {
      int val = minHeap.top();
      minHeap.pop();
      maxHeap.push(val);
    }

    if (maxHeap.size() > minHeap.size() + 1) {
      int val = maxHeap.top();
      maxHeap.pop();
      minHeap.push(val);
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    int numElements = maxHeap.size() + minHeap.size();
    if (numElements == 1) return maxHeap.top();
    if (numElements % 2 == 0)
      return (minHeap.top() + maxHeap.top()) / 2.0;
    else
      return maxHeap.top();
  }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();