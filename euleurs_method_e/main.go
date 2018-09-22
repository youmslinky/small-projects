package main

import (
    "fmt"
    "math"
)

func main(){
    x := 0.0
    y := 1.0
    dx := .000001
    dxdy := 1.0

    input := 4.0

    for x < input {
        if x+dx > input {
            dx = input-x+dx
        }
        x += dx
        y += dxdy*dx
        dxdy = y
    }
    fmt.Printf("x:%v y:%v dxdy:%v\n",x,y,dxdy)
    fmt.Println(y)
    actual_y := math.Exp(input)
    fmt.Println(actual_y)
    fmt.Println("error: ",y-actual_y)
}
