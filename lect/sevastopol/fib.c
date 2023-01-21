unsigned int fib(unsigned int n)
{
if(n<=2) return 1;
res = fib[n-1] + fib[n-2];
fib[n] = res;
return res;
}

5
5 10 15
2 10 15
5 5 5
20 20 1
20 1 1

1	2	3	4	5
inf	inf	inf	inf	inf
5	10	15	inf	inf
5	7	15	20	inf
5	7	12	12	12
if(waited_time[i] + buy[i][j] < waited_time[i+j])
O(n)
