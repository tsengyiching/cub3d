/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:43:42 by yictseng          #+#    #+#             */
/*   Updated: 2020/05/24 18:01:58 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		ft_atoi(int i, char *line)
{
	int		nb;

	nb = 0;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
	{
		nb = nb * 10 + (line[i] - '0');
		i++;
	}
	return (nb);
}

int		ft_atoi_save_index(int *i, char *line)
{
	int		nb;

	nb = 0;
	if (line[*i] < '0' || line[*i] > '9')
		return (-1);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		nb = nb * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (nb);
}
