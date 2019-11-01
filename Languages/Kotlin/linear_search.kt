//Linear Search

fun linearSearch(list:List<Any>, key:Any):Int?{
	for ((index, value) in list.withIndex()) {
		if (value == key){
			return index
		}
	}
	return null
}


fun main(args: Array<String>) {
    val someList = listOf(8, 190, 5, 56, "Ram", "apple")
    val name = 56
    val position = linearSearch(someList, name)
    println("${name} is in the index ${position}.\n")
}
