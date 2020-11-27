/* Checks planet names */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_PLANETS 9

int search_planet(const char *planets[], int planets_len, const char *planet);

int main(int argc, char *argv[]) {
    int i, j, res;
    const char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                       "Saturn", "Uranus", "Neptune", "Pluto"};

    int planets_len = sizeof(planets) / sizeof(planets[0]);

    for (i = 1; i < argc; i++) {
        res = search_planet(planets, planets_len, argv[i]);

        if (res > 0)
            printf("%s is planet %d\n", argv[i], res);
        else
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

int search_planet(const char *planets[], int planets_len, const char *planet) {
    const char **pn, *p1, *p2;

    for (pn = planets; pn < planets + planets_len; pn++) {
       p1 = *pn;
       p2 = planet;


       if (strlen(p1) != strlen(p2)) continue;

       while (*p1) {
           if (toupper(*p1) != toupper(*p2))
               break;
           p1++, p2++;
       }

       if (*p1 == '\0') return pn - planets + 1;
    }

    return 0;
}
