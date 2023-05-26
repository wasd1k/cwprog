#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50

struct text_info{
	int word;
	int symb;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: calcFrequency input_file output_file\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: unable to open input file\n");
        return 1;
    }
    
    struct text_info text_info;
    text_info.word = 0;
    text_info.symb = 0;
    
    char word[MAX_WORD_LEN];
    
    while (fscanf(input, "%s", word) != EOF){
    	text_info.word++;
    	if(word[0] <= 'z' && word[0] >= 'A')
    		text_info.symb += strlen(word);
    	else text_info.symb += strlen(word) / 2 + strlen(word) % 2;
    	if(fgetc(input) == ' ') text_info.symb++;
    }
    
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: unable to open output file\n");
        return 1;
    }
	
    fprintf(output, "Количество слов: %d\nКоличество символов: %d\n", text_info.word, text_info.symb);

    
    fclose(input);
    fclose(output);

    return 0;
}

