#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 100

void read_line(char *buffer, int size);
void print_locale_info(const char *locale);

int main(void) {
    char str[SIZE];

    printf("Enter locale name: ");
    read_line(str, SIZE - 1);
    print_locale_info(str);

    return 0;
}

void read_line(char *buffer, int size) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < size)
            buffer[i++] = ch;

    buffer[i] = '\0';
}

void print_locale_info(const char *locale) {
    char *cp;
    struct lconv *lconv_p;

    cp = setlocale(LC_ALL, locale);
    if (cp == NULL) {
        printf("Locale name not valid.\n");
        exit(EXIT_FAILURE);
    }

    lconv_p = localeconv();

    printf("decimal_point = \"%s\"\n",     lconv_p->decimal_point);
    printf("thousands_sep = \"%s\"\n",     lconv_p->thousands_sep);
    printf("grouping = %s\n",              lconv_p->grouping);
    printf("mon_decimal_point = \"%s\"\n", lconv_p->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", lconv_p->mon_thousands_sep);
    printf("mon_grouping = %s\n",          lconv_p->mon_grouping);
    printf("positive_sign = \"%s\"\n",     lconv_p->positive_sign);
    printf("negative_sign = \"%s\"\n",     lconv_p->negative_sign);
    printf("currency_symbol = \"%s\"\n",   lconv_p->currency_symbol);
    printf("frac_digits = %d\n",           lconv_p->frac_digits);
    printf("p_cs_precedes = %d\n",         lconv_p->p_cs_precedes);
    printf("n_cs_precedes = %d\n",         lconv_p->n_cs_precedes);
    printf("p_sep_by_space = %d\n",        lconv_p->p_sep_by_space);
    printf("n_sep_by_space = %d\n",        lconv_p->n_sep_by_space);
    printf("p_sign_posn = %d\n",           lconv_p->p_sign_posn);
    printf("n_sign_posn = %d\n",           lconv_p->n_sign_posn);
    printf("int_curr_symbol = \"%s\"\n",   lconv_p->int_curr_symbol);
    printf("int_frac_digits = %d\n",       lconv_p->int_frac_digits);
    printf("int_p_cs_precedes = %d\n",     lconv_p->int_p_cs_precedes);
    printf("int_n_cs_precedes = %d\n",     lconv_p->int_n_cs_precedes);
    printf("int_p_sep_by_space = %d\n",    lconv_p->int_p_sep_by_space);
    printf("int_n_sep_by_space = %d\n",    lconv_p->int_n_sep_by_space);
    printf("int_p_sign_posn = %d\n",       lconv_p->int_p_sign_posn);
    printf("int_n_sign_posn = %d\n",       lconv_p->int_n_sign_posn);
}

