/*
  328_v1.cpp
  Odd Even Linked List
*/

/**
*Definition for singly-linked list.
*struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
*};
*/
class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prevOdd = NULL, *prevEven = NULL, *currOdd = head;
    if (currOdd == NULL || currOdd->next == NULL) return head;
    ListNode *currEven = currOdd->next, *startEven = currEven;
    while (currOdd || currEven) {
      ListNode *nextEven = NULL;
      if (currOdd && currOdd->next && currOdd->next->next) {
        prevOdd = currOdd;
        currOdd = currOdd->next->next;
        nextEven = currOdd->next;
        prevOdd->next = currOdd;
      } else {
        if (currOdd == NULL)
          prevOdd->next = startEven;
        else
          currOdd->next = startEven;
        currOdd = NULL;
      }

      if (prevEven) prevEven->next = currEven;
      prevEven = currEven;
      currEven = nextEven;
    }
    return dummy->next;
  }
};