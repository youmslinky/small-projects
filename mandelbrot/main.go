package main

import (
	//"fmt"
	"github.com/fogleman/gg"
	"math/rand"
	"time"
	//"math/cmplx"
)

func main() {
	rand.Seed(time.Now().UTC().UnixNano())
	//size of canvas

	dc := gg.NewContext(100, 100)
	//dc.DrawCircle(50, 50, 40)
	dc.SetRGB(0, 0, 0)
	//fill in object?
	//dc.Fill()
	var scale = float64(2)
	halfHeight := dc.Height() / 2
	halfWidth := dc.Width() / 2
	maxIter := 300
	numColors := 100
	colors := randomColors(numColors)
	//for i := 0; i < 10; i++ {
	for w := 0; w < dc.Width(); w++ {
		for h := 0; h < dc.Height(); h++ {

			x := scale * float64((float64(w)-float64(halfWidth))/float64(halfWidth))
			y := scale * float64(-1.0*(float64(h)-float64(halfHeight))/float64(halfHeight))
			//fmt.Printf("xy:(%v,%v)\nhw:(%v,%v)\n\n", x, y, h, w)
			iter := nthIter(maxIter, complex(x, y))
			if iter == maxIter {
				dc.SetRGB(0, 0, 0)
				//dc.SetPixel(w, h)
			} else {
				dc.SetRGB(selectColor(iter, colors))
			}
			dc.SetPixel(w, h)
		}
	}
	//}
	//var a = complex(1, 1)

	dc.SavePNG("out.png")
}

func doesEscape(c complex128) bool {
	return real(c)*real(c)+imag(c)*imag(c) > 4
}

func manIter(c, origC complex128) complex128 {
	return c*c + origC
}

func nthIter(n int, c complex128) int {
	originalC := c
	i := 0
	for i < n {
		if doesEscape(c) {
			return i
		}
		c = manIter(c, originalC)
		i++
	}
	return i
}

func selectColor(n int, colors [][3]float64) (float64, float64, float64) {
	n = n % len(colors)
	return colors[n][0], colors[n][1], colors[n][2]
}

func randomColors(n int) [][3]float64 {
	a := [][3]float64{}
	for i := float64(0); int(i) < n; i++ {
		a = append(a, [3]float64{rand.Float64(), rand.Float64(), rand.Float64()})
	}
	return a
}
