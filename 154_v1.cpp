/*
  154_v1.cpp
  Find Minimum in Rotated Sorted Array II

  The basic idea is similar to 153_v1.cpp except that now we need to deal with a
  special case when nums[lo], nums[mid] and nums[hi] are all equal. When this
  happens there is no way to cut the search range by half so the algorithm
  degenerates to linear time.

  And actually, in my first submission, I didn't consider the case where
  nums[lo] == nums[mid] and nums[mid] < nums[hi]. Thus I've got my first WA. For
  cases like this we can directly return nums[lo] as the minimum value.

  However, if instead of checking whether nums[lo] == nums[mid], we check
  whether nums[mid] == nums[hi], then actually we can directly decrement hi by
  one without the special handling. The reason is that when doing binary search,
  lo can be equal to mid so for a simple case like [1, 3], lo = 0, mid = 0, hi =
  1, if we directly increment lo we will be missing the minimum value. But mid
  can never be equal to hi unless lo == hi, so decrementing hi is safe here.
*/

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1, mid;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;

      if (lo == hi) return nums[lo];

      if (nums[lo] < nums[mid] && nums[mid] <= nums[hi]) return nums[lo];

      if (nums[lo] > nums[mid])
        hi = mid;
      else if (nums[mid] > nums[hi])
        lo = mid + 1;
      else if (nums[lo] == nums[mid]) {
        if (nums[mid] < nums[hi])
          return nums[lo];
        else
          lo++;
      }
    }

    return -1;
  }
};