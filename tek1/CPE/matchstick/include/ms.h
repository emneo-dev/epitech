/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** ms
*/

#ifndef MS_H_
#define MS_H_

/////////////////////////////
// @brief Stores the map
//
// Stores the entire map and keep its total size
/////////////////////////////
typedef struct map_s{
    unsigned char size;
    unsigned char *match;
    long long int max_match;
} map_t;

/////////////////////////////
// @fn int matchstick(int ac, char **av)
// @brief Main function
//
// Gets and parses the given arguments and launch the game
// @param ac The number of given arguments
// @param av The array of given arguments
// @return 0 if successful, 84 if not
////////////////////////////
int matchstick(int ac, char **av);

/////////////////////////////
// @fn void display_map(map_t *map)
// @brief Display the map
//
// @param map The map of matchsticks
// @return Nothing, cannot fail
// @see map_t
/////////////////////////////
void display_map(map_t *map);

/////////////////////////////
// @fn map_t *get_map(char *arg)
// @brief Get map from file
//
// Gets the map of matchsticks with a given size
// @param size The size of the map
// @param max_match The max number of match you can take by turn
// @return A map_t with the initial map
// @see map_t
/////////////////////////////
map_t *get_map(char *size, char *max_match);

void destroy_map(map_t *map);
int handle_input(map_t *map);
int is_empty(map_t *map);
int game_loop(map_t *map);
void ai(map_t *map);
int entry_point(map_t *map);
void r_carriage(char *str);
int calculate_sum(map_t *map);

#endif /* !MS_H_ */