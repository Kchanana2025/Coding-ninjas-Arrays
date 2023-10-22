// O(n)
// O(n)+O(n)(call stack and array)
// memoization
// bss yehi krna hai memo mein mein ki recursive call krne se phle answer array mein check krlo ki agar wo answer present hai ya nai
// agar hai toh return krdo nai toh calculate kro phir save kro aur phir return kro
int countMinStepsToOne_helper(int n, int *output)
{
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    //  base case
    if (n == 1) // base case wali call i.e n=1 wali call save krni hai toh krlo array mein nai toh koi need nai hai.becayse jab bhi n=1 call hogi base case se return hi ho jayega.uske neeche wale if mein ghusne se phle (neeche wale if se hi output[1] ki value return hoti)
    {
        return 0;
    }
    if (output[n] != -1)
    {
        return output[n];
    }

    x = countMinStepsToOne_helper(n - 1, output);

    if (n % 2 == 0)
    {
        y = countMinStepsToOne_helper(n / 2, output);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsToOne_helper(n / 3, output);
    }
    int ans = min(x, min(y, z));
    output[n] = ans + 1;
    // cout<<output[n]<<" ";
    return output[n];
}
int countMinStepsToOne(int n)
{
    int *output = new int[n + 1]; // hm hemsha n+1 ka size lete hain taki indexes 0 to n hoien aur hm ith index pr ith fibbonaachi no rakh skien valid for all dp questions
    for (int i = 0; i <= n; i++)  // hm apne output array ko kisi bhi value se initially set kr skte thee provided wo value answer ka part nai honi chahie eg -1 kabhi bhi no of steps ke barabar nai ho skta
    {
        output[i] = -1;
    }
    return countMinStepsToOne_helper(n, output);
}
