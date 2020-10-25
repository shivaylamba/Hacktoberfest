package main.dataStructures.sorting

fun main(args: Array<String>) {
    val list = ArrayList(readLine()!!.split(" ").map { it.toInt() })
    selection(list)
    for(i in list) println(i)
}

fun selection(a: ArrayList<Int>) {
    var min:Int
    for (i in 0 until a.size) {
        min = i
        for (j in (i + 1) until a.size) {
            if (a[j] < a[min]) {
                min = j
            }
        }
        swap(a, min, i)
    }
}
fun swap(a : ArrayList<Int>, b: Int, c:Int) {
    val temp = a[b]
    a[b] = a[c]
    a[c] = temp
}