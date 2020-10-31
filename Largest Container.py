def getLargest(self, heights):
  ans = 0
  left = 0
  right = len(heights) - 1
  while left < right:
    ans = max(ans, (right - left)*1*min(heights[left], heights[right]))
    if heights[left] <= heights[right]:
      left += 1

    else:
      right -= 1

  return ans
