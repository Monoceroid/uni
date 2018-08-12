/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:04:50 by wtaylor           #+#    #+#             */
/*   Updated: 2018/06/05 20:28:19 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(const char *s, char c)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			sym = 1;
		}
		if (s[i] == c)
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}

static int	ft_nb_ch(const char *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || ((res = malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))) == NULL))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_nb_ch(s, i, c) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
