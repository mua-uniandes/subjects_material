/**
 * implementation of a sum segment tree
 */

var array =  intArrayOf(0, 1,3,-2,8,-7)
var tree = IntArray(4*array.size)
fun build(array: IntArray, current: Int, left: Int, right: Int) {
    if (left == right) {
        tree[current] = array[left]
    } else {
        val mid = (left + right) / 2
        build(array, 2*current, left, mid)
        build(array, 2*current+1, mid+1, right)
        tree[current] = tree[2*current] + tree[2*current+1]
    }
}

fun update(v: Int, tl: Int, tr: Int, pos: Int, newVal: Int) {
    if (tl == tr) {
        array[2] = newVal
        tree[v] = newVal
    } else {
        val tm = (tl + tr) / 2
        if (pos <= tm)
            update(v * 2, tl, tm, pos, newVal)
        else
            update(v * 2 + 1, tm + 1, tr, pos, newVal)
        tree[v] = tree[2*v] + tree[2*v + 1]
    }
}
fun main() {
    build(array, 1, 1, array.size-1)
    println(tree.contentToString())
    update(1, 1, array.size-1,3,3)
    println(tree.contentToString())
}