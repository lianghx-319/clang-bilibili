#include <stdio.h>

// https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
int main(int argc, char const *argv[])
{
	int n = 1;
	int count = 0;
	scanf("%d", &n);

	while (n > 0 && n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
		} else {
			n = (3 * n + 1) / 2;
		}
		count++;
	}

	printf("%d", count);

	return 0;
}
