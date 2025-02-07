#include "so_long.h"
#include <stdio.h>

int manage_key(int keycode, t_game *game)
{
	if(keycode == ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_error(GAME_OVER, &game->map);
	}
	return(0);
}
void manage_window(t_game *game)
{
	game->mlx_ptr = mlx_init();

	if(!game->mlx_ptr)
		ft_error(INV_WND, &game->map);
	game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, MSG);
	if(!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, NULL);
	mlx_key_hook(game->mlx_win, manage_key, game);
	mlx_loop(game->mlx_ptr);
}
void execute_game(t_game *game)
{
	manage_window(game);		
}
