from sys import stdin, stdout

nodes = []

def main():    
    stdin.readline()
    edges = int(stdin.readline())
    for i in range(0, edges):
        ends = stdin.readline().split()
        e1 = int(ends[0])
        e2 = int(ends[1])
        addEdge(e1, e2)

def addEdge(w,v):
    nodes[u].