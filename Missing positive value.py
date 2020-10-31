def getFirst(nums):
		n = len(nums)
		tot = (n+1)*(n+2)/2
		numsum = sum(nums)
		x = tot - numsum
		if x == 0:
			return int(nums[n-1] + 1)
		else:
		    return int(x)
        
nums = [1,2,4,5]
print(getFirst(nums))
