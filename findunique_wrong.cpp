// iss quesn mein ye approachnai lga skte find duplicate mein hi lga skte hain kyunki kisi bhi test case mein run hi ni hoga
//  kyunki picche wale element wo check hi ni krta agr phle repeat ho gaye ho
int findUnique(int *arr, int size)
{
    int j;
    for (int i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                break; // break breaks from peeche wala loop
        }
        if (j == size)
        {
            return arr[i];
        }
    }
}