#include <unordered_map>
#include <limits.h>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> output;
    for (int i = 0; i < n; i++)
        output[arr[i]]++;

    int maxFreq = INT_MIN;
    int element = 0;
    for (int i = 0; i < output.size(); i++) // very good approach : hamien ye check krne ki zarurat naipadhi ki agar do elements ki frequency same hai toh jo phle array mein aaya hoga wo print hoga
                                            // hmne seedha map se max print kr dia = wala condition hi check nai kia because jo array mein phla max aaya hoga wo map mein bhi  max  hoga.toh jab map mein mein iterate krenge toh sahi max hi ayega
    {

        if (maxFreq < output[arr[i]])
        {
            maxFreq = output[arr[i]];
            element = arr[i];
        }
    }
    return element;
}
