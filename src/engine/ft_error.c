#include "head.h"

void	ft_perror(char *str)
{
	char	*error_str;
	char	*output;

	error_str = strerror(errno);
	if (str)
	{
		output = ft_strjoin(str, error_str);
		free(error_str);
		free(str);
	}
	else
		output = error_str;
	if (output)
		ft_putstr_fd(output, STDERR, "\033[0;31m");
	free(output);	
}

void	ft_error(char *str)
{
	ft_perror(str);
	// return (EXIT_FAILURE);
	exit(EXIT_FAILURE);
}
