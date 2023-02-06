/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:32:53 by mi                #+#    #+#             */
/*   Updated: 2022/11/27 14:37:00 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp_set(char *str, char const *set)
{
	char	*ptr_set;
	int		flag;

	flag = 1;
	ptr_set = (char *)set;
	while (*ptr_set)
	{
		if (ft_strncmp(str, ptr_set, 1) == 0)
		{
			flag = 0;
		}
		ptr_set++;
	}
	return (flag);
}

static char	*ft_cal_start(char *str, char const *set)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_cmp_set(start, set) != 0)
			break ;
		start++;
	}
	return (start);
}

static char	*ft_cal_end(char *str, char const *set, char *start)
{
	char	*end;

	end = str + ft_strlen(str) - 1;
	while (start < end)
	{
		if (ft_cmp_set(end, set) != 0)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_cal_start((char *)s1, set);
	end = ft_cal_end((char *)s1, set, start);
	len = end - start + 1;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, start, len);
	res[len] = '\0';
	return (res);
}
