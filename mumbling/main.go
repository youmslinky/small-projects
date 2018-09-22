package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {

	fmt.Println(Accum(os.Args[1]))
}

func Accum(s string) string {
	out := ""
	for i := 0; i < len(s); i++ {
		out += strings.ToUpper(string(s[i]))
		for j := 0; j < i; j++ {
			out += strings.ToLower(string(s[i]))
		}
		out += "-"
	}
	return strings.Trim(out, "-")
}
