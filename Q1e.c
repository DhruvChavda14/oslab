#include <stdio.h>
#include <string.h>

int main()
{
    char input[256];       
    char result[256] = ""; 
    char *word;            
    char separator = '-';  

    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    
    printf("Split words:\n");
    word = strtok(input, " ");
    while (word != NULL)
    {
        printf("%s\n", word);

    
        if (result[0] != '\0')
        {
            strncat(result, &separator, 1); 
        }
        strcat(result, word);

        word = strtok(NULL, " ");
    }

    
    printf("Joined string: %s\n", result);

    return 0;
}
