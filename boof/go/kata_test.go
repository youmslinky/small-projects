package kata_test

import (
	"fmt"
	"github.com/onsi/gomega/types"

	. "codewarrior/kata"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

const (
	helloWorld = ";;;+;+;;+;+;\n+;+;+;+;;+;;+;\n;;+;;+;+;;+;\n;;+;;+;+;;+;\n+;;;;+;+;;+;\n;;+;;+;+;+;;\n;;;;;+;+;;\n+;;;+;+;;;+;\n+;;;;+;+;;+;\n;+;+;;+;;;+;\n;;+;;+;+;;+;\n;;+;+;;+;;+;\n+;+;;;;+;+;;\n;+;+;+;"
	multiply   = ">,>,>,>,>,>,>,>,>>,>,>,>,>,>,>,>,<<<<<<<<+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>>>>>>>>>>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]>[>]+<[+<]>>>>>>>>>[+]>[>]+<[+<]>>>>>>>>>[+]<<<<<<<<<<<<<<<<<<+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]>>>>>>>>>>>>>>>>>>>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]<<<<<<<<<<<<<<<<<<<<<<<<<<[>]+<[+<]>>>>>>>>>[+]>>>>>>>>>>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]<<<<<<<<<<<<<<<<<<+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]>>>>>>>>>>>>>>>>>>>;>;>;>;>;>;>;>;<<<<<<<<"
	catFF      = ">,>,>,>,>,>,>,>,<<<<<<<[>]+<[+<]>>>>>>>>>[+]+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]<<<<<<<<;>;>;>;>;>;>;>;<<<<<<<,>,>,>,>,>,>,>,<<<<<<<[>]+<[+<]>>>>>>>>>[+]+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]"
	cat00      = ">,>,>,>,>,>,>,>,>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>;>;>;>;>;>;>;>;>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+<<<<<<<<[>]+<[+<]>>>>>>>>>+<<<<<<<<+[>+]<[<]>>>>>>>>>[+]+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]>,>,>,>,>,>,>,>,>+<<<<<<<<+[>+]<[<]>>>>>>>>>]<[+<]"
)

var exampleTests = []testCase{
	{
		input{helloWorld, ""},
		"Hello, world!\n",
		"Your interpreter did not work with the code example provided on the official website",
	},
	{
		input{catFF, "Codewars\xff"},
		"Codewars",
		"should echo until byte(255) encountered",
	},
	{
		input{cat00, "Codewars\x00"},
		"Codewars",
		"should echo until byte(0) encountered",
	},
	{
		input{multiply, "\x08\x09"},
		"\x48",
		"should multiply two numbers. byte(8)*byte(9)=byte(72)",
	},
}

// -----------------------------------------------------------------------

var _ = Describe("Boolfuck Interpreter", func() {
	Describe("Examples", func() {
		for i, p := range exampleTests {
			in, out, msg := p.in, p.out, p.msg
			It(fmt.Sprintf("Test #%02d", i+1), func() {
				ans := Boolfuck(in.code, in.input)
				if ans != out {
					fmt.Printf("<LOG::Input>(%#v, %#v)\n", in.code, in.input)
					fmt.Printf("<LOG::Returned>%#v\n", ans)
					fmt.Printf("<LOG::Expected>%#v\n", out)
				}
				Expect(ans).To(match(out, msg))
			})
		}
	})
})

type input struct {
	code  string
	input string
}

type testCase struct {
	in  input
	out string
	msg string
}

func match(expected interface{}, msg string) types.GomegaMatcher {
	return &bfMatcher{
		expected: expected,
		message:  msg,
	}
}

type bfMatcher struct {
	expected interface{}
	message  string
}

func (m *bfMatcher) Match(actual interface{}) (success bool, err error) {
	return actual == m.expected, nil
}
func (m *bfMatcher) FailureMessage(actual interface{}) (message string) {
	return fmt.Sprintf("Expected\n\t%#v\nto equal\n\t%#v\n%s\n", actual, m.expected, m.message)
}
func (m *bfMatcher) NegatedFailureMessage(actual interface{}) (message string) {
	return fmt.Sprintf("Expected\n\t%#v\nnot to equal\n\t%#v\n", actual, m.expected)
}
