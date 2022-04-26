/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototypes fct
*/

#ifndef _MY_H
    #define _MY_H

int error_handling_bsq(char *pathname);
int specific_case_bsq(int **map);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strdup(char const *src);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
int it_is_alphanumeric(char c);
int count_space_to_cut(char const *str, int i);
int count_len_alphanumeric(char const *str);
char *delete_non_alphanumeric_char(char const *str, char *str_alpha);
int count_len_of_word(char *str);
int count_number_of_word(char *str);
int nb_char_word(char *str);
char *cpy_nospace(char *dest, char *str_alpha);
int check_alpha(char to_check, char c);
int it_is_alpha(char c);
int it_is_num(char c);
char *find_smallest_str(char *str1, char *str2);
char *find_bigger_str(char *str1, char *str2);
char *fill_str_of0(char *dest, char *src, int size);
char *infin_sub(char *str1, char *str2, char *res);
int compare_str(char *str1, char *str2);
void clear_first0(char *str);
char *find_smallest_strm(char *str1, char *str2);
char *find_bigger_str_min(char *str1, char *str2);
int it_is_prio_sign(char c);
int it_is_a_sign(char c);
char *my_strncpy_rev(char *dest, char const *src, int n);
int is_there_parent_in_str(char *str, char sign);
char *my_strndup(char const *src, int start, int end);
int *find_first_parent_to_calc(char *src, int *pos_parent, char const *sign);
char find_pos_calc_and_sign(char *src, int *pos_my_calc, char const *sign);
char *do_my_op(char sign, int *pos_my_calc, char *res, char *src);
char *replace_op_by_res(char *src, char *res, int *pos_my_calc);
int there_is_op(char *str, char const *sign);
char *calc_my_str_withoutpar(char *my_calcp, char *res, char const *sign);
int where_is_sign(char *src, char const *sign);
char *fill_after_par(char *src, int pos_l_par, char *after_par);
char *fill_before_par(char *src, int pos_f_par, char *before_par);
char *my_strndup(char const *src, int start, int end);
int pos_start_nb1(char *src, int pos_op, char minus);
int pos_end_nb2(char *src, int pos_op, char minus);
char *fill_after_par(char *src, int pos_l_par, char *after_par);
char *fill_before_par(char *src, int pos_f_par, char *before_par);
char *my_infin_add(char *nb1, char *nb2, char *res);
int it_is_a_sign_bistro(char c, char const *s);
char find_my_sign(char c, char const *s);
int it_is_prio_sign_bistro(char c, char const *s);
char *eval_expr(char const *str, char const *sign, char *key_base);
char *add_minus_str(char *str);
void check_error_bistro(char *expr, char *base, char *ops);
int check_par(char *str, char open_par, char end);
int check_matching_parenthesis(char *str, char open_par, char end);
char *replace_minus(char *nb);
char *my_infin_modulo(char *nb1, char *nb2, char *res);
char *switch_my_char_int_str(char c, char replace, char *str);
char *decrypt_str_with_key(char *str, char *key);
char *encrypt_str_with_key(char *str, char *key);
char *delete_min_str(char *str);
char *my_true_infin_sub(char *nb1, char *nb2, char *res);
char *calc_infin_sub(char *res, char *nb1, char *nb2);
int find_str_minus_and_delete_min(char *str1, char *str2);
int two_same_nb(char *base);
char *my_infin_mult(char *nb1, char *nb2, char *res);
char *infin_mult_2pos(char *str1, char *str2, char *res);
char *mult_str_by_10(char *str, int time_m10);
void free_2str(char *str1, char *str2);
void clear_first0_let_one(char *str);
char *my_infin_div(char *num, char *div, char *res);
char *my_infin_modulo(char *num, char *div, char *res);
int par_sign(char *str, char *ops);
int bsq(char *pathname);
int print_array_char(char **array);
char **free_array_char(char **array);
int **free_array_int(int **array);
int print_array_int(int **array);
char **fill_my_map(char **map, char *pathname, int k);
int **fill_my_map_int(int **map, char *pathname);
int find_pos_start_map(char *str);
int print_array_char_jumpline(char **array);
char **copy_x(int i, int j, char **res, int size_square);
int replace_square_by_x(int **map, char **res, int i, int size_square);
int print_array_char_fast(char **array, int size);

#endif
