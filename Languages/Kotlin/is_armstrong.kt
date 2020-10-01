fun main(args: Array<String>) {
    val num = 371
    var originalNum: Int
    var rem: Int
    var result = 0
    originalNum = number
    while (originalNum != 0) {
        rem = originalNum % 10
        result += Math.pow(rem.toDouble(), 3.0).toInt()
        originalNum /= 10
    }
    if (result == num)
        println("$num - Armstrong number.")
    else
        println("$num - not an Armstrong number.")
}
