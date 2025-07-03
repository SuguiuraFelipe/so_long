/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:15:28 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 18:15:13 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

/* libs padrão */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

/* get_next_line para ler o mapa */
# include "../get_next_line/get_next_line.h"

/* MiniLibX */
# include "mlx.h"

/*
 * Estrutura que guarda todo o estado do jogo:
 * - map: matriz de chars
 * - rows/cols: dimensões
 * - player_x/y: posição atual
 * - collectibles: quantos faltam pegar
 * - steps: contador de movimentos
 * - mlx_ptr, win_ptr: ponteiros do MLX
 * - img_...: imagens carregadas
 */
typedef struct s_game
{
    char    **map;
    int     rows;
    int     cols;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     steps;
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_floor;
    void    *img_wall;
    void    *img_player;
    void    *img_collectible;
    void    *img_exit;
}               t_game;

/* check_args.c */
void    check_args(int argc, char **argv);
int     ft_strlen(const char *s);

/* read_map.c */
char    **read_map(const char *path);
void    free_map(char **map);

/* map_utils.c */
void    free_map(char **map);

/* validation.c */
void    validate_rectangle_and_walls(char **map);
void    validate_elements(char **map);
/* flood_fill.c */
void    validate_paths(char **map);

/* flood_fill_utils.c */
char    **dup_map(char **map);

/* render.c */
void    render_map(t_game *game);

/* input.c */
int     handle_input(int keycode, t_game *game);

/* game.c */
void    start_game(char **map);
void    load_images(t_game *g);

/* cleanup.c */
void    cleanup_game(t_game *game);

#endif /* SO_LONG_H */
