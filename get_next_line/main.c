#include <libc.h>
#include "get_next_line.h"

int main()
{
	int		fd;
//	char *result;
	char *line;

//	result = "";
	fd = open("./test_nl5.txt", O_RDONLY);
//	result = ft_read_file(fd, result); ;
//	printf("%s\n", result);
//	printf("print line : %s\n", ft_read_line(result));
//
//	printf("new file : %s\n", ft_read_new_file(result));


//	printf("avant get_next");
//	printf("avant get_next : %s", new);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("get_next : %s", line);
	free(line);
	close(fd);
	return (0);
}
