import java.util.Scanner

fun main(args: Array<String>) {

    var n: Int
    var p = 1
    var i = 2
    var sc = Scanner(System.`in`)

    print("Enter a Number :")
    n = sc.nextInt()

    while (i < n) {
        if (n % i == 0) {
            p = 0
            break
        }
        i++
    }
    
    if (p == 1) {
        println("Number is prime :$n")
    } else {
        println("The number is not prime :$n")
    }
}
