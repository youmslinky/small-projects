package main

import (
	"fmt"
	//"strings"
)

func main() {

	fmt.Println(Boolfuck(",;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;", "Codewars\x00"))

}

func Boolfuck(code, input string) string {
	t := NewTape()
	out := NewTape()
	in := NewTape()
	in.data = []byte(input)
	fmt.Println(in.data)
	in.position = 0
	programPointer := 0
	for programPointer < len(code) {
		fmt.Printf("code:%c t.position:%3v programPointer:%3v\n", code[programPointer], t.position, programPointer)
		switch code[programPointer] {
		case '<':
			t.left()
			programPointer++

		case '>':
			t.right()
			programPointer++

		case '+':
			t.flip()
			programPointer++

		case ',':
			t.data[t.position] = in.readBit()
			programPointer++

		case ';':
			out.push(int(t.read()))
			programPointer++

		case '[':
			if t.read() == '0' {
				programPointer = findRightBracket(code[programPointer+1:]) + 2 + programPointer
			} else {
				programPointer++
			}

		case ']':
			if t.read() == '1' {
				programPointer = findLeftBracket(code[:programPointer]) + 1
			} else {
				programPointer++
			}

		default:
			programPointer++
		}
	}

	return string(out.data[:len(out.data)])
}

func findRightBracket(code string) int {
	openBrackets := 0
	for i, c := range code {
		switch c {
		case '[':
			openBrackets++
		case ']':
			if openBrackets == 0 {
				return i
			} else {
				openBrackets--
			}
		}
	}
	panic("closing brace not found")
}

func findLeftBracket(code string) int {
	openBrackets := 0
	for i := len(code) - 1; i >= 0; i-- {
		c := code[i]
		switch c {
		case ']':
			openBrackets++
		case '[':
			if openBrackets == 0 {
				return i
			} else {
				openBrackets--
			}
		}
	}
	panic("closing brace not found")
}

type tape struct {
	position int
	data     []byte
}

//func NewSomething(text string) Something {
func NewTape() tape {
	t := tape{}
	t.data = append(t.data, 0)
	return t
}

func (t *tape) read() byte {
	return t.data[t.position]
}

func (t *tape) flip() {
	if t.data[t.position] == 0 {
		t.data[t.position] = 1
	} else {
		t.data[t.position] = 0
	}
}

func (t *tape) left() {
	t.position--
	if t.position < 0 {
		n := []byte{0}
		t.data = append(n, t.data...)
		t.position = 0
	}
}

func (t *tape) right() {
	t.position++
	if t.position >= len(t.data) {
		t.data = append(t.data, 0)
	}
}

func (t *tape) push(in int) {
	t.data[t.position/8] = t.data[t.position/8] | ((byte(in) & 1) << uint(t.position%8))
	t.position++
	if t.position/8 >= len(t.data) {
		t.data = append(t.data, 0)
	}
}

func (t *tape) readBit() byte {
	if t.position < 0 {
		return 0
	}
	out := (t.data[t.position/8] >> uint(7-t.position%8)) & 1
	t.position--
	return out
}
