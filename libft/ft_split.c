/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:25:20 by mi                #+#    #+#             */
/*   Updated: 2022/11/27 14:41:25 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_free_before(int index, char **res)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		idx;

	idx = 0;
	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			res[idx] = (char *)malloc(sizeof(char) * (ft_word_len(s, c) + 1));
			if (res[idx] == NULL)
				return (ft_free_before(idx, res));
			ft_strlcpy(res[idx++], s, ft_word_len(s, c) + 1);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	res[idx] = NULL;
	return (res);
}
