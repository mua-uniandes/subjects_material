
pq = []
size = 0

def insert(key):
    pq[size+1] = key
    swim(size)

def deleteMax():
    max = pq[1]
    exchange(1, size-1)
    pq[size+1] = None
    return max

def swim(key):
    while key > 1 and less(key/2, key):
        exchange(key/2, key)  
        key /= 2

def sink(key):
    while 2*key <= size:
        j = 2*key
        if j < size and less(j, j+1):
            j += 1
        if not less(k, j):
            break
        exchange(k, j)
        k = j

def less(k1, k2):
    return pq[k1] < p1[k2]

def exchange(k1, k2):
    temp = pq[k1]
    pq[k1] = pq[k2]
    pq[k2] = temp

def isEmpty():
    return size == 0