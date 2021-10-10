#include <stdio.h>

void static_variable()
{
	// 将变量 a 存储在「静态区」; static 修饰局部变量
	static int a = 1;
	a++;
	printf("%d ", a);
}

int main(int argc, char const *argv[])
{
	int i = 0;
	while (i < 10)
	{
		static_variable();
		i++;
	}
	
	return 0;
}

// static 修饰全局变量或函数使得变量或函数只能在自己的原文件使用，无法跨文件使用
