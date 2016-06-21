/*
  160_v3.cpp
  Intersection of Two Linked Lists

  My first submission got WA since I didn't consider the case where headA or
  headB can be NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 private:
  ListNode* getLastValidNode(ListNode* head, int& numNodes) {
    numNodes = 1;
    while (head->next != NULL) {
      head = head->next;
      numNodes++;
    }
    return head;
  }

 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == NULL || headB == NULL) return NULL;

    int lenA = 0, lenB = 0;
    ListNode* lastA = getLastValidNode(headA, lenA);
    ListNode* lastB = getLastValidNode(headB, lenB);
    if (lastA != lastB) return NULL;

    ListNode *currA = headA, *currB = headB;
    if (lenA < lenB) {
      for (int i = 0; i < lenB - lenA; i++) currB = currB->next;
    } else {
      for (int i = 0; i < lenA - lenB; i++) currA = currA->next;
    }
    while (currA != currB) {
      currA = currA->next;
      currB = currB->next;
    }
    return currA;
  }
};