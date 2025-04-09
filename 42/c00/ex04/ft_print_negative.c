/* ****************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_negative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knznsmn <mail@knznsmn>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:31:21 by knznsmn           #+#    #+#             */
/*   Updated: 2025/04/09 23:31:21 by knznsmn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int n)
{
	if (n % 2 == 0) {
		ft_putchar('Y');
	}
	else {
		ft_putchar('N');
	}
}
