// O(2^n)
// O(n)
int countMinStepsToOne(int n)
{
    int x, y = INT_MAX, z = INT_MAX;
    // ye krna isliye zaruri hai because hr baar x,y,z ko ki value assign hogi hi ye zaruri nai hai because hr no toh 2,3 dono se divisible nai hota so we need to make sure that jiski value hi calculate nai hui lets say /3 ki wo toh minimum calculate krte smay include na hi ho isliye usko INT_MAX rakh dia
    //  base case
    if (n == 1)
    {
        return 0;
    }
    // recursive calls
    x = countMinStepsToOne(n - 1);

    if (n % 2 == 0)
    {
        y = countMinStepsToOne(n / 2);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsToOne(n / 3);
    }
    int ans = min(x, min(y, z));

    return ans + 1;
}