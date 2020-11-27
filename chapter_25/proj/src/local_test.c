#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

int main(void) {
    struct lconv native_cont, c_cont, *lconv_p;
    bool same_locale = false;

    setlocale(LC_ALL, ""); // native
    lconv_p = localeconv();
    native_cont = *lconv_p; // copying struct

    setlocale(LC_ALL, NULL); // c
    lconv_p = localeconv(); 
    c_cont = *lconv_p; // copying struct

    if (
           native_cont.p_cs_precedes          == c_cont.p_cs_precedes
        && native_cont.n_cs_precedes          == c_cont.n_cs_precedes
        && native_cont.p_sep_by_space         == c_cont.p_sep_by_space
        && native_cont.n_sep_by_space         == c_cont.n_sep_by_space
        && native_cont.p_sign_posn            == c_cont.p_sign_posn
        && native_cont.n_sign_posn            == c_cont.n_sign_posn
        && native_cont.int_frac_digits        == c_cont.int_frac_digits
        && native_cont.int_p_cs_precedes      == c_cont.int_p_cs_precedes
        && native_cont.int_n_cs_precedes      == c_cont.int_n_cs_precedes
        && native_cont.int_p_sep_by_space     == c_cont.int_p_sep_by_space
        && native_cont.int_n_sep_by_space     == c_cont.int_n_sep_by_space
        && native_cont.int_p_sign_posn        == c_cont.int_p_sign_posn
        && native_cont.int_n_sign_posn        == c_cont.int_n_sign_posn
        && native_cont.frac_digits            == c_cont.frac_digits

        && strcmp(native_cont.decimal_point,     c_cont.decimal_point) == 0
        && strcmp(native_cont.thousands_sep,     c_cont.thousands_sep) == 0
        && strcmp(native_cont.grouping,          c_cont.grouping) == 0
        && strcmp(native_cont.mon_decimal_point, c_cont.mon_decimal_point) == 0
        && strcmp(native_cont.mon_thousands_sep, c_cont.mon_thousands_sep) == 0
        && strcmp(native_cont.mon_grouping,      c_cont.mon_grouping) == 0
        && strcmp(native_cont.positive_sign,     c_cont.positive_sign) == 0
        && strcmp(native_cont.negative_sign,     c_cont.negative_sign) == 0
        && strcmp(native_cont.currency_symbol,   c_cont.currency_symbol) == 0
        && strcmp(native_cont.int_curr_symbol,   c_cont.int_curr_symbol) == 0
    )
        same_locale = true;

    if (same_locale)
        printf("native locale is same as c locale\n");
    else
        printf("native locale is not same as c locale\n");
                                                        
    return 0;
}
