#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int minIdx = i;
        // iterate 
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (i != minIdx) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
    return 0;
}
