int is_just_star(char *str)
{
    for(int i = 0; str[i] != '\0';i ++){
        if (!(str[i] == '*' || str[i] == '\n'))
            return(0);
   }
    return(1);
}
