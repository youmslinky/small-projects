package main

import (
	"crypto/sha256"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UTC().UnixNano())
	ch := make(chan []byte)
	inch := make(chan int)
	for i := 0; i < 100; i++ {
		go find0(2, ch, inch)
	}
	iterations := 0
	for i := 0; i < 100; i++ {
		hashInput := <-ch
		currentIterations := <-inch
		iterations += currentIterations
		fmt.Printf("%x %v\n", hashInput, currentIterations)
	}
	fmt.Println("total iterations:", iterations)
}

func find0(zeros int, ch chan []byte, intch chan int) {
	token := make([]byte, 5)
	rand.Read(token)
	iterations := 1
	for {
		h := sha256.New()
		h.Write(token)
		s := h.Sum(nil)

		exit := true
		for i := 0; i < zeros; i++ {
			if s[i] != 0 {
				exit = false
			}
		}
		if exit {
			//fmt.Printf("%x\n%x\n", token, s)
			ch <- token
			intch <- iterations
		}
		iterations++
		rand.Read(token)
	}
}
