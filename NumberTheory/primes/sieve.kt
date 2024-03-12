import kotlin.math.sqrt


var primes = IntArray(1000000){1}

fun sieve() {
    for(i in 2..1000000) {
        if(primes[i]==1) {
            var j = 2
            while(i*j<=1000000) {
                primes[i*j]=0
            }
        }
    }
}

fun primeFactors(N : Double) : DoubleArray {
    tailrec fun primeFactorsIter(N : Double, index : Int, factors : DoubleArray) : DoubleArray {
        if( N == 1.0)
            return factors
        else {
            val primeFactor = primes[index]
            if(primeFactor*primeFactor <= N) {
                if(N % primeFactor == 0.0) {
                    factors[index] = factors[index] + 1
                    return primeFactorsIter(N / primeFactor, index, factors)
                } else
                    return primeFactorsIter(N, index + 1, factors)
            } else {
                if(N != 1.0) {
                    factors[index] = factors[index] + 1
                    return primeFactorsIter(N, index, factors)
                } else {
                    return factors
                }
            }
        }
    }
    return primeFactorsIter(N, 0, DoubleArray(sqrt(N).toInt() + 1){0.0})
}

fun main() {
    sieve()
    val res = primeFactors(2147483647.0)
    println(res)
}