/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:44:31 by wtaylor           #+#    #+#             */
/*   Updated: 2018/05/19 17:57:41 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(char const *s)
{
	int		i;
	int		startspaces;
	int		endspaces;
	int		len;
	char	*t;

	i = 0;
	startspaces = 0;
	while (s[i++] != '\0' && (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || \
				s[i] == '\t'))
		startspaces++;
	while (s[i++] != '\0')
		len++;
	while (s[i--] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		endspaces++;
	len -= endspaces;
	t = (char *)malloc((len + 1) * sizeof(t));
	i = startspaces - 1;
	endspaces = 0;
	while (i++ < (startspaces + len))
	{
		t[endspaces] = s[i];
		endspaces++;
	}
	t[endspaces] = '\0';
	return (t);
}
