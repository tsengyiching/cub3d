/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:13:11 by yictseng          #+#    #+#             */
/*   Updated: 2020/07/30 14:36:24 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		write_error(int error_code)
{
	if (error_code == -1)
		write(1, "Error: Wrong number of argument\n", 32);
	else if (error_code == -2)
		write(1, "Error: Opening file failed\n", 27);
	else if (error_code == -3)
		write(1, "Error: Having invalid identifier\n", 34);
	else if (error_code == -4)
		write(1, "Error: Resolution\n", 18);
	else if (error_code == -5)
		write(1, "Error: Invalid path to the north texture\n", 41);
	else if (error_code == -6)
		write(1, "Error: Invalid path to the west texture\n", 40);
	else if (error_code == -7)
		write(1, "Error: Invalid path to the east texture\n", 40);
	else if (error_code == -8)
		write(1, "Error: Invalid path to the south texture\n", 41);
	else if (error_code == -9)
		write(1, "Error: Invalid path to the sprite texture\n", 42);
	else if (error_code == -10)
		write(1, "Error: Invalid ceiling RGB\n", 28);
	else if (error_code == -11)
		write(1, "Error: Invalid floor RGB\n", 26);
	else if (error_code == -12)
		write(1, "Error: Invalid char after RGB\n", 30);
	else if (error_code == -13)
		write(1, "Error: Invalid map\n", 19);
	else if (error_code == -14)
		write(1, "Error: Memory allocation failure\n", 33);
	else if (error_code == -15)
		write(1, "Error: Missing map\n", 18);
	else if (error_code == -16)
		write(1, "Error: Map has invalid char\n", 28);
	else if (error_code == -17)
		write(1, "Error: Map has wrong number of starting position\n", 49);
	else if (error_code == -18)
		write(1, "Error: Map is not closed with walls (left)\n", 43);
	else if (error_code == -19)
		write(1, "Error: Map is not closed with walls (right)\n", 44);
	else if (error_code == -20)
		write(1, "Error: Map is not closed with walls (up)\n", 41);
	else if (error_code == -21)
		write(1, "Error: Map is not closed with walls (down)\n", 43);
	else if (error_code == -22)
		write(1, "Error: Invalid map file extension\n", 34);
	else if (error_code == -23)
		write(1, "Error: the last argument is not --save\n", 38);
	return (0);
}
