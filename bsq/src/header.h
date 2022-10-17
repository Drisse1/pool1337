/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:28 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/12 21:43:30 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_ATOI_NO_LIMIT 1337
# define INIT_FIRST_LINE_SIZE 0xff
# define READ_LINE_CHUNK_SIZE 0xff

typedef struct _row_disciptor
{
	char				*buffer;
}						t_row_disciptor;

typedef struct _map_coordinates
{
	unsigned int		y;
	unsigned int		x;
	int					boxes;
}						t_map_coordinates;

typedef struct _map_info
{
	int					fd;
	char				*filename;
	char				empty;
	char				obstacle;
	char				full;
	unsigned int		header_length;
	unsigned int		y;
	unsigned int		x;
	int					no_obstacles;
	int					check_edges;
	char				*map_body;
	int					*cache;
	t_row_disciptor		*first_row;
	t_map_coordinates	*solution_coordinates;
}						t_map_info;

int						ft_atoi(char *str, int limit);
int						get_first_line(t_map_info *map);
int						validate_map(t_map_info *map);
int						min(int a, int b, int c);
int						ft_strlen(char *str);
void					copy_buffer(void *dest, void *src, unsigned int size);
void					handle_map_file(char *map_filename);
void					handle_map_from_stdin(void);
t_map_info				*load_map(char *map_filename, int fd);
int						read_map_header(t_map_info *map);
void					free_map(t_map_info *map);
int						validate_map(t_map_info *map);
int						is_printable_char(char c);
void					solve_map(t_map_info *map);
void					print_solution_map(t_map_info *map);
int						read_map_header(t_map_info *map);
void					no_obstacle_map_print(t_map_info *map);
void					single_row_map_print(t_map_info *map);
void					solved_map_print(t_map_info *map);
void					zero_out_buffer(void *buffer, unsigned int size);
unsigned int			read_max(int fd, char *buffer, unsigned int max);
void					copy_and_translate_map_row(int *cache_line,
							char *map_body_line,
							int width,
							char obstacle);
int						ft_get_char(int fd);
#endif
