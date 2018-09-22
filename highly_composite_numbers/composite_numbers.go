package main

import (
	"fmt"
	"math/big"
)

func main() {
	//i := 10000
	//fmt.Printf("%3v: %3v has %v factors\n", i, MostComposite(i), factors(MostComposite(i)))
	n := big.NewInt(360)
	fmt.Printf("%v has %v factors\n", n, factors(n))
}

func factors(number *big.Int) *big.Int {
	n := big.NewInt(0).Set(number)
	if n.Cmp(big.NewInt(0)) == 0 {
		return big.NewInt(0)
	}
	if n.Cmp(big.NewInt(1)) == 0 {
		return big.NewInt(1)
	}
	fac := big.NewInt(2)
	for i := big.NewInt(2); i.Cmp(n) == -1; i.Add(i, big.NewInt(1)) {
		if big.NewInt(0).Mod(n, i).Cmp(big.NewInt(0)) == 0 {
			fac.Add(fac, big.NewInt(1))
		}
	}
	return fac
}

//func MostComposite(max int) int {
//	most := 0
//	mostFactors := 0
//	for i := 0; i <= max; i++ {
//		if factors(i) > mostFactors {
//			most = i
//			mostFactors = factors(most)
//		}
//	}
//	return most
//}
