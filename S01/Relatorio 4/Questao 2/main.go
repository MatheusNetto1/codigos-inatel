package main

import (
	"fmt"
	"math/rand"
)

func main() {
	var x int = rand.Intn(10)
	var fatorial int = 1

	for i := x; i > 0; i--{
		fatorial *= i
	}

	fmt.Printf("Fatorial de %d é %d\n", x, fatorial)
}
