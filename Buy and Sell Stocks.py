  #############################
  # Amazon Interview Question #
  #############################

def getMaxProfit(self, prices):
		if len(prices) < 2:
			return 0
		left = [0]*len(prices)
		right = [0]*len(prices)
		minsofar = prices[0]
		for i in range(1,len(prices)):
			left[i] = max(left[i-1], prices[i] - minsofar)
			minsofar = min(minsofar, prices[i])
		
		maxsofar = prices[len(prices) - 1]
		for i in range(len(prices)-2,0,-1):
			right[i] = max(right[i+1], maxsofar - prices[i])
			maxsofar = max(maxsofar, prices[i])
			
		ans = right[0]
		for i in range(len(right)-1):
			ans = max(ans, left[i] + right[i])
		return ans
