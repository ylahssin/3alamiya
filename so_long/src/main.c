#include "so_long.h"
#include <stdio.h>

void ft_lst_free(t_map **map)
{
	int i = 0;

	if(!map)
		return;
	if((*map)->map_2d)
	{
		while((*map)->map_2d[i])
			free((*map)->map_2d[i++]);
		free((*map)->map_2d);
	}
	free(*map);
}
void ft_error(char *str, t_map **lst)
{
    write(2, str, ft_strlen(str));
    if (lst)
        ft_lst_free(lst);
    exit(EXIT_FAILURE);
}

void ft_check_map(char *str, t_map *map)
{
    map->name = ft_strstr(str, EXTENSION);
    if (!map->name || ft_strlen(map->name) != ft_strlen(EXTENSION))
            ft_error(INV_FILE, &map);
    map->fd_map = open(str, O_RDONLY);
    if (map->fd_map == -1)
        ft_error(PR_DENIED, &map);
}

int is_one(char *map)
{
    while (*map)
    {
        if (*map != '1')
            return (FALSE);
        map++;
    }
    return (TRUE);
}

int is_check_one(char *map)
{
    int i = 0;

    while (map[i])
    {
        if ((i == 0 || i == (int)(ft_strlen(map) - 1)) && map[i] != '1')
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int check_the_wall(char **map, int idx)
{
    int i = 0;

    while (map[i])
    {
        if ((i == 0 || i == idx - 1) && !is_one(map[i]))           
		return (FALSE);
        else if (!is_check_one(map[i]))
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int check_is_rectangle(char **map)
{
    int i = 0, j = 1;

    while (map[i] && map[j])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[j]))
            return (FALSE);
        i++;
        j++;
    }
    return (TRUE);
}

int is_valid_chars(char c)
{
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int check_valid_chars(char **map)
{
    int i = 0, j;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!is_valid_chars(map[i][j]))
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int is_check(char **map, char c)
{
    int i = 0, j, count = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count == 1);
}

int is_check_collectible(char **map, char c)
{
    int i = 0, j, count = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count >= 1);
}

void check_all_map(t_map *map, int idx)
{
    if (!check_the_wall(map->map_2d, idx))
        ft_error(INV_WALL, &map);
    else if (!check_is_rectangle(map->map_2d))
        ft_error(INV_REG, &map);
    else if (!check_valid_chars(map->map_2d))
        ft_error(INV_CH, &map);
    else if (!is_check(map->map_2d, PLA_CHAR))
        ft_error(INV_PL, &map);
    else if (!is_check(map->map_2d, EXIT_CHAR))
        ft_error(INV_EX, &map);
    else if (!is_check_collectible(map->map_2d, CL_CHAR))
        ft_error(INV_CL, &map);
}

void ft_read_map(t_map *map)
{
    char *line;
    int i = 0;
    char *all_map = NULL, *tmp;
    while (1)
    {
	tmp = all_map;
        line = get_next_line(map->fd_map);
        if (!line)
            break;
        all_map = ft_strjoin(all_map, line);
	free(tmp);
        free(line);
    }
    map->map_2d = ft_split(all_map, '\n');
    free(all_map);
    close(map->fd_map);
    if(!map->map_2d)
	    ft_error("NICK_MOK", NULL);
    check_all_map(map, i - 1);
}

int main(int ac, char **av)
{
    t_map *map = malloc(sizeof(t_map));

    if (ac < 2 || !map)
        ft_error(NO_MAP, &map);
    ft_check_map(av[1], map);
    ft_read_map(map);
   ft_lst_free(&map); 
    return (SUCCESS);
}

