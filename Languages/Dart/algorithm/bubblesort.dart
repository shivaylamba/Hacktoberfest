import 'dart:core';

void main() {
  List<int> arr = [0, 5, 6, 77, 1, 3, 5, 6, 100];
  bubbleSort(arr);
  print("Sorted Array/List :" + arr.toString());
}

void bubbleSort(List<int> arr) {
  var len = arr.length;
  for (var i = 0; i < len - 1; i++) {
    for (var j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        var temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
