int is_just_b(char *str)
{
    for(int i = 0; str[i] != '\0';i ++){
        if (!(str[i] == 'B' || str[i] == '\n'))
            return(0);
   }
    return(1);
}
