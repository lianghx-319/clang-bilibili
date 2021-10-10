// 宏是替换字符的，所以如果是四则运算需要考虑计算优先级
#define ADD(X,Y) ((X)+(Y))
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("%d", 4 * ADD(2,3));
	return 0;
}
