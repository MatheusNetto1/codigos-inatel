package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c float64
	
	fmt.Print("Digite o valor de a: ")
	fmt.Scan(&a)
	fmt.Print("Digite o valor de b: ")
	fmt.Scan(&b)
	fmt.Print("Digite o valor de c: ")
	fmt.Scan(&c)

	var delta float64 = b * b - 4 * a * c
	var raiz_delta float64 = math.Pow(float64(delta), 0.5)

	if delta < 0 || a == 0 {
		fmt.Println("A equação não possui raízes reais.")
	} else {
		var x1 = (-b + raiz_delta) / (2 * a)
		var x2 = (-b - raiz_delta) / (2 * a)

		fmt.Println("As raízes da equação são:")
		fmt.Println("x1 = ", x1)
		fmt.Println("x2 = ", x2)
	}
}