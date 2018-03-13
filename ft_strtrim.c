/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:52:17 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/05 14:02:53 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s)
{
	int		index;

	index = 0;
	while ((s[index] == '\n' || s[index] == '\t' || s[index] == ' ')
			&& s[index])
		index++;
	return (s[index] != '\0' ? index : -1);
}

static int	get_end(char const *s)
{
	int		str_len;

	str_len = ft_strlen(s) - 1;
	while ((s[str_len] == '\t' || s[str_len] == '\n' || s[str_len] == ' ')
			&& str_len >= 0)
		str_len--;
	return (str_len);
}

char		*ft_strtrim(char const *s)
{
	int		str_start;
	int		str_end;
	int		index;
	char	*final_str;

	str_start = get_start(s);
	if (str_start == -1)
	{
		final_str = malloc(sizeof(char));
		final_str[index] = '\0';
	}
	else
	{
		str_end = get_end(s);
		index = 0;
		final_str = malloc(sizeof(char) * (str_end - str_start) + 2);
		if (final_str == NULL)
			return (NULL);
		while (str_start <= str_end)
			final_str[index++] = s[str_start++];
		final_str[index] = '\0';
	}
	return (final_str);
}