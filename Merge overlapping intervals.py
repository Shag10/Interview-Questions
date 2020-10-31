def merge(self, intervals):
  n = len(intervals)
  intervals.sort()
  i = 0
  ans = []
  while i < n:
    start = intervals[i][0]
    end = intervals[i][1]
    j = i + 1
    while j < n and intervals[j][0] <= end:
      end = max(intervals[j][1], end)
      j += 1

    ans.append([start, end])
    i = j
  return ans
