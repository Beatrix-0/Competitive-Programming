# 1. Legendre's Formula
Task : Find largest power of a prime p, who devide n! <br>

Legendre's formula is used to determine the highest power of a prime $p$ that divides $n!$ (n factorial). It is given by:

$$ 
v_p(n!) = \sum_{k=1}^{\infty} \left\lfloor \frac{n}{p^k} \right\rfloor 
$$

where:
- $v_p(n!)$ is the exponent of the prime $p$ in the prime factorization of $n!$.
- $\lfloor x \rfloor$ denotes the floor function, which gives the greatest integer less than or equal to $x$.

## Explanation
- The term $\left\lfloor \frac{n}{p} \right\rfloor$ counts the multiples of $p$ up to $n$.
- The term $\left\lfloor \frac{n}{p^2} \right\rfloor$ accounts for numbers that contribute an extra factor of $p$ (e.g., multiples of $p^2$).
- Similarly, $\left\lfloor \frac{n}{p^3} \right\rfloor$, $\left\lfloor \frac{n}{p^4} \right\rfloor$, etc., continue to count higher powers of $p$ until $p^k > n$, at which point the terms become zero.

## Example
Find the highest power of $5$ in $100!$:

$$
v_5(100!) = \left\lfloor \frac{100}{5} \right\rfloor + \left\lfloor \frac{100}{25} \right\rfloor + \left\lfloor \frac{100}{125} \right\rfloor
$$

$$
= \left\lfloor 20 \right\rfloor + \left\lfloor 4 \right\rfloor + \left\lfloor 0.8 \right\rfloor
$$

$$
= 20 + 4 + 0 = 24
$$

So, the exponent of $5$ in $100!$ is **24**. </br>
```
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}  
```
