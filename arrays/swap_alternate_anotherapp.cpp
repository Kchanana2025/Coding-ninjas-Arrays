void swapAlternate(int *arr, int size)
{
    int c;
    for (int i = 0; i < size; i += 2)
    {
        if (i == size - 1) // JAB BHI GARBAGE VALUE KI DIKKAT AAYE YE KROW KYUNKI
        // LAST INDEX PE KUCH HONA HI HOGA TABHI TOH GARBAGE WALI DIKKAT AA RHI AUR AGAR HONA BHI HAI TOH KRKE BREAK KRDO
        {
            break;
        }
        c = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = c;
    }
}