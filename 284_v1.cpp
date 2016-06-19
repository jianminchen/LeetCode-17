/*
  284_v1.cpp
  Peeking Iterator

  My first submission got RTE since I didn't consider the case where one may
  peek multiple consecutive times. In this case I should directly return the
  previous peekedElement.
*/

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 private:
  bool hasPeeked;
  int peekedElement;

 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    hasPeeked = false;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!hasPeeked) {
      peekedElement = Iterator::next();
      hasPeeked = true;
    }
    return peekedElement;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (hasPeeked) {
      hasPeeked = false;
      return peekedElement;
    }
    return Iterator::next();
  }

  bool hasNext() const {
    if (hasPeeked) {
      return true;
    }
    return Iterator::hasNext();
  }
};