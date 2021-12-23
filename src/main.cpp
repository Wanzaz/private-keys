#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "sha1.h"  /** <- FAKE BIPS39 hash public key **/

using namespace std;

string words[] = { "akce","bambus","blud","dnes","hmat","lump","mzda","ocel","revma","sysel","zmar","zubr" };

/**
vyuzito odkaz: http://www.zedwood.com/article/cpp-sha1-function
        odkaz: https://github.com/bitcoin/bips/blob/master/bip-0039/czech.txt

Seznam slov:
1 akce
2 bambus
3 blud
4 dnes
5 hmat
6 lump
7 mzda
8 ocel
9 revma
10 sysel
11 zmar
12 zubr

Naplnte seznam cisly 1 - 12 (zadne cislo se neopakuje) a predejte funkci VypoctiHash(seznam), ktera vraci hash = string (pole znaku).
Hledejte tak dlouho, dokud nenajdete odpovidajici hash, az jej najdete, nasli jste spravne poradi slov.

**/

string VypoctiHash(int seznam[]);
bool next_permutation(int* array, int length);
void reverse(int* array, int length);
void swap(int* c1, int* c2);
void print_arr(int arr[], int length);


int main(int argc, char* argv[])
{
    const int length = 12;
    int seznam[length];
    string hashHledany = "d99fa327540d376faf85ffb64bfe95c0191a428f";

    seznam[0] = 1;
    seznam[1] = 2;
    seznam[2] = 3;
    seznam[3] = 4;
    seznam[4] = 5;
    seznam[5] = 6;
    seznam[6] = 7;
    seznam[7] = 8;
    seznam[8] = 9;
    seznam[9] = 10;
    seznam[10] = 11;
    seznam[11] = 12;

    /*seznam[0] = 11;
    seznam[1] = 12;
    seznam[2] = 9;
    seznam[3] = 10;
    seznam[4] = 4;
    seznam[5] = 1;
    seznam[6] = 5;
    seznam[7] = 8;
    seznam[8] = 2;
    seznam[9] = 3;
    seznam[10] = 7;
    seznam[11] = 6;
    
    resolution for slower pcs to be able to test it by themselves
    */


    int i = 0;
    do
    {
        if (hashHledany == VypoctiHash(seznam))
        {
            printf("yay!\n");
            break;
        }
        if (i % 4790016 == 0)
            cout << i / 4790016 << "%" << endl;
        i++;
    } while (next_permutation(seznam, length));

    if (hashHledany != VypoctiHash(seznam))
        printf("Smula\n");
    else {
        print_arr(seznam, length); // 11 12 9 10 4 1 5 8 2 3 7 6
    }

    return 0;
}

void print_arr(int arr[], int length)
{
    printf("Seznam je: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

string VypoctiHash(int seznam[]) {

    std::string SpojeniSlov = words[seznam[0] - 1];

    for (int i = 1; i < 12; i++)
        SpojeniSlov.append(words[seznam[i] - 1]);

    return sha1(SpojeniSlov);
}

bool next_permutation(int* array, int length)
{
    // find pivot
    int pivot;
    for (pivot = length - 1; pivot > 0 && array[pivot - 1] > array[pivot]; pivot--);
    pivot--;

    // if there is no pivot, the array is already in its last permutation
    if (pivot < 0)
        return false;

    // find the 'smallest value larger than pivot' (svltp) to the right of pivot (there will always be at leas one)
    int svltp;
    for (svltp = length - 1; array[svltp] < array[pivot]; svltp--);

    // swap pivot and svltp
    swap(&array[pivot], &array[svltp]);

    // reverse everything to the right of pivot
    reverse(&array[pivot + 1], length - pivot - 1);

    return true;
}

void reverse(int* array, int length)
{
    int lim = length / 2;
    for (int i = 0; i < lim; i++)
        swap(&array[i], &array[length - 1 - i]);
}

void swap(int* c1, int* c2)
{
    char h = *c1;
    *c1 = *c2;
    *c2 = h;
}

