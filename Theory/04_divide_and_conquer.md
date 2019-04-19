# Divide and Conquer

 - **Divide**: Recursively solve smaller problems
 - **Conquer**: Original problem's solution is composed of smaller problems' solutions
 - There is division when an **algorithm has at leat 2 recursive calls in its body**
 - sub-problems must be disjointed
    - if not, solve in a **bottom-up** fashion with **dynamic Programming**
 - Division in **sub-problems of similar dimension** is crucial for obtaining **good time efficiency**
 - Adequate for **parallel processing**

```
function DAQ(x)
    if x is small enough then
        solve x directly
    else
        divide x sub-problems: x1, …, xk
        
    for i := 1 to k do yi := DAQ( xi )
        y := Σ yi
    return y
```

## Example: Calculating x^n

```C++
double power(double x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    double p = power(x, n / 2);
    if (n % 2 == 0)
        return p * p;
    else
        return x * p * p;
} 
```