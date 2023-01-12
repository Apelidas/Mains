#include "push_swap.h"

void comb(int time, int numb, int out)
{
	if (time == 5)
	{
		printf("%d | %d\n", out, out % 120);
	}
	else
	{
		int i = 1;
		int tmp;
		out = out * 10;
		out = out + numb;
		while (i <= 5)
		{
			tmp = out;
			while (tmp > 0)
			{
				if (i != tmp % 10)
				{
					comb(time + 1, i, out);
					break;
				}
				tmp = tmp / 10;
			}
			i++;
		}
	}
}

int main()
{
	comb(4, 1, 1234);
	// int i = 1;

	// while (i <= 5)
	// {
	// comb(time + 1, i, out);
	// }
}