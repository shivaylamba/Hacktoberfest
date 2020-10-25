import kotlin.coroutines.experimental.*

fun main(args: Array<String>) {
    val fib = sequence {
        var a = 0
        var b = 1
        yield(0) 
        while (true) {
            yield(b)
            val temp = a + b
            a = b
            b = temp
        }
    }
    println(fib.take(10).joinToString(" "))
}
