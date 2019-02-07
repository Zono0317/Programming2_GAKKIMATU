#include <stdio.h>

long long fib(int n){
	if(n == 1 || n == 2) return 1LL;
	return fib(n - 1) + fib(n - 2);
}

int main(){
	int n;
	printf("第何項を表示しますか. >>> ");
	scanf("%d", &n);
	printf("%lld\n", fib(n));
	return 0;
}