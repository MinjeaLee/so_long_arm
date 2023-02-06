/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:21:10 by mi                #+#    #+#             */
/*   Updated: 2022/11/18 21:19:36 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	if (ptr1 < ptr2)
	{
		while (len--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		ptr1 += len;
		ptr2 += len;
		while (len--)
			*--ptr1 = *--ptr2;
	}
	return (dst);
}
