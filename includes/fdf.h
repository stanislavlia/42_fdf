/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:52 by sliashko          #+#    #+#             */
/*   Updated: 2023/09/18 12:04:06 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;

}	t_vector;

typedef struct s_row
{
	int			y;
	t_vector	*values;


}	t_row;


typedef struct s_matrix
{
	t_row	*rows;
	int		m;
	int		n; //shape of the matrix

}	t_matrix;


int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);


t_list		*get_last_node(t_list *lst);
int			search_for_newline(t_list *list);
void		append_node(t_list **list, char *buffer_batch);
int			create_list(t_list **list, int fd);
size_t		len_till_nl(t_list	*start_node);
char		*get_next_line(int fd);
void		keep_rest(t_list **list);
void		free_list(t_list **list, t_list *clean_node, char *buffer);
char		*retrive_line(t_list	*list);
int			fill_line_from_content(char *line, int *i, char *content);

#endif