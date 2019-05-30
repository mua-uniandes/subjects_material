from sys import stdin, stdout 

def main():
    nodes = {}
    n = int(stdin.readline())
    edgeNum = int(stdin.readline())
    for i in range(0, edgeNum):
        edges = stdin.readline().split()
        nodes[int(edges[0]), int(edges[1])] = 1
    printGraph(nodes, n)

def printGraph(nodes, n):
    for i in range(0, n):
        for j in range(0, n):
            print("%d " %(nodes.get((i,j))))
        print("\n")

main()