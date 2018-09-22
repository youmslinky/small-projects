package main

import (
	"fmt"
	"math/big"
)

func main() {
	//for i := big.NewInt(0); i.Cmp(big.NewInt(20)) != 0; i.Add(i, big.NewInt(1)) {
	i := big.NewInt(120)
	fmt.Printf("%v: %v\n", i, fac(i))
	//}
	//a := big.NewInt(555)
	//b := big.NewInt(666)
	//for i := 0; i < 100; i++ {
	//	f := a.Mul(a, b)
	//	fmt.Printf("a: %v\n", f)
	//}
}

func fac(number *big.Int) *big.Int {
	n := big.NewInt(0).Set(number)
	if n.Cmp(big.NewInt(0)) == 0 || n.Cmp(big.NewInt(1)) == 0 {
		return big.NewInt(1)
	}
	return big.NewInt(0).Mul(n, fac(big.NewInt(0).Add(n, big.NewInt(-1))))
}
