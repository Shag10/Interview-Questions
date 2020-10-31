  ##################################
  #  Microsoft Interview Questions #
  ##################################
    
import numpy as np

def DFS(friends, n, visited, v):
    for x in range(n):
        if friends[v,x] and visited[x] == 0:
            if x != v:
                visited[x] = 1
                DFS(friends, n, visited, x)

def friendCircles(friends, n):
    if n==0:
        return 0
  
    numCircles = 0
    visited = np.zeros((n))
    
    for i in range(n):
        if (visited[i] == 0):
            visited[i] = 1
            DFS(friends, n, visited, i) 
            numCircles = numCircles + 1
    
    return numCircles


n = 4
friends = np.array([
  [1,1,0,0,0],
  [1,1,1,0,0],
  [0,1,1,0,0],
  [0,0,0,1,1],
  [0,0,0,1,1] 
])

print("Number of friend circles:", friendCircles(friends, n))
