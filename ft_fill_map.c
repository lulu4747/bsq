/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lfourage <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:41:01 by lfourage     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 23:56:56 by lfourage    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_first_line(char *map, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (map[i] == '0' || map[i] == '\n')
			i++;
		map[i] = '1';
		i++;
	}
	return (i);
}

void	ft_end_map(char *map, int len, int i)
{
	int n;

	n = 0;
	while (i < ft_strlen(map) - 1)
	{
		if (map[i] == '0' || map[i] == '\n')
			i++;
		map[i] = '1';
		if (map[i - 1] != '\n')
		{
			n = map[i - 1];
			if (map[i - len] < n)
				n = map[i - len];
			if (map[i - len - 1] < n)
				n = map[i - len - 1];
			n++;
			map[i] = n;
		}
		i++;
	}
}

char	*ft_fill_map(char *map, int len)
{
	int i;

	i = ft_first_line(map, len);
	ft_end_map(map, len, i);
	return (map);
}

int		main()
{
	char map[73] = "...0....\n........\n..0.....\n........\n.0......\n.....0..\n........\n..00....\n\0";

	printf("%s", ft_fill_map(map, 9));
}
