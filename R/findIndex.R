findIndex <- function(list,select){
  for (i in list) {
    if(i == select) {
      index <- which(list == i)
      print(index)
    }
  }
}

# example
items <- c("tv","phone","car","house","plane","road")

findIndex(
  list = items,
  select = "house"
)

4
