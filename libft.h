/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abentoun <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/24 13:05:11 by abentoun     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 17:35:44 by lfourage    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct t_map
{
	char *map;
	int  nline;
	char empty;
	char wall;
	char sqr;
}    s_smap;
#endif
