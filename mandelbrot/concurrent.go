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

	dc := gg.NewContext(10000, 10000)
	//dc.DrawCircle(50, 50, 40)
	dc.SetRGB(0, 0, 0)
	//fill in object?
	//dc.Fill()
	var scale = float64(1.5)
	halfHeight := dc.Height() / 2
	halfWidth := dc.Width() / 2
	maxIter := 100
	numColors := 100
	set := settings{halfHeight, halfWidth, maxIter, scale}
	colors := randomColors(numColors)
	inCh := make(chan pixel)
	outCh := make(chan pixel)
	//for i := 0; i < 10; i++ {
	for i := 0; i < 100; i++ {
		go pixelWorker(inCh, outCh, &set)
	}

	go pixelWriter(outCh, dc, maxIter, colors)

	for w := 0; w < dc.Width(); w++ {
		for h := 0; h < dc.Height(); h++ {
			inCh <- pixel{h, w, 0}
		}
	}
	////}
	//var a = complex(1, 1)

	dc.SavePNG("out.png")
}

type settings struct {
	halfHeight, halfWidth, maxIter int
	scale                          float64
}

type pixel struct {
	h    int
	w    int
	iter int
}

func pixelWriter(inCh chan pixel, dc *gg.Context, maxIter int, colors [][3]float64) {
	for pix := range inCh {
		if pix.iter == maxIter {
			dc.SetRGB(0, 0, 0)
		} else {
			dc.SetRGB(selectColor(pix.iter, colors))
		}
		dc.SetPixel(pix.w, pix.h)
	}
}

func pixelWorker(inCh, outCh chan pixel, s *settings) {
	for pix := range inCh {
		x := s.scale * float64((float64(pix.w)-float64(s.halfWidth))/float64(s.halfWidth))
		y := s.scale * float64(-1.0*(float64(pix.h)-float64(s.halfHeight))/float64(s.halfHeight))
		iter := nthIter(s.maxIter, complex(x, y))
		outCh <- pixel{pix.h, pix.w, iter}
	}
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
