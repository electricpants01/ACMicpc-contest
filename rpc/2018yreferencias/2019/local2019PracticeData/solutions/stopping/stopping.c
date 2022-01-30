#include "stdio.h"


int gcd (int a, int b);
int lcm (int a, int b);


int main(){

	int m, g, f, ans;

	scanf("%d", &m);
	scanf("%d", &g);
	scanf("%d", &f);

	// Ignore when a stop is made at the destination
	m--;

	// Use the inclusion-exclusion principle
	ans = m/g + m/f - m/lcm(f, g);

	printf ("%d\n", ans);

	return 0;
}

int gcd (int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int lcm (int a, int b){
	return b / gcd(a,b) * a;
}
