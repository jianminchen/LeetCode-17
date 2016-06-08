/*
  138_v1.cpp
  Copy List with Random Pointer

  Wow, that's a lot of submissions! Right, initially I thought I only need to
  "split the new list" out but it seems one of the problem's requirement is that
  the original list should be kept. My first several submissions did not meet
  this requirement. Then even after I've noticed this, I forgot to set curr back
  to head before the third while loop and got another multiple rounds of WAs.
*/

/**
*Definition for singly-linked list with a random pointer.
*struct RandomListNode {
*    int label;
*    RandomListNode *next, *random;
*    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
*};
*/
class Solution {
 public:
  RandomListNode* copyRandomList(RandomListNode* head) {
    if (head == NULL) return NULL;
    RandomListNode* curr = head;
    while (curr != NULL) {
      RandomListNode* newNode = new RandomListNode(curr->label);
      RandomListNode* tmp = curr->next;
      curr->next = newNode;
      newNode->next = tmp;
      curr = tmp;
    }
    curr = head;
    while (curr != NULL) {
      if (curr->random) curr->next->random = curr->random->next;
      curr = curr->next->next;
    }

    /*
    curr = head;
    while (curr != NULL) {
        cout << curr -> label << endl;
        curr = curr -> next;
    }
    */

    RandomListNode* newHead = head->next;
    curr = head;
    while (curr != NULL) {
      RandomListNode* tmp = curr->next;
      if (curr->next) curr->next = curr->next->next;
      curr = tmp;
    }

    /*
    cout << "After" << endl;
    curr = head;
    while (curr != NULL) {
        cout << curr -> label << endl;
        curr = curr -> next;
    }
    */
    return newHead;
  }
};