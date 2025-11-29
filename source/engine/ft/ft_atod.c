/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:57:58 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:57:59 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

static double	parse_number_sub(double result, const unsigned char *str,
		unsigned int *loop, unsigned char *error)
{
	double	divisor;

	if (str[*loop] == '.')
	{
		*loop += 1;
		divisor = 10.0;
		while (ft_isdigit(str[*loop]))
		{
			result += (str[*loop] - '0') / divisor;
			divisor *= 10.0;
			*loop += 1;
		}
		if (str[*loop] == '.')
		{
			*error = 1;
			return (0.0);
		}
	}
	return (result);
}

static double	parse_number(const unsigned char *str,
		unsigned int *loop, unsigned char *error)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	if (str[*loop] == '-')
	{
		sign = -1;
		*loop += 1;
	}
	if (!ft_isdigit(str[*loop]) && str[*loop] != '.')
	{
		*error = 1;
		return (0.0);
	}
	while (ft_isdigit(str[*loop]))
	{
		result = result * 10.0 + (str[*loop] - '0');
		*loop += 1;
	}
	return (parse_number_sub(result, str, loop, error) * sign);
}

double	ft_atod(const unsigned char *str,
		unsigned int number, unsigned char *error)
{
	unsigned int	loop;
	unsigned int	current;

	loop = 0;
	current = 0;
	while (str[loop] != '\0' && str[loop] != '\n')
	{
		while (ft_isspace(str[loop]) || str[loop] == ',')
			loop += 1;
		if (str[loop] == '\0' || str[loop] == '\n')
			break ;
		if (current == number)
			return (parse_number(str, &loop, error));
		parse_number(str, &loop, error);
		if (*error == 1)
			return (0.0);
		current += 1;
	}
	*error = 1;
	return (0.0);
}
