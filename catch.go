package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	signals := make(chan os.Signal, 1)
	done := make(chan bool)
	signal.Notify(signals, syscall.SIGTERM)
	go func() {
		sig := <-signals
		fmt.Println(sig)
		fmt.Println("signal catch")
		done <- true
	}()
	fmt.Println("waiting")
	<-done
	fmt.Println("Exit")
}
