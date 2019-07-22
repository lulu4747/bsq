/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lfourage <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 16:24:38 by lfourage     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 16:31:34 by lfourage    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int  ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t  ft_strlen(const char *s)
{
	int  i;

	i = -1;
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

typedef struct t_map
{
	char *map;
	int  nline;
	char empty;
	char wall;
	char sqr;
}    s_smap;

s_smap get_param(char *s)
{
	int  fd;
	char *buf;
	s_smap smap;
	int  i;
	char *tmp;

	fd = open(s, O_RDONLY);
	if (!(buf = (char *)malloc(sizeof(*buf) * 5)))
		return (smap);
	read(fd, buf, 5);

	/* attribution of args */
	if (!((*buf)))
		return (smap);
	i = -1;
	if (!(buf = (char *)malloc(sizeof(*buf) * 5)))
		return (smap);
	while (*buf != '\n' && (++i))
	{
		read(fd, buf, 1);

		tmp - ft_strnjoin(tmp, buf, 1);
	}
	read(fd, buf, 5);

	smap.nline = 0;
	return(smap);
}

int  main(int ac, char **av)
{
	s_smap map;

	map = get_param(av[1]);
	if (!(ac == 1))
		return (0);
	bsq(av[1]);
	return(0);
}
