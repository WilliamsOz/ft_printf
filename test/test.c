#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// static long		ft_intlen(long nbr)
// {
// 	int		i;
// 	long	len;

// 	i = 1;
// 	len = 1;
// 	while (nbr >= 10)
// 	{
// 		nbr /= 10;
// 		i++;
// 	}
// 	while (--i > 0)
// 		len *= 10;
// 	return (len);
// }

// void			ft_putnbr(long n)
// {
// 	char	res[10];
// 	long	nbr;
// 	int		i;
// 	long	cc;

// 	nbr = n;
// 	i = -1;
// 	cc = 0;
// 	while (++i < 10)
// 		res[i] = '\0';
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr *= -1;
// 	}
// 	i = 0;
// 	cc = ft_intlen(nbr);
// 	while (cc > 0)
// 	{
// 		res[i] = ('0' + ((nbr / cc) % 10));
// 		write(1, &res[i], 1);
// 		cc /= 10;
// 		i++;
// 	}
// }

int main(void)
{
	char	*str;

	asprintf(&str, "%.50d", 10000);
	printf("%s\n", str);
	return (0);
}
