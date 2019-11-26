#include<stdio.h>  
#include<string.h>

void str_cmp01()
{
	char str[80], rev[80];
	int n, i, x;

	printf("Enter a string: ");
	//scanf("%s", str);
	str[0] = 't';
	
	n = strlen(str);

	x = 0;
	for (i = n - 1; i >= 0; i--)
	{
		rev[x] = str[i];
		x++;
	}
	rev[x] = '\0';
	if (strcmp(str, rev) == 0)
		printf("The %s is palindrome", str);
	else
		printf("The %s is not palindrome", str);
}


int ifexists(char u, char z[], int v)
{
	int i;
	for (i = 0; i < v; i++)
		if (z[i] == u) return (1);
	return (0);
}

void str_cmp02()
{
	char str1[80], str2[80];
	int n, i, x;

	printf("Enter a string: ");
	scanf_s("%s", str1);

	n = strlen(str1);
	str2[0] = str1[0];
	x = 1;
	for (i = 1; i < n; i++)
	{
		if (ifexists(str1[i], str2, x))
		{
			printf("The first repetitive character in %s is %c", str1, str1[i]);
			break;
		}
		else
		{
			str2[x] = str1[i];
			x++;
		}
	}
	if (i == n)
		printf("There is no repetitive character in the string %s", str1);
}


int ifexists3(char u, char p[], int v, int q[])
{
	int i;
	for (i = 0; i <= v; i++)
	{
		if (p[i] == u)
		{
			q[i]++;
			return (1);
		}
	}
	if (i > v) return (0);
}
void str_cmp03()
{
	//char str[80], chr[80];
	char chr[80];
	int n, i, x, count[80];
	printf("Enter a string: ");
	//scanf_s("%s", str);
	char str[10] = "test";

	n = strlen(str);

	chr[0] = str[0];
	count[0] = 1;
	x = 0;
	for (i = 1; i < n; i++)
	{
		if (!ifexists3(str[i], chr, x, count))
		{
			x++;
			chr[x] = str[i];
			count[x] = 1;
		}
	}
	printf("The count of each character in the string %s is \n", str);
	for (i = 0; i <= x; i++)
		printf("%c\t%d\n", chr[i], count[i]);
}


void str_cmp04()
{
	char str[255];
	int  i;
	printf("Enter a sentence: ");
	gets(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'
			|| str[i] == 'u')
			str[i] = str[i] - 32;
		i++;
	}
	printf("The sentence after converting vowels into uppercase is:\n");
	puts(str);
}