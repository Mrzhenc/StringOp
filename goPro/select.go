package main
import "fmt"


func Chann(ch chan int){
	var i int
	i = 10
	ch <- i
}
func main(){
	
	ch := make(chan int)
	c := 0
	
	go Chann(ch)
	select{
	case c  = <- ch:
		fmt.Println("Recvice", c)
		fmt.Println("channel")
	case s := <-ch:
		fmt.Println("Receive", s)
	//default:
		//fmt.Println("Error")
	}
}
