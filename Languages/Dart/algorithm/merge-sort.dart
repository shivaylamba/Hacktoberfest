import 'dart:core';

void main() {
  List<int> arr1 = [0, 5, 6, 77, 1];
  List<int> arr2 = [8, 3, 5, 6, 100]; 
  List<int> mergedList = [...arr1,...arr2];
  mergedList = sort(mergedList);
  print("Sorted Array/List :" + mergedList.toString());
}

List<int> sort(List<int> arr) {
  var len = arr.length;
  for (var i = 0; i < len; i++) {
    for (var j = i+1; j < len; j++) {
      if (arr[i] > arr[j]) {
        var temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  return arr;
}