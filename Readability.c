#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int count_letter = 0;  //declare an int to count number of letters
    int count_word = 1;     //declare an int to count number of words
    int count_sentence = 0;  //declare an int to count number of sentences
    string text = get_string("Text: ");  //Getting Text  from user

    int text_length = strlen(text);         //to check the length of the text
    for (int i = 0; i < text_length; i++)   //iterate through the length of the text
    {
        if(isalpha(text[i]))    //check if the text is an Alphabeth
        {
            count_letter++;   //Then count the number of  alphabeth in the text
        }
    }
    //printf("%i\n", count_letter);     i use this to check if the number of letter is correct
    for (int i = 0; i < text_length; i++)  //iterate through the length of the text
    {
        if (isspace(text[i]))      // to Check if there is space
        {
            count_word++;    //to count the number of space as words
        }
    }
    //printf("%i\n", count_word);   i use this to check if the number of words is correct
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') // to check if character in text have '.', '?' and '!'
        {
            count_sentence++; //then count the number of the above character if found
        }
    }
    //printf("%i\n", count_sentence);  //to check if the number of sentence is correct

    //index = 0.0588 * L - 0.296 * S - 15.8 //

    float calculation = (0.0588 * count_letter / count_word * 100) - (0.296 * count_sentence / count_word * 100) - 15.8; // to calculate Index
    int index = round(calculation);  //then round up the Index
    if (index < 1)    //
    {
        printf("Before Grade 1\n");   //if index is less than 1, print 'Before Grade 1'
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");  //if index is greater than 16, print 'Grade 16+'
    }
    else
    {
        printf("Grade %i\n", index); //else if index is any other digit, print Grade index(digit)
    }
}
