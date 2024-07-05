/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Some desc
*/

#define ABS(value) (value * value)

static char *reeee(float en, float fr, float gr, float sp);

float ENGLISH[26] = {8.16, 1.49, 2.78, 4.25, 12.70, 2.22, 2.01, 6.09,
    6.96, 0.15, 0.77, 4.02, 2.40, 6.74, 7.50, 1.92, 0.09, 5.98, 6.32,
    9.05, 2.75, 0.97, 2.36, 0.15, 1.97, 0.07};
float FRENCH[26] = {7.63, 0.90, 3.26, 3.66, 14.71, 1.06, 0.86, 0.73,
    7.52, 0.61, 0.07, 5.45, 2.96, 7.09, 5.79, 2.52, 1.36, 6.69, 7.94,
    7.24, 6.31, 1.83, 0.04, 0.42, 0.12, 0.33};
float GERMAN[26] = {6.51, 1.88, 2.73, 5.07, 16.39, 1.65, 3.00, 4.57,
    6.55, 0.26, 1.41, 3.43, 2.53, 9.77, 2.59, 0.67, 0.01, 7.00, 7.27,
    6.15, 4.16, 0.84, 1.92, 0.03, 0.03, 1.13};
float SPANISH[26] = {11.52, 2.21, 4.01, 5.01, 12.18, 0.69, 1.76, 0.70,
    6.24, 0.49, 0.01, 4.96, 3.15, 6.71, 8.68, 2.51, 0.87, 6.87, 7.97,
    4.63, 2.92, 1.13, 0.01, 0.21, 1.00, 0.47};

char *get_language(float *percentage, char *to_display)
{
    float en = 0;
    float fr = 0;
    float gr = 0;
    float sp = 0;

    for (int i = 0; to_display[i] != '\0'; i++) {
        int index = my_charlowcase(to_display[i]) - 97;
        en += ABS(ENGLISH[index] - percentage[index]) / percentage[index];
    }
    for (int i = 0; to_display[i] != '\0'; i++) {
        int index = my_charlowcase(to_display[i]) - 97;
        fr += ABS(FRENCH[index] - percentage[index]) / percentage[index];
    }
    for (int i = 0; to_display[i] != '\0'; i++) {
        int index = my_charlowcase(to_display[i]) - 97;
        gr += ABS(GERMAN[index] - percentage[index]) / percentage[index];
    }
    for (int i = 0; to_display[i] != '\0'; i++) {
        int index = my_charlowcase(to_display[i]) - 97;
        sp += ABS(SPANISH[index] - percentage[index]) / percentage[index];
    }
    return (reeee(en, fr, gr, sp));
}

static char *reeee(float en, float fr, float gr, float sp)
{
    if (en <= fr && en <= gr && en <= sp)
        return ("English");
    else if (fr <= en && fr <= gr && fr <= sp)
        return ("French");
    else if (gr <= fr && gr <= en && gr <= sp)
        return ("German");
    return ("Spanish");
}