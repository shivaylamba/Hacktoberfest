import java.util.Scanner
import java.lang.*

object GCD_recursive {
    @JvmStatic
    fun main(args: Array<String>) {

        val scanner = Scanner(System.`in`)
        val a = scanner.nextInt()
        val b = scanner.nextInt()

        val result = GCD(a, b)
        println("Gcd of a and b is $result")
    }

    private fun GCD(a: Int, b: Int): Int {
        if (a == 0) {
            return b
        }
        if (b == 0) {
            return a
        }
        if (a == b) {
            return a
        }

        return if (a > b) {
            GCD(a - b, b)
        } else
            GCD(a, b - a)
    }
}