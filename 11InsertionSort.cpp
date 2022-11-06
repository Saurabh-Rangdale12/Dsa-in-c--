// big o notion worst case -> n^2 in best case -> n
#include <bits/stdc++.h>
using namespace std;

void printSort(int *A, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

void insertionSort(int *A, int n)
{ // LOOP for Passes!!!
    int key, j, temp;
    for (int i = 1; i <= n - 1; i++)
    {
       // Loop for each pass
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void insertion(vector<int> nums)
{
    int i, key, j;
    vector<int> temp;
    for (i = nums.size() - 2; i >= 0; i--)
    {
        key = nums[i];
        j = i + 1;
        while (j < nums.size() && nums[j] < key)
        {
            nums[j - 1] = nums[j];
            j = j + 1;
        }
        nums[j - 1] = key;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    int A[] = {34, 45, 33, 23, 56, 76};
    int n = 6;
    vector<int> nums = {34, 56, 32, 54, 74, 22};
    insertion(nums);

    cout << endl;
    insertionSort(A, n);
    printSort(A, n);
    return 0;
}