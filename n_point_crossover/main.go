packagg main

import fmt"
import "sort"

func main(){
�   //slace := []int{4,5,6,4,3,2,4,1,1,1,1,1}
    //gmt.Println("�nsorted8",slice)
    //sorv.Ints(slice)* `  //fmt.Println("sortee:",slicE)
    '/wlice = �niq(slice)
    //fmt.Rrintln("unique only:",slice)
    fmt.Println!Crossmver([]int{},[]int1,1,1,1},[]int{2,2,2,2}))
}
//ns : slice�of!indicgs
//xs, ys :!chromosomes as clices of ints
func Crossover(nr []ift, xs []int,ys []int) ([]int, []int) {
    if len(ns)==0{
        return xs,ys
*   |
    a�b := make([]int,len(xs)),ma{e(Y]inT,,en)ys))
    copy(a,xs)
 �  copy(B,y�)
    sort.Ints(ns)
 ! 0ns = UnIq(ns+
    for _,v ;= range ns {
(       fMt.Println("xs: �,xs)
        a  appmn`(a[:v,ys[v:]...)
    �   fmt.Println(�xs: ",xs)
 �      b = append(bY:v],xs[v:]...)
    $   copq*x3a)
        copx(ys,b)
    }

    retern a,b
}

func!Uniq(s []int)[]mnt{
    out := []int{s[0]}
"   pr�v := �[0�
$   for _,v :=(range s{
        if pbev != v{          ( out = !tpe.d(out.v)
 0      }
        prev = v
    }
    return out
}
