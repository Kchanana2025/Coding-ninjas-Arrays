#include <iostream>
#include <algorithm>
using namespace std;
// //code sahi hai but optimized nai hai

// void sortZeroesAndOne(int *input, int size){
//     int counter_1,counter_0;int i;
//     for( i=0;i<size;i++){
//         if(input[i]==1)
//         counter_1++;
//         else if(input[i]==0)
//         counter_0++;

//     }
//     for(i=0;i<counter_0;i++){
//         input[i]=0;
//     }
//     for(i=counter_0;i<size;i++){
//         input[i]=1;
//     }
// }

// BETTER CODE

void sortZeroesAndOne(int *input, int size)
{
	int start = 0;
	int end = size - 1;
	while (start <= end) // OR while(start<end)
	{
		if (input[start] == 1)
		{
			int temp = input[start];
			input[start] = input[end];
			input[end] = temp;
			end--; // hm basically 1 mila toh peeche fenko nai toh choro
		}
		else
			start++;
	}
}

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}