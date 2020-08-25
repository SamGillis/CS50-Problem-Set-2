#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // checks if there is an input
    if (argc == 2)
    {
        const int length = strlen(argv[1]);
        // error if only letters in key
        int n = 0;
        for (int i = 0; i + 1 < length; i++)
        {
            char c = argv[1][i];
            if (!isalpha(c))
            {
                printf("Key must only be letters\n");
                return 1;
            }
        }
        // checks if key is 26 letters
        if (length == 26)
        {
            //convert key to lowercase
            string key = argv[1];
            for (int r = 0; r < length; r++)
            {
                char d = key[r];
                if (isupper(d))
                {
                    key[r] = tolower(key[r]);
                }
            }
            //error if letters duplicated
            for (int doubles = 0; doubles + 1 < length; doubles++)
            {
                for (int y = doubles + 1; y < length; y++)
                {
                    if (key[doubles] == key[y])
                    {
                        printf("Key must not contain duplicate letters\n");
                        return 1;
                    }
                }
            }
            // prompts for plaintext
            string input = get_string("plaintext: ");
            string alph = "abcdefghijklmnopqrstuvwxyz";
            int v = strlen(input);
            //checks if input is upper or lower
            for (int t = 0; t < v; t++)
            {
                char z = input[t];
                //if upper convert to lower
                if (isupper(z))
                {
                    input[t] = tolower(input[t]);
                    //change to cipher text
                    for (int p = 0; p <= 25; p++)
                    {
                        if (input[t] == alph[p])
                        {
                            input[t] = key[p];
                            p = 26;
                        }
                    }
                    //convert back to upper
                    input[t] = toupper(input[t]);
                }
                //if lower
                else
                {
                    //convert to cipher text
                    for (int s = 0; s <= 25; s++)
                    {
                        if (input[t] == alph[s])
                        {
                            input[t] = key[s];
                            s = 26;
                        }
                    }
                }
            }
            //prints ciphertext
            printf("ciphertext: %s\n", input);
            return 0;
        }
        // error if key is not 26 letters
        else
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
    }
    //error if no key inputed
    else
    {
        printf("Usage ./substitution key\n");
        return 1;
    }
}
