/*
  355_v1.cpp
  Design Twitter

  My first submission got RTE since I didn't check whether a followee has
  published any tweet when constructing the initial values for the
  priority queue. My second submission got WA since I thought Tweeet IDs are
  ever-increasing so I didn't add an additional timestamp field.
*/

class Twitter {
 private:
  unordered_map<int, vector<pair<int, int>>> tweetList;
  unordered_map<int, unordered_set<int>> followees;
  int timestamp;

 public:
  /** Initialize your data structure here. */
  Twitter() {
    timestamp = 0;
    tweetList.clear();
    followees.clear();
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweetList[userId].emplace_back(timestamp, tweetId);
    timestamp++;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<vector<pair<int, int>>> tweets;
    tweets.push_back(tweetList[userId]);
    if (followees.find(userId) != followees.end()) {
      for (auto it : followees[userId]) {
        int followeeId = it;
        if (tweetList.count(followeeId)) {
          tweets.push_back(tweetList[followeeId]);
        }
      }
    }
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    for (int i = 0; i < tweets.size(); i++) {
      if (tweets[i].size() > 0)
        pq.emplace(tweets[i].back(), make_pair(i, tweets[i].size() - 1));
    }

    int cnt = 0;
    vector<int> ret;
    while (ret.size() < 10 && (!pq.empty())) {
      auto p = pq.top();
      pq.pop();

      int timestamp = p.first.first;
      int tweetId = p.first.second;
      int userId = p.second.first;
      int ptr = p.second.second;
      ret.push_back(tweetId);
      if (ptr != 0)
        pq.emplace(tweets[userId][ptr - 1], make_pair(userId, ptr - 1));
    }
    return ret;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followeeId == followerId) return;
    followees[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followees[followerId].find(followeeId) == followees[followerId].end())
      return;
    followees[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */