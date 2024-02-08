from sys import stdin, stdout

def main():    
    vertex, edges = stdin.readline().split()
    nodes = [[] for _ in range(int(vertex))]
    for _ in range(int(edges)):
        ends = stdin.readline().split()
        e1 = int(ends[0])
        e2 = int(ends[1])
        nodes[e1].append(e2)
        nodes[e2].append(e1)

main()