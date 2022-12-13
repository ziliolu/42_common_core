/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:52:47 by lpicoli-          #+#    #+#             */
/*   Updated: 2022/12/12 15:10:53 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_filter_format(format[++i], ap);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}


int main()
{/* 
	printf("-- original --\n");
	printf("%d, %d\n", 10, 20);

	printf("-- fake --\n");
	 */
	ft_printf("%d, %d\n", 10, 20);
}
