#include <stdio.h>

int main(){

	int c, p, ans;

	scanf("%d", &c);
	scanf("%d", &p);

  ans = p + (p-2)*(c-1);

	printf ("%d\n", ans);

	return 0;
}
