package main

import (
	"crypto/sha256"
	"fmt"
	"math/rand"
)

func main() {
	token := make([]byte, 5)
	rand.Read(token)
	for i := 0; i < 10; i++ {
		h := sha256.New()
		h.Write(token)
		s := h.Sum(nil)
		fmt.Printf("%x\n", s)
	}
}
