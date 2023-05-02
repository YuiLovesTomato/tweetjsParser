#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE* fp_in = fopen("tweets.js", "r");

    if (fp_in == NULL) {
        printf("Error: failed to open input file\n");
        return 1;
    }

    FILE* fp_out = fopen("tweets_extracted.js", "w");

    if (fp_out == NULL) {
        printf("Error: failed to open output file\n");
        fclose(fp_in);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
	char prev[MAX_LINE_LENGTH];
	char prev_prev[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp_in) != NULL) {
        if (strstr(line, "\"full_text\"") != NULL && strstr(line, "RT @")==NULL) {
			fputs(prev_prev, fp_out);
            fputs(line, fp_out);
			fputs("\n", fp_out);
        }
		strcpy(prev_prev, prev);
		strcpy(prev, line);
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
