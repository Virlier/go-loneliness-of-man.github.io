#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
/*
原题：
颠倒给定的 32 位无符号整数的二进制位。

示例:

输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
进阶:
如果多次调用这个函数，你将如何优化你的算法？
*/

uint32_t reverseBits(uint32_t n)
{
	uint32_t num, i;
	for (num = i = 0; 1; num <<= 1, n >>= 1, i++)
	{
		if (n & 1)	num += 1;
		if (i == 31)	break;
	}
	return num;
}

int main()
{
	printf("%u", reverseBits(2147483649));
	return 0;
}
/*
思路：
每次令 n&1，若其最右侧也是 1，则值为 1，反之为 0，可用 if(n & 1)	num += 1; 实现两数最右侧的同步，赋值后 n 右移一位，而 num 左移
一位，如此循环该过程（数字的位数的 -1 次）即可完成逆置。
*/