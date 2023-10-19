#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm> //std::fill_n
#include <cmath>

void swap(int *a, int *b);
int calculate_Bin2Dec(int *arr);

void Bin2Dec()
{
    bool check;
    char str[20]; // '\n'
    int temp;
    int binary[8];


    do
    {
        std::fill_n(str, 20, '\0'); // str still keep value of previous loop. [IMPORTANT]
        check = true;
        std::cout << "Enter binary nummber ( up to 8 digits only :) ): ";
        std::cin >> str;

        if (strlen(str) > 8) //Only up to 8 digits
            check = false;

        temp = std::atoi(str);

        for (int i = 0; i < 8; i++)
        {
            if (check == false) // if strlen(str) > 8 do this so don't have to go furthur, probably need to think of something better
            {
                std::cout << "Invalid.\n";
                break;
            }
            if (temp > 0)
            {
                binary[i] = temp % 10;
                temp /= 10;
                if (binary[i] != 0 && binary[i] != 1) // Binary number only contains 0 or 1;
                {
                    std::cout << "Invalid.\n";
                    check = false;
                    break;
                }
            }            
            else
                binary[i] = 0;
        }
    } while (!check); // so readable i love c++ :)...


    for (int i = 7, j = 0; i > j; i--, j++)
        swap(&binary[i], &binary[j]);
    for (int i = 0; i < 8; i++)
        std::cout << binary[i] << ' ';

    
    std::cout << '\n';

    int result = calculate_Bin2Dec(binary);
    std::cout << result << '\n';

    system("pause"); // this thing only works on Windows
}

int calculate_Bin2Dec(int *arr)
{
    int sum = 0;
    for (int i = 7, j = 0; i >= 0; i--, j++)
        if (arr[i] == 1)
            sum += (int)pow(2, j);
    return sum;
}