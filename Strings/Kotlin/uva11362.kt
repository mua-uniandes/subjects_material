import java.io.BufferedReader
import java.io.InputStreamReader


data class Node(val id : Int) {
    var end = false
    val links = arrayOfNulls<Node>(10) //Array<java.Node>(10){x -> java.Node(x)}
}


//val trie = java.Node(0)

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val t = In.readLine()!!.toInt()
    for(i in 1..t) {
        val n = In.readLine()!!.toInt()
        val trie = Node(0)
        var ans = true
        for(j in 1..n) {
            val s = In.readLine()!!
            ans = buildTrie(trie!!, s.trim())
            if(!ans) {
                println("NO")
                break
            }
        }
        if(ans)
            println("YES")
    }
}

tailrec fun buildTrie(trie : Node, s : String) : Boolean {
    if(s.isEmpty()) {
        trie.end = true
        val l = trie.links.filter { x -> x != null }
        return l.isEmpty()
    }else {
        if(trie.end) {
            return !trie.end
        } else {
            when(trie.links[s.first().toInt() -48]) {
                null -> {
                    val n = Node(s.first().toInt()-48)
                    trie.links[s.first().toInt()-48] = (n)
                    n
                }
                else -> trie.links[s.first().toInt()-48]
            }
            return buildTrie(trie.links[s.first().toInt()-48]!!, s.drop(1))
        }

    }
}