import java.io.BufferedReader
import java.io.InputStreamReader


data class Node(val id : Int) {
    var end = false
    val links = arrayOfNulls<Node>(10)
}


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val n = In.readLine()!!.toInt()
    val trie = Node(0)
    for(j in 1..n) {
        val s = In.readLine()!!
        buildTrie(trie!!, s)
    }
}

tailrec fun buildTrie(trie : Node, s : String) {
    if(s.isEmpty()) {
        trie.end = true
    }else {
        when(trie.links[s.first().toInt() -65]) {
            null -> {
                val n = Node(s.first().toInt()-65)
                trie.links[s.first().toInt()-65] = (n)
                n
            }
            else -> trie.links[s.first().toInt()-65]
        }
    }
}