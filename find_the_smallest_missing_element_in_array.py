def find_the_smallest_missing_element(a: list, start: int=None, end: int=None) -> int:
  if start == None or end == None:
    start = 0
    end = len(a)
  
  mid = int((end + start) / 2)

  if end - start == 1:
    return mid if a[mid] != mid else mid + 1
  if a[mid] == mid:
    start = mid
  else:
    end = mid
  return find_the_smallest_missing_element(a, start, end)

A = list(map(int, input().split()))

print(find_the_smallest_missing_element(A))