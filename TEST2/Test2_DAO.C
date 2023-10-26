#include <stdio.h>
#include <string.h>

void reverseWords(char* start, char* end) 
{
    char temp;
    while (start < end) 
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseString(char* str) 
{
    char* wordStart = str;
    char* wordEnd = str;

    while (*wordEnd) 
    {
        wordEnd++;
        if (*wordEnd == ' ' || *wordEnd == '\0') {
            reverseWords(wordStart, wordEnd - 1);
            wordStart = wordEnd + 1;
        }
    }

    reverseWords(str, wordEnd - 1);
}

int main() 
{
    char string[] = "anh thai bao bao anh nam bao thai linh";
    reverseString(string);
    printf("%s\n", string);

    return 0;
}
