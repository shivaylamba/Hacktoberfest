package main

import (
	"fmt"
	"net/http"
	"time"
)


func main(){
	start := time.Now()

	apis := []string{
        "https://management.azure.com",
        "https://dev.azure.com",
        "https://api.github.com",
        "https://outlook.office.com/",
        "https://api.somewhereintheinternet.com/",
        "https://graph.microsoft.com",
    }

	ch := make(chan string)// using channels to send or receive data

	// for _, api := range apis{
	// 		go checkAPI(api) // we can achieve concurrency by calling the function with prefix go
 	// }
	 for _, api := range apis{
		go checkAPI(api,ch) // we can achieve concurrency by calling the function with prefix go
 	}
	 for i := 0; i < len(apis); i++ {
        fmt.Print(<-ch)
    }
	elapsed := time.Since(start)
    fmt.Printf("Done! It took %v seconds!\n", elapsed.Seconds())


	chh := make(chan string, 1)
    send(chh, "Hello World!")
    read(chh)

	ch1 := make(chan string)
    ch2 := make(chan string)
    go process(ch1)
    go replicate(ch2)

    for i := 0; i < 2; i++ {
        select {
        case process := <-ch1:
            fmt.Println(process)
        case replicate := <-ch2:
            fmt.Println(replicate)
        }
    }
}
// func checkAPI(api string) {
//     _, err := http.Get(api)
//     if err != nil {
//         fmt.Printf("ERROR: %s is down!\n", api)
//         return
//     }

//     fmt.Printf("SUCCESS: %s is up and running!\n", api)
// }


//function using channels for concurrency
func checkAPI(api string, ch chan string){
	_, err := http.Get(api)
    if err != nil {
        ch <- fmt.Sprint("ERROR: %s is down!\n", api)
        return
    }

    	ch <- fmt.Sprint("SUCCESS: %s is up and running!\n", api)
}

func send(ch chan<- string, message string) {
    fmt.Printf("Sending: %#v\n", message)
    ch <- message
}

func read(ch <-chan string) {
    fmt.Printf("Receiving: %#v\n", <-ch)
}

func process(ch chan string) {
    time.Sleep(3 * time.Second)
    ch <- "Done processing!"
}

func replicate(ch chan string) {
    time.Sleep(1 * time.Second)
    ch <- "Done replicating!"
}