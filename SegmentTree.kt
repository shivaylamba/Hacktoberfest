import kotlin.math.ceil
import kotlin.math.ln
import kotlin.math.pow

class SegmentTree(array: IntArray, size: Int) {
    private val segmentTree: IntArray

    init {
        val height = ceil(ln(size.toDouble()) / ln(2.0)).toInt()
        val maxSize = (2 * 2.0.pow(height) - 1).toInt()
        segmentTree = IntArray(maxSize)
        constructSegmentTree(array, 0, size - 1, 0)
    }

    private fun constructSegmentTree(array: IntArray, start: Int, end: Int, index: Int): Int {
        if (start == end) {
            segmentTree[index] = array[start]
            return array[start]
        }
        val mid = getMidIndex(start, end)
        segmentTree[index] = constructSegmentTree(array, start, mid, index * 2 + 1) +
                constructSegmentTree(array, mid + 1, end, index * 2 + 2)
        return segmentTree[index]
    }

    private fun getMidIndex(start: Int, end: Int): Int = start + (end - start) / 2

    private fun getSumUtility(start: Int, end: Int, startRange: Int, endRange: Int, index: Int): Int {
        if (startRange <= start && endRange >= end) {
            return segmentTree[index]
        }
        if (end < startRange || start > endRange) {
            return 0
        }
        val mid = getMidIndex(start, end)
        return getSumUtility(start, mid, startRange, endRange, index * 2 + 1) +
                getSumUtility(mid + 1, end, startRange, endRange, index * 2 + 2)
    }

    private fun updateValueUtility(start: Int, end: Int, indexToUpdate: Int, difference: Int, index: Int) {
        if (indexToUpdate < start || indexToUpdate > end) {
            return
        }
        segmentTree[index] = segmentTree[index] + difference
        if (start != end) {
            val mid = getMidIndex(start, end)
            updateValueUtility(start, mid, indexToUpdate, difference, index * 2 + 1)
            updateValueUtility(mid + 1, end, indexToUpdate, difference, index * 2 + 2)
        }
    }

    fun getSumInRange(size: Int, startRange: Int, endRange: Int): Int {
        if (startRange < 0 || endRange > size - 1 || startRange > endRange) {
            throw IllegalArgumentException("Invalid Input")
        }
        return getSumUtility(0, size - 1, startRange, endRange, 0)
    }

    fun updateValue(array: IntArray, size: Int, index: Int, newValue: Int) {
        if (index < 0 || index > size - 1) {
            throw IllegalArgumentException("Invalid Input")
        }
        val difference = newValue - array[index]
        array[index] = newValue
        updateValueUtility(0, size - 1, index, difference, 0)
    }

    fun printSegmentTree() {
        println(segmentTree.joinToString(" "))
    }

}

fun main() {
    val array = intArrayOf(2, 3, -1, 5, -2, 4, 8, 10)
    val size = array.size
    val segmentTree = SegmentTree(array = array, size = size)
    println("Segment Tree: ")
    segmentTree.printSegmentTree()
    println("Range Query 0 to 2: ${segmentTree.getSumInRange(size, 0, 2)}") //prints 4, expected 4
    println("Range Query 3 to 6: ${segmentTree.getSumInRange(size, 3, 6)}") //prints 15, expected 15
    segmentTree.updateValue(array,size, 2, 10) //updates index 2 with 10
    println("Segment Tree: ")
    segmentTree.printSegmentTree()
    println("Range Query 0 to 2: ${segmentTree.getSumInRange(size, 0, 2)}") //print 15, expected 15
}
