/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:40:41 by skhali            #+#    #+#             */
/*   Updated: 2023/01/25 00:25:04 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_correct(int num)
{
	if ((num >= 0) && (num <= 255))
		return (1);
	else
		return (0);
}

int	char_to_rgb(char *c, char *f, t_game *w)
{
	char	**tmp1;

	tmp1 = ft_split(c, ',');
	w->cr = ft_atoi(tmp1[0]);
	if (!is_correct(w->cr))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	w->cg = ft_atoi(tmp1[1]);
	if (!is_correct(w->cg))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	w->cb = ft_atoi(tmp1[2]);
	if (!is_correct(w->cb))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	free_split(tmp1);
	tmp1 = ft_split(f, ',');
	w->fr = ft_atoi(tmp1[0]);
	if (!is_correct(w->fr))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	w->fg = ft_atoi(tmp1[1]);
	if (!is_correct(w->fg))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	w->fb = ft_atoi(tmp1[2]);
	if (!is_correct(w->fb))
		return (free_split(tmp1), close_win(w, "Erreur RGB.\n"), exit(1), 0);
	free_split(tmp1);
	return (1);
}

unsigned long	creatergb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	rgbcheck(char *path)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(path, ',');
	if (ft_strstrlen(tmp) != 3)
		return (free_split(tmp), 1);
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) == 0)
			return (free_split(tmp), 1);
		i++;
	}
	free_split(tmp);
	return (0);
}
