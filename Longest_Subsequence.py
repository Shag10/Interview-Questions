  #############################
  # Amazon Interview Question #
  #############################
  
ar = [1,1,0,1,1,0,1,1,1,1]
l = []
seqonetot = 0
for i in range(len(ar)):
    if ar[i] == 1:
        seqonetot += 1

    else:
        if seqonetot > 0:
            l.append(seqonetot)
            l.append(ar[i])
            seqonetot = 0

#print(l)
maxseq = 0
for i in range(len(l)):
    x = l[i]
    if (i + 1) < len(l):
        x += 1
    if (i + 2) < len(l):
        x += l[i+2]
    if x > maxseq:
        maxseq = x

print(maxseq)
