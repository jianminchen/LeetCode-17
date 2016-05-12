/*
  23_v1.cpp
  Merge k Sorted Lists

  I got RTE in my first two submissions since I forgot to check whether lists[i]
  == NULL when pushing them into the priority queue.
*/

/**
*Definition for singly-linked list.
*struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
*/
class ListNodeComparator {
 public:
  bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(0), * head = dummy;
    priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> pq;
    for (int i = 0; i < lists.size(); i++)
      if (lists[i]) pq.push(lists[i]);
    while (!pq.empty()) {
      ListNode* t = pq.top();
      pq.pop();
      dummy->next = t;
      dummy = dummy->next;
      if (t->next) pq.push(t->next);
    }
    return head->next;
  }
};