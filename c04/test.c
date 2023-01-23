#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str, int *len)
{
	while (*str)
		*len += write(1, &(*str++), 1);
}

void	ft_putnbr(unsigned long long nb, int base, int *len)
{
	char	*data;

	data = "0123456789abcdef";
	if (nb >= (unsigned long long)base)
		ft_putnbr((nb / base), base, len);
	*len += write(1, &data[nb % base], 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		digit;
	int		len;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr((char *)va_arg(ptr, void *), &len);
			else if (str[i] == 'd')
			{
				digit = (long long int)va_arg(ptr, void *);
				if (digit < 0)
				{
					digit *= -1;
					len += write(1, "-", 1);
				}
				ft_putnbr(digit, 10, &len);
			}
			else if (str[i] == 'x')
			{
				digit = (long long int)va_arg(ptr, void *);
				ft_putnbr(digit, 16, &len);
			}
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}

int	main(void)
{
	// int i = 0;

	// write(1, "\n", 1);
	// i = ft_printf("%s\nint: %d\nint: %d\nhex: %x\nhex: %x\nlast int: %d\n",
	// 				"azul fell-awen a xwali dagi tes3am    ",
	// 				89,
	// 				-2147483648,
	// 				42,
	// 				0,
	// 				0);
	// ft_printf("ft_printf result: %d\n", i);
	write(1, "\n\n", 2);
	ft_printf("Hexadecimal for %d is %x\n", 42,-42);
	printf("Hexadecimal for %d is %x\n", 42, -42);
	// ft_printf("Magic %s is %d", "number", 42);
	write(1, "\n\n", 2);
	// i = 0;
	// i = ft_printf("%s\nint: %d\nint: %d\nhex: %x\nhex: %x\nlast int: %d\n",
	// 				"azul fell-awen a xwali dagi tes3am    ",
	// 				89,
	// 				-2147483648,
	// 				42,
	// 				0,
	// 				0);
	// printf("printf result: %d\n", i);
	return (0);
}