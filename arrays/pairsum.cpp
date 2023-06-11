#include <iostream>
using namespace std;
int pairSum(int *arr, int size, int x)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        { // find duplicate mein i+1 likhne pr no of comparisons ghat rhe thee lekin yaha zrurui hai for eg a[i]=5 aur sum 10 banna hai toh 5+5=10 ho jayega toh wo usko (5,5)ko pair consider kr lega
            if (arr[i] + arr[j] == x)
            {
                counter++;
                // WRONG because iss se a[i] ka ek hi pair aa payega    //arr[i]=23456; //ispe kuch value likhdi ki ek pair 2 par hn count ho jaye like 2+8=10and 8+2=10; hmne basically ekinclusion ke baad nos hi change kr die ye sahi bhi h pr
                //   arr[j]=23456; //isko isliye nai kia kyunki kya upar wale ka sbse possible sum nikal lia na ussi ko cange kro kya pta arr[j] ka kisi aur ke sath sum ajae
            }
        }
    }

    return counter;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}