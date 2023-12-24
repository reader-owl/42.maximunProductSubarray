#include <iostream>

/*
                    Q. maximum product subarray

                explanation -  we will be given an array -  arr[] = {2, 3, -2, 4} and we have to find the subarray
                                which gives the maximum product, here the answer is '6' whih we get by (2, 3)

        Brute force -  we will be generating all the subarrays
                        for that we stand in an element and iterate through whole array, then we stand in the next 
                        element and iterate through whole array

    pseudo code
maxi = INT_MIN
for(i=0->n)
{
    for(j=i->n)
    {
        product = 1;
        for(k=i->j)
        {
            produt = product * arr[k]
        }
        maxi = max(maxi, product)
    }
}

        TC - O(N^3)             // nearly
        SC - O(1)


            Better sol -  we don't 'k', when we stand as 'i' and iterate as 'j' we can just multiply as we iterate.

        pseudo code
maxi = INT_MIN
for(i=0;i<n;i++)
{
    product = 1;
    for(j=i;j<n;j++)
    {
        product = product * arr[j];
        maxi = max(maxi, product);
    }
}

        TC - O(N^2)
        SC - O(1)


            Optimal sol -  there are 2 types of optimal solution
                            1. observation based                    // will be using this
                            2. Kadane's (modified)                      // do not use this

                1.  observation based -  there are some cases for an array which we have to consider
                                            a) all the elements are positive
                                            b) even negative and rest positive
                                            c) odd negative and rest positive
                                            d) has Zeroes in it

                                    arr[] = {2, 3, -2, 4}
        pseudo code
prefix = 1, suffix = 1;
for(i=0->n-1)
{
    if(prefix == 0)
        prefix = 1;
    if(suffix == 0)
        suffix = 1;

    prefix = prefix * arr[i]
    suffix = suffix * arr[n-i-1]
    maxi = max(maxi, max(prefix, suffix));
}
return maxi;


        Actual code
int subarrayWithMaxProduct(vector<int> &arr)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        if(pre == 0)
            pre = 1;
        if(suff == 0)
            suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

        TC - O(N)
        SC - O(1)
*/

int main()
{
    std::cout << "Hello World!\n";
}