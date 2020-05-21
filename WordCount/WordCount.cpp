// WordCount.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<conio.h>
#include<stdio.h>
#include<string.h>//以使用strcmp()函数
int main(int cnt, char *order[])
/*main中的两个参数用以从命令行中读取操作和文件名
cnt记录命令行键入的字符串先后顺序以识别操作类型
order字符数组记录对文件进行的操作和被操作的文件名
order[1]记录操作类型，分为-c和-w,分别对应识别字符和识别数组
order[2]为fp文件指针指向要操作的文件名*/
{
	FILE *fp = NULL;
	//初始化一个空文件指针

	int cnt_word = 0, cnt_char = 0;
	//分别用于文件中单词和字符的计数,均初始化为0

	char ch;
	//临时存放从文件中读出的字符

	fp = fopen("practice.txt", "r");
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		if (ch == ' ' || ch == ',') { cnt_word++;cnt_char++; }
		if (ch == '\t' || ch == '\n' || ch >= '!'&&ch <= '/' || ch >= ':'&&ch <= '@' || ch >= '['&&ch <= '`' || ch >= '{'&&ch <= '~') { cnt_char++; }
	}
	fclose(fp);

	if (strcmp(order[1], "-c") == 0)
	{
		printf("字符数：%d", cnt_char);
	}
	else if (strcmp(order[1], "-w") == 0)
	{
		printf("单词数：%d", cnt_word);
	}
}
