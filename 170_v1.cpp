/*
  170_v1.cpp
  Two Sum III - Data structure design
*/

class TwoSum {
  unordered_map<int, int> m;

 public:
  // Add the number to an internal data structure.
  void add(int number) { m[number]++; }

  // Find if there exists any pair of numbers which sum is equal to the value.
  bool find(int value) {
    for (auto it : m) {
      int key = it.first;
      if (value - key != key && m.find(value - key) != m.end()) return true;
      if (value - key == key && it.second >= 2) return true;
    }
    return false;
  }
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);