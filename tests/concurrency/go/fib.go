package main

import (
  "fmt"
  "time"
  "os"
  "strconv"
)

func main() {

  go spinner( 50 * time.Millisecond)
  arg := os.Args[1]
  argN,_ := strconv.Atoi(arg)
  fibN := fib(argN) // slow
  fmt.Printf("\rFibonacci(%d) = %d\n", argN, fibN)
}

func spinner(delay time.Duration) {
  for {
    for _, r := range `-\|/` {
      fmt.Printf("\r%c", r)
      time.Sleep(delay)
    }
  }
}

func fib(x int) int {
  if x < 2 { return x }
  return fib(x - 1) + fib(x - 2)
}
