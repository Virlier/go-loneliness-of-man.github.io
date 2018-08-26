#include<stdio.h>
//删除一字符串中所有空格（不另外创建字符串）

char *del(char *s);

int main()
{
	char a[101];
	printf("\n  请输入字符串： ");
	gets_s(a, 101);
	printf("\n\n  删去空格后： %s\n\n  ", del(a));
	return 0;
}

char *del(char *s)										//删去一个字符串中的所有空格
{									
	char *a = NULL, *ss = s;							//标记指针、存储字符串首地址的指针 ss，便于观察字符串状态
	for (; *s != ' '; s++);								//确定标记指针初始位置，标记指针永远标记接下来第一个空格的位置
	for (a = s; *s != '\0'; s++)						//遍历字符串
		if (*s == ' ')									//当遇到空格
		{
			for (; *s == ' ' && *s != '\0'; s++);		//找出接下来第一个不是空格的字符
			for (; *s != ' ' && *s != '\0'; s++, a++)	//将找到的字符赋值给标记位置
				*a = *s;
			s--;										//自减一次，抵消下一个自增
			printf("\n\n  进行一系列赋值后： %s", ss);
		}
	*a = '\0';											//加上空格，截断字符串
	return ss;
}
/*
	思路：
	创建一个指针 a，该指针永远指向接下来第一个空格的位置，然后形参 s 寻找接下来第一个不是空格的字符，找到后赋值到 a 的位置。
	接下来判断 s 后是否是空格，若是则停止赋值寻找下一个空格的位置，否则继续赋值。
	这样就可以将字符串中所有非空格字符按先后顺序排列在一起。
	最后，为排列好的非空格字符后加上 '\0' 截断字符串即可。
*/