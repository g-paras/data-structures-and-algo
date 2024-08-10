#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr);

    for (auto i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}