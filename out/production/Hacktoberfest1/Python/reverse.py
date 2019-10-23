def reverse(self, x: int) -> int:
        result = ""
        if x<0:
          for i in str(x)[1:]:
            result = i + result
          result = -1 * int(result)
        else:
          for i in str(x):
            result = i + result
          result = int(result)
        if(result.bit_length() < 32):
            return(result)
        else:
            return 0
