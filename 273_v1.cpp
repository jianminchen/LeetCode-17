/*
  273_v1.cpp
  Integer to English Words

  My first submission got WA since I've mistakenly written "if (num <= 20)"
  instead of "if (num < 20)".
*/

class Solution {
  string words[20] = {"Zero",    "One",       "Two",      "Three",
                      "Four",    "Five",      "Six",      "Seven",
                      "Eight",   "Nine",      "Ten",      "Eleven",
                      "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  map<int, string> ties = {{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
                           {50, "Fifty"},  {60, "Sixty"},  {70, "Seventy"},
                           {80, "Eighty"}, {90, "Ninety"}};

 public:
  string numberToWords(int num) {
    if (num < 20)
      return words[num];
    else if (num >= 20 && num < 100) {
      int val1 = num / 10 * 10;
      int val2 = num - val1;
      if (val2 == 0)
        return ties[val1];
      else
        return ties[val1] + " " + numberToWords(val2);
    } else if (num >= 100 && num < 1000) {
      int numHundred = num / 100;
      int remaining = num - numHundred * 100;
      if (remaining != 0)
        return words[numHundred] + " Hundred " +
               numberToWords(num - numHundred * 100);
      else
        return words[numHundred] + " Hundred";
    } else if (num >= 1000 && num < 1000000) {
      int numThousand = num / 1000;
      int remaining = num - numThousand * 1000;
      if (remaining != 0)
        return numberToWords(numThousand) + " Thousand " +
               numberToWords(remaining);
      else
        return numberToWords(numThousand) + " Thousand";
    } else if (num >= 1000000 && num < 1000000000) {
      int numMillion = num / 1000000;
      int remaining = num - numMillion * 1000000;
      if (remaining != 0)
        return numberToWords(numMillion) + " Million " +
               numberToWords(remaining);
      else
        return numberToWords(numMillion) + " Million";
    } else {
      int numBillion = num / 1000000000;
      int remaining = num - numBillion * 1000000000;
      if (remaining != 0)
        return numberToWords(numBillion) + " Billion " +
               numberToWords(remaining);
      else
        return numberToWords(numBillion) + " Billion";
    }
  }
};