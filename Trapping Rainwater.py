def getMaxWater(self, heights):
		left = [0]*len(heights)
		right = [0]*len(heights)
		curmax = 0
		for i in range(len(heights)):
			curmax = max(curmax, heights[i])
			left[i] = curmax
			
		curmax = 0
		for i in range(len(heights)-1, -1, -1):
			curmax = max(curmax, heights[i])
			right[i] = curmax
			
		tot = 0
		for i in range(len(heights)):
			store = min(left[i], right[i]) - heights[i]
			tot += store
			
		return tot
