//) Develop a Menu driven program to demonstrate the following operations of Arrays
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.SEARCH
// 6.EXIT
// I NEED TO CHECK SOLUTIONS KI KOI CHEZ MISS OUT TOH NAI KI
#include <iostream>
using namespace std;
int delete_num(int arr[], int n) // delete is inbuilt keyword
{
    int i;
    int j;
    if (n == 0)
    {
        cout << "ELEMENT CANT BE DELETED";
    }
    cout << "ENTER THE INDEX AT WHICH YOU WISH TO DELETE THE ELEMENT";
    cin >> j;
    for (int i = j; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int create(int arr[]) // POPULATING THE ARRAY
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return n;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int insert(int arr[30], int n)
{
    int j;
    int flag = 0;
    int i, val;
    // if(n==0)
    cout << "ENTER THE POSITION AT WHICH YOU WANT TO INSERT ELEMENT";
    cin >> j;
    cin >> val;
    for (i = n - 1; i >= j; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[j] = val;
    return n + 1;
}
void search(int *arr, int n)
{
    int m, i;
    int flag = 0;
    cout << "Enter element you wish to search";
    cin >> m;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Element is presnt at " << i << " th "
             << "index";
    else
        cout << "element not present";
}

int main()
{
    int arr[30];
    int a;
    int n;
    char ch;
    do
    {

        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.SEARCH" << endl;
        cout << "6.EXIT" << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            n = create(arr);
            break; // hm break lgate hai because break na lgane pr neeche ke sare cases execute ho jate hain
        case 2:
            display(arr, n);
            break;

        case 3:
            n = insert(arr, n);
            break;
        case 4:
            n = delete_num(arr, n);
            break;
        case 5:
            search(arr, n);
            break;
        case 6:
            exit(0); // this is how we use exit it is used to terminate the program
        default:
            //  The default and break are optional in the switch in C++.
            cout << "wrong choice entered";
        }
        cout << endl;
        cout << "do you wish to continue" << endl;
        cin >> ch;
        cout << endl;
    } while (ch != 'n'); // while ke baad semicolon aata hai
    return 0;
}