/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:16:33 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/20 11:13:14 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_word(char const *s, char c, int i)
{
	int		j;
	char	*word;

	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	word = ft_calloc(sizeof(char), (j + 1));
	if (!word)
		return (0);
	word[j] = 0;
	while (j--)
		word[j] = s[i + j];
	return (word);
}

static int	count_words(char const *s, char c, int *i, int *k)
{
	int	j;
	int	nb_words;

	j = 0;
	*i = 0;
	*k = 0;
	nb_words = 0;
	while (s && s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j])
			nb_words++;
		while (s[j] && s[j] != c)
			j++;
	}
	return (nb_words);
}

static void	free_all(char **tab, int k)
{
	if (k != 0)
	{
		while (0 <= k)
			free(tab[k--]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	tab = ft_calloc(sizeof(char *), (count_words(s, c, &i, &k) + 1));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[k++] = create_word(s, c, i);
			if (!tab[k - 1])
			{
				free_all(tab, k - 1);
				return (0);
			}
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[k] = 0;
	return (tab);
}
