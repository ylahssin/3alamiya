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
void get_size_map(char **map, int *row, int *cols)
{
	while(map[*cols])
		(*cols)++;
	while(map[0][*rows])
		(*rows)++;
}
void get_all_textures(t_game **game, t_texture *texture)
{
	texture->wall = mlx_file_to_image((*game)->mlx_ptr, WALL_XPM, &texture->width, &texture->hight);
	texture->player = mlx_file_to_image((*game)->mlx_ptr, PLAYER_XPM, &texture->width, &texture->hight);
	texture->collect = mlx_file_to_image((*game)->mlx_ptr, COLLECT_XPM, &texture->width, &texturei->hight);
	texture->exit = mlx_file_to_image((*game)->mlx_ptr, EXIT_XPM, &texture->width, &texture->hight);
	texture->space = mlx_file_to_image((*game)->mlx_ptr, SPACE_XPM, &texture->width, &texture->hight);
	//check error when textures filled
}
void ft_load_textures(t_game **game)
{
	get_size_map((*game)->map->map_2d, &(*game)->rows,
			&(*game)->cols);
	(*game)->texture->width = (*game)->rows * 32;
	(*game)->texture->hight = (*game)->cols * 32;
	get_all_textures(game ,&(*game)->texture);
	giy<F4>

}
void manage_window(t_game *game)
{
	game->mlx_ptr = mlx_init();

	if(!game->mlx_ptr)
		ft_error(INV_WND, &game->map);
	game->mlx_win = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, MSG);
	if(!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, NULL);
	//      -------->start work TD<--------
	ft_load_textures(&game);
	//      -------->end work TD<--------
	mlx_key_hook(game->mlx_win, manage_key, game);
	mlx_loop(game->mlx_ptr);
}
void execute_game(t_game *game)
{
	manage_window(game);		
}
