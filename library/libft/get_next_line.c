/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2025/01/31 17:56:46 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

// char	*read_fd(int fd, char *stash)
// {
// 	char	*buffer;
// 	int		bytes_read;

// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	bytes_read = 1;
// 	while (!ft_strchr(stash, '\n') && bytes_read != 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 		{
// 			free(stash);
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[bytes_read] = '\0';
// 		stash = ft_strjoin(stash, buffer);
// 	}
// 	free (buffer);
// 	return (stash);
// }

// char	*get_current_line(char *stash)
// {
// 	int		i;
// 	char	*string;

// 	i = 0;
// 	if (!stash[i])
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	string = ft_substr(stash, 0, i + ft_endl(stash));
// 	if (!string)
// 	{
// 		free (string);
// 		return (NULL);
// 	}
// 	return (string);
// }

// char	*string_to_add(char *stash)
// {
// 	char	*string;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (!stash[i])
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	string = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
// 	if (!string)
// 		return (NULL);
// 	i++;
// 	while (stash[i])
// 		string[j++] = stash[i++];
// 	string[j] = '\0';
// 	free (stash);
// 	return (string);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*stash;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	stash = read_fd(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	printf("\n passou do read");
// 	line = get_current_line(stash);
// 	printf("\n passou do current line");
// 	stash = string_to_add(stash);
// 	printf("\n passou do string");
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	*rl[1024];
	char		*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	buffer = ft_check_buffer(fd, &rl[fd]);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		rl[fd] = ft_get_temp(bytes_read, buffer, rl[fd]);
		if (ft_strchr(rl[fd], '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!rl[fd] || rl[fd][0] == '\0')))
		return (free(rl[fd]), rl[fd] = NULL);
	line = ft_extract_line(rl[fd]);
	temp = ft_strdup(rl[fd] + ft_strlen(line));
	free(rl[fd]);
	rl[fd] = temp;
	return (line);
}

char	*ft_extract_line(char *rl)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (rl[i] && rl[i] != '\n')
		i++;
	if (rl[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = rl[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_check_buffer(int fd, char **rl)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (*rl == NULL)
		*rl = ft_strdup("");
	return (buffer);
}

char	*ft_get_temp(int bytes_read, char *buffer, char *rl)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = ft_strjoin(rl, buffer);
	free(rl);
	return (temp);
}
