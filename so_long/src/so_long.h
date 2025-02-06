#ifndef SO_LONG_H
#define SO_LONG_H

#include "../Libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

enum e_CHECK
{
	FALSE,
	TRUE
};

#define NO_MAP "Error: Invalid Map\n"
#define PLA_CHAR 'P'
#define CL_CHAR 'C'
#define EXIT_CHAR 'E'
#define INV_FILE "Error: Invalid File\n"
#define PR_DENIED "Error: Permission Denied\n"
#define EXIT_FAILIRE 1
#define SUCCESS 0 
#define EXTENSION ".ber"
#define INV_WALL "Error: Invalid wall in the map\n"
#define INV_REG "Error: The map is not valid rectangle\n"
#define INV_CH "error: The map contains invalid characters\n"
#define INV_PL "Error: Invalid number of players in the map\n"
#define INV_EX "Error: Invalid number of exits in the map\n"
#define INV_CL "error: Invalid number of collectibles in the map\n"
typedef struct s_map
{
	char *name;
	int fd_map;
	char **map_2d;
} t_map;
#endif
