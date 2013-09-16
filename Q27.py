from itertools import count, chain
from bitarray import bitarray

N = 1000000

# prime sieve
isprime = bitarray(N)
isprime.setall(True)
isprime[:2] = False
isprime[4::2] = False  # "cross off" multiples of 2
isprime[6::3] = False  # "cross off" multiples of 3
isprime[10::5] = False  # "cross off" multiples of 5
# deal with 6 integers at a time, starting with 7-13
n = 7
while n < N - 6:
    if isprime[n]:
        isprime[n*n::n] = False
    if isprime[n+4]:
        isprime[(n+4)*(n+4)::n+4] = False
    n += 6

# for n=0, we have b, so b must be prime
# for n=1, we have 1+a+b, which is at least 2, so a>=1-b
record = 39
record_params = 1, 31
for b in (p for p in xrange(1000) if isprime[p]):
    for a in xrange(1-b, 1000):
        for n in count(0):
            candidate = n * (a+n) + b
            if not isprime[candidate]: break
        if n-1 > record:
            record = n-1
            record_params = a,b
            #print a,b

print (record_params[0] * record_params[1])