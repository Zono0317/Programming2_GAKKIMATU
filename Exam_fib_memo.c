#include <stdio.h>

long long memo[100] = {};

long long fib_memo(int n) {
	if (n == 1 || n == 2) return memo[n] = 1LL;
	if (memo[n] != 0) return memo[n];
	return memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
}

int main() {
	int n;
	printf("第何項を表示しますか. >>> ");
	scanf("%d", &n);
	printf("%lld\n", fib_memo(n));
	return 0;
}