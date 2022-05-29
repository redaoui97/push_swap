/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:27:24 by rnabil            #+#    #+#             */
/*   Updated: 2022/05/20 23:28:20 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef MAX_FD
#define MAX_FD 65535
#endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct nodes
{
	int position;
	int value;
	int lis;
	int bool_lis;
	int moves_count;
	struct nodes *previous;
	struct nodes *next;
	struct nodes *first;
	struct nodes *last;
} t_node;

int print_addresse(unsigned long int adr);
int ft_printf(const char *f, ...);
int print_nbr(int n);
int print_hex_lower(unsigned int nbr);
int print_hex_upper(unsigned int nbr);
int print_nbr_unsigned(unsigned int nbr);
int print_str(char *str);
int print_char(char chr);
void add_element(t_node **stack_a, int value);
void clear_elements(t_node **stack_a);
t_node *duplicate_node(t_node *old);
int list_size(t_node *stack_a);
t_node *new_node(int value);
void remove_element(t_node **stack_a);
void set_min_first(t_node **stack_a);
void show_elements(t_node *stack_a);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void ra(t_node **stack_a);
void rb(t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);
void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
long int ft_atoi(char *str);
int is_sorted(t_node **stack);
// t_node *get_min(t_node *stack);
void parsin(char *arg, t_node **stack_a);
void error(t_node **stack);
int is_num(char arg);
int ft_strcmp(char *s1, char *s2);
int non_int(char *arg);
char *get_next_line(int fd);
int check_newline(char *buff);
size_t ft_strlen(const char *s);
char *fix_text(char **str, int nl);
char *ft_substr(char const *s, unsigned int start, size_t len);
void *ft_calloc(size_t count, size_t size);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
char *fix_line_text(char **text, char **line, int new_line_position);
int init_function(char **text, char **buffer);
#endif
