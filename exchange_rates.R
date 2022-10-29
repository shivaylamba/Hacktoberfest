rm(list=ls())

getNBPRates <- function(year){
      
      d <- readLines(paste0("https://www.nbp.pl/kursy/Archiwum/archiwum_tab_a_",year,".csv"))
      d <- d[-2]
      d <- head(d, -4)
      tmpColnames <- strsplit(d[1],";",useBytes=T)[[1]]
      tmpColnames <- head(tmpColnames, -2)
      d <- do.call("rbind",
                   lapply(strsplit(d[-1],";"),
                          function(x){
                            matrix(as.numeric(gsub(",",".",head(x,-2))),nrow=1)
                          })
      )
      colnames(d) <- tmpColnames
      d <- as.data.frame(d)
      d <- d[ , grep( "USD|EUR|data", colnames(d))]
      
      d$data <- as.Date(as.character(d$data),format="%Y%m%d")
      colnames(d) <- c('date', 'usd', 'eur')
      
  return(d)
  
}

a <- getNBPRates(year = 2015)
head(as.data.frame(a))
View(a)

library(dplyr)

a <- do.call("bind_rows",
               lapply(2013:2020,getNBPRates))

library(ggplot2)
x11()
ggplot(data = a, aes(x = date))+
  geom_line(aes(y = usd), colour = "blue", size = 1) + 
  geom_line(aes(y = eur), colour = "red", size = 1) +
  ggtitle("Wykres kursow srednich NBP dla EUR i USD")+
  theme_light()+
  theme(
    plot.title = element_text(color="black", size=14, face="bold"))
