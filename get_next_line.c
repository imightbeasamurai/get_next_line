#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len0;
	int		len1;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len0 = ft_strlen(s1);
	len1 = ft_strlen(s2);
	str = (char *)malloc(len0 + len1 + 1);
	if (!str)
		return (NULL);
	ft_memcpy (str, s1, len0);
	ft_memcpy (str + len0, s2, len1);
	str[len0 + len1] = '\0';
	return (str);
}

char	*read_line(int fd)
{
	int		offset;
	char	*line;
	char	*tmp0;
	char	*tmp1;

	line = NULL;
	tmp0 = malloc(BUFFER_SIZE + 1);
	if (!tmp0)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		offset = read(fd, tmp0, BUFFER_SIZE);
		if (offset < 0)
			return (free(tmp0), NULL);
		if (offset == 0)
			break ;
		tmp0[offset] = '\0';
		tmp1 = line;
		line = ft_strjoin(line, tmp0);
		if (!line)
			return (free(tmp0), free(tmp1), NULL);
		free(tmp1);
	}
	return (free(tmp0), line);
}

char	*get_rest_line(char *hold)
{
	int		nl;
	int		i;
	char	*hold0;

	nl = 0;
	i = 0;
	hold0 = NULL;
	while (hold[nl] && hold[nl] != '\n')
		nl++;
	if (hold[nl] && hold[nl + 1] && hold[nl] == '\n')
	{
		hold0 = malloc(ft_strlen(hold) - nl + 1);
		while (hold[++nl])
			hold0[i++] = hold[nl];
			hold0[i] = 0;
	}
	return (hold0);
}

char	*get_current_line(char *line)
{
	char	*str;
	int		nl;

	str = NULL;
	nl = 0;
	while (line && line[nl] && line[nl] != '\n')
		nl++;
	if (line && line[nl] == '\n')
	{
		str = malloc(nl + 2);
		if (!str)
			return (free(line), NULL);
		ft_memcpy(str, line, nl + 1);
		str[nl + 1] = 0;
	}
	return (free(line), str);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*tmp;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd);
	if (hold)
	{
		tmp = line;
		line = ft_strjoin(hold, line);
		free(tmp);
		free(hold);
		hold = NULL;
	}
	if (line && ft_strchr(line, '\n'))
	{
		if (ft_strlen(line) > 1)
			hold = get_rest_line(line);
		line = get_current_line(line);
	}
	return (line);
}

