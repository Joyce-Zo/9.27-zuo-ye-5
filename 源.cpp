#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

		�ÿ⺯��ʵ�� ���� �ַ���1 ���Ƿ��� �ַ���2
int is_left_move(char*arr1, char*arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 == len2)
		  1.��һ���ַ�������
		 strcat(arr1, arr1); �����Լ�(arr1)ʱ�ᱨ��
	{
		strncat(arr1, arr1, len1);
		  �������⣺���2�ַ������Ȳ�һ������Ҳ��yes 
		  2.��arr1���Ƿ����Ӵ�arr2
		char* ret = strstr(arr1, arr2);
		 strstr - ���Ӵ���1���Ƿ����2,���򷵻ص�ַ�����򷵻ؿ�ָ��
		if (ret == NULL)
		{
			return 0;
		}
		else
			return 1;
	}
	else
		return 0;
	
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "defa";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("%Yes\n");
	else
		printf("No\n");
	strcat(arr1, arr1);
	printf("%s", strcat(arr1, arr1));
	return 0;
}

			ʵ�� ���Ͼ���
		�� 1
int Findnum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	/*while (x!=3 && y!=0)*/
	while(x<=row-1 && y>=0)
	{
		if (arr[x][y] > k)
		{
			y--;			  //  ��ʹ��printf�޷�ʵ����� ��Ԫ�ص�����
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
			�� 2
int Findnum(int arr[3][3], int k, int* px,int* py)
{
	int x = 0;
	int y = *py - 1;
	/*while (x!=3 && y!=0)*/
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;	// ͨ��ָ�룬ʵ���ں������޸ģ�ֵ����
			*py = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;	
	int y = 3;
	/*int ret = Findnum(arr, k, 3, 3);*/
	  �����Ͳ���
	int ret = Findnum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("����\n");
		printf("��������:(%d,%d)", x, y);
	}
	else
		printf("û��\n");
	return 0;
}

	�����������ؼ���ֵ������ֵ�㲻��������ʹ�÷����Ͳ���