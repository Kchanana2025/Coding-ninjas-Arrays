// O(n)
// O(n)
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
                                            // NOOOOOO this is absolutely wrong firsly this is not the way to iterate in a map use iterator secondly unordered map mein koi bhi key value pair kabhi bhi aa skta hai kuch bhi ordered nai hota toh wo waali cheez ki agar same frequency hai toh chote wale ka max frequency hoga will not hold true
    {                                       // to do it rightly use ordered map and iterate in ordered map through iterator done in max_frequency_1

        if (maxFreq < output[arr[i]])
        {
            maxFreq = output[arr[i]];
            element = arr[i];
        }
    }
    return element;
}
