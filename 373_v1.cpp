/*
  373_v1.cpp
  Find K Pairs with Smallest Sums

  I was trying to implement an O(K) algorithm initially but then failed. This
  algorithm is non-optimal but it at least can get accepted on LeetCode. :p
*/

class PairComparer {
 public:
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    return a.first + a.second > b.first + b.second;
  }
};

class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                        int k) {
    vector<pair<int, int>> ret;
    if (k == 0 || nums1.size() == 0 || nums2.size() == 0) return ret;
    k = min((int)nums1.size() * (int)nums2.size(), k);
    priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparer> pq;
    int p1 = 0;
    while (ret.size() < k) {
      if (p1 < nums1.size() &&
          (pq.empty() ||
           nums1[p1] + nums2[0] < pq.top().first + pq.top().second)) {
        for (int i = 0; i < nums2.size(); i++) pq.emplace(nums1[p1], nums2[i]);
        p1++;
      }
      ret.push_back(pq.top());
      pq.pop();
    }
    return ret;
  }
};