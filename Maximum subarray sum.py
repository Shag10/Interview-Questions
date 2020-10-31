def getMaximumSum(self, nums):
  maxsofar = 0
  maxendhere = 0
  for i in range(len(nums)):
    if nums[i] > maxendhere + nums[i]:
      maxendhere = nums[i]
    else:
      maxendhere += nums[i]
    if maxendhere > maxsofar:
      maxsofar = maxendhere

  return maxsofar
