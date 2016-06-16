/*
  158_v1.cpp
  Read N Characters Given Read4 II - Call multiple times
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
 private:
  char buff[4];
  int buffPtr = 0, buffCnt = 0;

 public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int ptr = 0;
    while (ptr < n) {
      if (buffPtr == 0) buffCnt = read4(buff);
      if (buffCnt == 0) break;
      while (ptr < n && buffPtr < buffCnt) buf[ptr++] = buff[buffPtr++];
      if (buffPtr >= buffCnt) buffPtr = 0;
    }
    return ptr;
  }
};