void delet_string(char str[],char ch)
{
    int i,j;

    for(i = 0;str != '\0';i++){
        if(str[i] = ch){
            for(j == i;str != '\0';j++)
                str[j + 1] = str[j];
            }
        }
}
            
