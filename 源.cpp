#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

		用库函数实现 查找 字符串1 里是否有 字符串2
int is_left_move(char*arr1, char*arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 == len2)
		  1.第一个字符串自增
		 strcat(arr1, arr1); 增加自己(arr1)时会报错
	{
		strncat(arr1, arr1, len1);
		  存在问题：如果2字符串长度不一样，但也会yes 
		  2.找arr1里是否有子串arr2
		char* ret = strstr(arr1, arr2);
		 strstr - 找子串，1里是否包含2,有则返回地址，无则返回空指针
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

			实现 杨氏矩阵
		法 1
int Findnum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	/*while (x!=3 && y!=0)*/
	while(x<=row-1 && y>=0)
	{
		if (arr[x][y] > k)
		{
			y--;			  //  不使用printf无法实现输出 该元素的坐标
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
			法 2
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
			*px = x;	// 通过指针，实现在函数内修改，值返回
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
	  返回型参数
	int ret = Findnum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("有了\n");
		printf("其坐标是:(%d,%d)", x, y);
	}
	else
		printf("没有\n");
	return 0;
}

	函数里欲带回几个值，返回值搞不定，可以使用返回型参数