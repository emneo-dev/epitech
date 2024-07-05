/*
** EPITECH PROJECT, 2019
** rush2
** File description:
** Display the letter's frequencies
*/

void my_put_float(float nb);

float *display_letters(int frequencies[26], char *to_display, int nb_string,
                        float *percentage)
{
    for (int i = 0; to_display[i] != '\0'; i++) {
        my_putchar(to_display[i]);
        my_putchar(':');
        my_put_nbr(frequencies[my_charlowcase(to_display[i]) - 97]);
        my_putchar(' ');
        my_putchar('(');
        float frequencie =
                    (float)(frequencies[my_charlowcase(to_display[i]) - 97])
                    * (float)(100) / (float)(nb_string);
        percentage[my_charlowcase(to_display[i]) - 97] = frequencie;
        my_put_float(frequencie);
        my_putchar('%');
        my_putchar(')');
        my_putchar('\n');
    }
    return (percentage);
}