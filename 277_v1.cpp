/*
  277_v1.cpp
  Find the Celebrity

  I've got the first part correct in the first submission but I was always
  trying to minimize the second part in that I thought there might be a solution
  that doesn't need to "validate all other people against the final candidate".
  Turns out we must do the validation and this contributes to my first three
  WAs. My fourth submission got a CE.
*/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
 public:
  int findCelebrity(int n) {
    int id = 0;
    for (int i = 1; i < n; i++)
      if (knows(id, i)) id = i;
    for (int i = 0; i < n; i++)
      if (i != id && (!knows(i, id) || knows(id, i))) return -1;
    return id;
  }
};