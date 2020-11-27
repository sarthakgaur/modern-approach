#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dialing_code {
    char *country;
    int code;
};

bool in_database(const struct dialing_code *cc, int size, int code, char **cn);

int main(void) {
    const struct dialing_code country_codes[] = {
        {"Argentina", 54},            {"Bangladesh", 880},
        {"Brazil", 55},               {"Burma (Myanmar)", 95},
        {"China", 86},                {"Colombia", 57},
        {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
        {"Ethiopia", 251},            {"France", 33},
        {"Germany", 49},              {"India", 91},
        {"Indonesia", 62},            {"Iran", 98},
        {"Italy", 39},                {"Japan", 81},
        {"Mexico", 52},               {"Nigeria", 234},
        {"Pakistan", 92},             {"Philippines", 63},
        {"Poland", 48},               {"Russia", 7},
        {"South Africa", 27},         {"South Korea", 82},
        {"Spain", 34},                {"Sudan", 249},
        {"Thailand", 66},             {"Turkey", 90},
        {"Ukraine", 380},             {"United Kingdom", 44},
        {"United States", 1},         {"Vietnam", 84}
    };

    int country_codes_len = (int) (sizeof(country_codes) / sizeof(country_codes[0]));
    int code;
    bool found;
    char **country_name;

    while (true) {
        printf("Enter country code: ");
        scanf("%d", &code);

        if (code == 0)
            exit(EXIT_SUCCESS);
        else {
            found = in_database(country_codes, country_codes_len, code, country_name);

            if (found)
                printf("Country name: %s\n", *country_name);
            else
                printf("Error: Country Code not found in database.\n");
        }
    }

}

bool in_database(const struct dialing_code *country_codes, int size, int code, char **country_name) {
    while (country_codes < country_codes + size) {
        const struct dialing_code country_code = *country_codes;
        if (country_code.code == code) {
            *country_name = country_code.country;
            return true;
        }
        country_codes++;
    }

    return false;
}
