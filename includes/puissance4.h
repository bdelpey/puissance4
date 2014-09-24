/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbell <vbell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 07:26:08 by vbell             #+#    #+#             */
/*   Updated: 2014/09/24 15:27:03 by bdelpey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			PUISSANCE4_H
# define		PUISSANCE4_H

# define		COL_ERR			"## \033[1;31mYou can't play here.\033[1;0m ##"
# define		MIN_LINE		6
# define		MIN_COL			7
# define		EMPTY_CAR		'_'
# define		PLAYER_A		'O'
# define		PLAYER_B		'X'

typedef struct	s_cnct
{
	char		ia;
	char		player;
	int			NB;
	int			LN;
}				t_cnct;

int				check_col_not_full(char **map, int col);
int				check_player_entry(char **map, char *str);
char			**init_map(int ac, char **av, int *multi);
int				is_num(char *str);
void			who_s_begin(char *ia, char *player, int multi);
int				player_turn(char **map, char player, int multi);
int				insert_piece(char **map, char player, int col, int fl);
void			change_turn(char *who_play);
int				ia_turn(char **map, char ia, char player);
int				is_winner(char **map, char player, int col, int line);
int				check_diagleft(char **map, char player, int col, int line);
int				check_diagright(char **map, char player, int col, int line);
int				player_adverse(char player);
void			init_max_len(int *nb_piece, int *ln, int *col, char **map);
void			lets_play(char **map, int multi);
int				check_block(char **map, char player, int col);
int				check_ia_piece(char **map, char ia);
int				check_advanced_fork(char **map, t_cnct *c, int col);
int				vertical_fork(char **map, t_cnct *c);
int				one_move_vertical_fork(char **map, t_cnct *c);
int				default_place(char **map, char ia, int col);
int				player_player_play(char **map, char p1, char p2, char player);
int				player_ia_play(char **map, char p1, char p2, char player);
int				ia_ia_play(char **map, char ia1, char ia2, char player);

#endif			/*!PUISSANCE4_H*/
