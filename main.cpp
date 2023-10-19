#include <iostream>
#include <cstdlib>

void Bin2Dec();

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    Bin2Dec();
}