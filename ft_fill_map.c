/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lfourage <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 18:41:01 by lfourage     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 22:48:21 by lfourage    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_fill_map(char *map, int linelen)
{
	int i;
	int n;
	char *mpf;

	i = 0;
	if (!(mpf = malloc((sizeof(char)) * (ft_strlen(map)))))
		return (NULL);
	while (map[i])
	{
		while (i < linelen)
		{
			if (map[i] == '0' || map[i] == '\n')
				mpf[i] = map[i];
			else
				mpf[i] = '1';
			i++;
		}
		if (map[i] == '0' || map[i] == '\n')
			mpf[i] = map[i];
		else
		{
			mpf[i] = '1';
			if (map[i - 1] != '\n')
			{
				n = mpf[i - 1];
				if (mpf[i - linelen] < n)
					n = mpf[i - linelen];
				if (mpf[i - linelen - 1] < n)
					n = mpf[i - linelen - 1];
				n++;
				mpf[i] = n;
			}
		}
		i++;
	}
	return (mpf);
}

int		main()
{
	char map[73] = "...0....\n........\n..0.....\n........\n.0......\n.....0..\n........\n..00....\n\0";

	printf("%s", ft_fill_map(map, 9));
}
