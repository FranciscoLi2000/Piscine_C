/* c_piscine.h
 * Auto-generated prototypes collected from C Piscine modules C00..C13
 * (contains typedefs used across exercises)
 */

#ifndef C_PISCINE_H
# define C_PISCINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

/* -------------------------
 *    Basic structs used by exercises
 *       ------------------------- */

/* linked list used in C12 */
typedef struct s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

/* binary tree used in C13 */
typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void		*item;
}	t_btree;

/* stock/str struct used in C08 (ft_strs_to_tab / ft_show_tab) */
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

/* simple point used in C08 ft_point.h */
typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

/* -------------------------
 *    C00: basic output / combos
 *       ------------------------- */
void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);
void	ft_print_combn(int n);

/* -------------------------
 *    C01: basic pointers / arrays
 *       ------------------------- */
void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

/* -------------------------
 *    C02: string utilities
 *       ------------------------- */
char		*ft_strcpy(char *dest, char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			ft_str_is_alpha(char *str);
int			ft_str_is_numeric(char *str);
int			ft_str_is_lowercase(char *str);
int			ft_str_is_uppercase(char *str);
int			ft_str_is_printable(char *str);
char		*ft_strupcase(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void		ft_putstr_non_printable(char *str);
void		ft_print_memory(void *addr, unsigned int size);

/* -------------------------
 *    C03: more string funcs
 *       ------------------------- */
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
char		*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

/* -------------------------
 *    C04: numbers & bases
 *       ------------------------- */
int		ft_strlen(char *str); /* duplicate prototype (kept for compatibility) */
void	ft_putstr(char *str); /* duplicate prototype (kept for compatibility) */
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi(char *str);
int		ft_atoi_base(char *str, char *base);

/* -------------------------
 *    C05: maths / recursion / puzzles
 *       ------------------------- */
int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

/* -------------------------
 *    C06: argv handling programs
 *       ------------------------- */
void	ft_print_program_name(char *name);
void	ft_print_params(int argc, char **argv);
void	ft_rev_params(int argc, char **argv);
void	ft_sort_params(int argc, char **argv);

/* -------------------------
 *    C07: strings / memory helpers
 *       ------------------------- */
char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		*ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	**ft_split(char *str, char *charset);

/* -------------------------
 *    C08: headers, ft_strs_to_tab / show_tab, points
 *       ------------------------- */
t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(t_stock_str *par);
/* plus small headers/constants like ft_boolean/ft_abs/ft_point (macros/types) */

/* -------------------------
 *    C10: file utilities (programs — no function prototypes required here)
 *       ------------------------- */
/* Exercises are programs: ft_display_file (program), ft_cat, ft_tail, ft_hexdump — */
int		ft_display_file_main(int argc, char **argv); /* helper stubs if needed */

/* -------------------------
 *    C11: functional helpers / string sort
 *       ------------------------- */
void	ft_foreach(int *tab, int length, void(*f)(int));
int		*ft_map(int *tab, int length, int(*f)(int));
int		ft_any(char **tab, int (*f)(char *));
int		ft_count_if(char **tab, int (*f)(char *));
int		ft_is_sort(int *tab, int length, int(*f)(int, int));
void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

/* -------------------------
 *    C12: singly linked list functions (t_list)
 *       ------------------------- */
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

/* -------------------------
 *    C13: binary tree functions (t_btree)
 *       ------------------------- */
t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
