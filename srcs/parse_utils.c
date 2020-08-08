/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:43:42 by yictseng          #+#    #+#             */
/*   Updated: 2020/08/08 18:03:45 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_stradd_back(char *line, char **tab)
{
	char	**dup;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	if (!(dup = malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		dup[i] = tab[i];
		i++;
	}
	dup[i] = ft_strdup(line);
	i++;
	dup[i] = NULL;
	free(tab);
	return (dup);
}

void	adjust_resolution(t_cfg *cfg)
{
	cfg->width = cfg->width > 1440 ? 1440 : cfg->width;
	cfg->height = cfg->height > 900 ? 900 : cfg->height;
	cfg->width = cfg->width < 100 ? 100 : cfg->width;
	cfg->height = cfg->height < 100 ? 100 : cfg->height;
}
