import java.io.BufferedReader
import java.io.InputStreamReader


fun main(args : Array<String>) {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val n = In.readLine()!!.toInt()
    val num_edges = In.readLine()!!.toInt()
    tailrec fun addEdge(nodes : Array<List<Int>>, num_edges : Int) : Array<List<Int>> {
        if (num_edges == 0)
            return nodes
        else {
            val edges = In.readLine().split(" ").map{x -> x.toInt()}
            nodes[edges[0]] = nodes[edges[0]] + edges[1]
            nodes[edges[1]] = nodes[edges[1]] + edges[0]
            return addEdge(nodes,num_edges - 1)
        }
    }
    val graph = addEdge(Array(n){ x -> emptyList<Int>()},  num_edges)
    printGraph(graph)
}

fun printGraph(graph : Array<List<Int>>) {
    for(i in 0..graph.lastIndex) {
        println(" Adjacency list for node $i")
        for(x in graph[i])
            println("\t ($i, $x)")
    }
}

