// WordCount.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<conio.h>
#include<stdio.h>
#include<string.h>//��ʹ��strcmp()����
int main(int cnt, char *order[])
/*main�е������������Դ��������ж�ȡ�������ļ���
cnt��¼�����м�����ַ����Ⱥ�˳����ʶ���������
order�ַ������¼���ļ����еĲ����ͱ��������ļ���
order[1]��¼�������ͣ���Ϊ-c��-w,�ֱ��Ӧʶ���ַ���ʶ������
order[2]Ϊfp�ļ�ָ��ָ��Ҫ�������ļ���*/
{
	FILE *fp = NULL;
	//��ʼ��һ�����ļ�ָ��

	int cnt_word = 0, cnt_char = 0;
	//�ֱ������ļ��е��ʺ��ַ��ļ���,����ʼ��Ϊ0

	char ch;
	//��ʱ��Ŵ��ļ��ж������ַ�

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
		printf("�ַ�����%d", cnt_char);
	}
	else if (strcmp(order[1], "-w") == 0)
	{
		printf("��������%d", cnt_word);
	}
}
