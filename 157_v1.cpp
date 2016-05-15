/*
  157_v1.cpp
  Read N Characters Given Read4

  I didn't quite understand what the problem means for the first three
  submissions. "buf" is meant to be a destination buffer in both read4 and read.
  Thus we need to correctly handle the value for buf to make sure we won't
  overwrite the content we've just read to buf as well.
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int sum = 0;
    if (n == 0) return 0;
    while (true) {
      int numRead = read4(buf);
      sum += numRead;
      buf += numRead;
      if (sum >= n) return n;
      if (numRead < 4) return sum;
    }
  }
};