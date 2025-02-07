#ifndef SO_LONG_H
#define SO_LONG_H

#include "../Libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "../minilibx-linux/mlx.h"
enum e_CHECK
{
	FALSE,
	TRUE
};

#define NO_MAP "Error: Invalid Map\n"
#define PLA_CHAR 'P'
#define CL_CHAR 'C'
#define CL_WALL '1'
#define EXIT_CHAR 'E'
#define INV_FILE "Error: Invalid File\n"
#define PR_DENIED "Error: Permission Denied\n"
#define EXIT_FAILIRE 1
#define SUCCESS 0 
#define EXTENSION ".ber"
#define INV_WALL "Error: Invalid wall in the map\n"
#define INV_REG "Error: The map is not valid rectangle\n"
#define INV_CH "Error: The map contains invalid characters\n"
#define INV_PL "Error: Invalid number of players in the map\n"
#define INV_EX "Error: Invalid number of exits in the map\n"
#define INV_CL "Error: Invalid number of collectibles in the map\n"
#define INV_PATH "Error: NO valid path to exit and collectibles\n"
#define INV_ALC "Error: Memory allocation failed\n"
#define INV_WND "Error: Memory Failes to craete window\n"
#define HEIGHT 1080
#define WIDTH 1920
#define MSG "Welcome To My Game"
#define ESC 65307
#define GAME_OVER "GAME OVER\n"
typedef struct s_map
{
	char *name;
	int fd_map;
	char **map_2d;
} t_map;
typedef struct s_position
{
	int x;
	int y;
	int total_collectibe;
	int found_collectible;
	int found_exit;
} t_position;
typedef struct s_game
{
	void *mlx_ptr;
	void *mlx_win;
	t_map *map;
} t_game;
void execute_game(t_game *game);
void ft_error(char *str, t_map **lst);
#endif
