/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abentoun <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 14:23:01 by abentoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 17:44:42 by lfourage    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lfourage <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 16:24:38 by lfourage     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 13:35:25 by abentoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_map{
	char *map;	int  nline;
	char empty;
	char wall;
	char sqr;
}    s_smap;

int		ft_strlen(char *s)
{
	int  i;

	i = 0;
	while (s[++i])
		;
	return (i);
}

void ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

s_smap	ft_saveparams(s_smap smap, char *tmp)
{
	int c;
	int i;

	i = 0;
	smap.nline = 0;
	c = ft_strlen(tmp) - 4;
	while (i < c)
	{
		smap.nline = smap.nline * 10 + tmp[i] - '0';
		i++;
	}
	smap.empty = tmp[i];
	i++;
	smap.wall = tmp[i];
	i++;
	smap.sqr = tmp[i];
	return (smap);
}

s_smap get_param(char *s)
{
	int  fd;
	char *buf;
	s_smap smap;
	int  i;
	char *tmp;

	i = 0;	
	fd = open(s, O_RDONLY);
	if (!(buf = malloc(sizeof(char) * 1)))
		return (smap);
	while (buf[i] != '\n')
	{
		read(fd, buf, 1);
		if (!(tmp = malloc(sizeof(char) * 1)))
			return (smap);
		tmp[i] = buf[0];
		i++;
	}
	smap = ft_saveparams(smap, tmp);
	i = 0;
	free(tmp);
	while (buf[i] != '\n')
	{
		read(fd, buf, 1);
		if (!(tmp = malloc(sizeof(char) * 1)))
			return (smap);
		tmp[i] = buf[0];
		i++;
	}
	free(buf);
	if (!(buf = malloc(sizeof(char) * i)))
		return (smap);
	while (read(fd, buf, i))
	{
		if (!(tmp = malloc(sizeof(char) * i)))
			return (smap);
		tmp = buf;
		i++;
	}
	if (!(smap.map = malloc(sizeof(char) * ft_strlen(tmp))))
		return (smap);
	smap.map = tmp;
	free(buf);
	free(tmp);
	return(smap);
}

int  main(int ac, char **av)
{
	s_smap map;
	int i;
	i = 1;
	if (!(ac < 2))
		return (0);
	while (i <= ac)
	{
		map = get_param(av[i]);
		i++;
	}
	printf("%s", map.map);
	return(0);
}
