/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:47:42 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/12 18:06:46 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			count += ft_handle_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
int main()
{
	int value = 5;
	char value2 = 'H';
	char value3[] = "hello 42";
	void *ptr = value3;
	unsigned int value4 = 48879u;
	int a = printf("real: %d\n", value);
	int b = ft_printf("mine: %d\n", value);
	printf("real = %d | mine = %d\n", a, b);
	int c = printf("real: %c\n", value2);
	int d = ft_printf("mine: %c\n", value2);
	printf("real = %d | mine = %d\n", c, d);
	int e = printf("real: %s\n", value3);
	int f = ft_printf("mine: %s\n", value3);
	printf("real = %d | mine = %d\n", e, f);
	int k = printf("real: %u\n", value4);
	int l = ft_printf("mine: %u\n", value4);
	printf("real = %d | mine = %d\n", k, l);
	int m = printf("real: %x\n", value4);
	int n = ft_printf("mine: %x\n", value4);
	printf("real = %d | mine = %d\n", m, n);
	int o = printf("real: %X\n", value4);
	int p = ft_printf("mine: %X\n", value4);
	printf("real = %d | mine = %d\n", o, p);
	int g = printf("real: %p\n", ptr);
	int h = ft_printf("mine: %p\n", ptr);
	printf("real = %d | mine = %d\n", g, h);
	int i = printf("real: %%%%\n");
	int j = ft_printf("mine: %%%%\n");
	printf("real = %d | mine = %d\n", i, j);
}
// #include "ft_printf.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("--- 1. Testing NULL String (%%s) ---\n");
// 	printf("printf:    >");
// 	printf("%s", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%s", NULL);
// 	ft_printf("<\n\n");

// 	printf("--- 2. Testing NULL Pointer (%%p) ---\n");
// 	printf("printf:    >");
// 	printf("%p", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%p", NULL);
// 	ft_printf("<\n\n");

// 	printf("--- 3. Testing Zero (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", 0);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", 0);
// 	ft_printf("<\n\n");

// 	printf("--- 4. Testing INT_MIN (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", INT_MIN);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", INT_MIN);
// 	ft_printf("<\n\n");

// 	printf("--- 5. Testing INT_MAX (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", INT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", INT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 6. Testing UINT_MAX (%%u) ---\n");
// 	printf("printf:    >");
// 	printf("%u", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%u", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 7. Testing UINT_MAX (%%x) ---\n");
// 	printf("printf:    >");
// 	printf("%x", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%x", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 8. Testing UINT_MAX (%%X) ---\n");
// 	printf("printf:    >");
// 	printf("%X", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%X", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 9. Testing Null Char (%%c) ---\n");
// 	printf("printf:    >");
// 	printf("The char is %c here", '\0');
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("The char is %c here", '\0');
// 	ft_printf("<\n\n");

// 	printf("--- 10. Testing Empty String ---\n");
// 	printf("printf:    >");
// 	printf("");
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("");
// 	ft_printf("<\n\n");

// 	printf("--- 11. Testing String Ending with %% ---\n");
// 	printf("printf:    >");
// 	printf("This is a test %%");
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("This is a test %%");
// 	ft_printf("<\n\n");

// 	printf("--- 12. Testing Mixed Specifiers and %% ---\n");
// 	printf("printf:    >");
// 	printf("%d%s%p%%%%%%blablabla", 123, "abc", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d%s%p%%%%%%blablabla", 123, "abc", NULL);
// 	ft_printf("<\n\n");

// 	return (0);
// }
