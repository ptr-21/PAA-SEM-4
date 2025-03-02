#include<iostream>
#include<vector>
using namespace std;
struct minmax
{
    int minimum;
    int maximum;
};
minmax findminmax(const vector<int>& arr, int low, int high){
    minmax result, left, right;
    int mid;
    if (low == high)
    {
        result.minimum = arr[low];
        result.maximum = arr[low];
        return result;
    }
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.minimum = arr[low];
            result.maximum = arr[high];
        }
        else
        {
            result.minimum = arr[high];
            result.maximum = arr[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    left = findminmax(arr, low, mid);
    right = findminmax(arr, mid + 1, high);
    result.minimum = min(left.minimum, right.minimum);
    result.maximum = max(left.maximum, right.maximum);
    return result;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {7, 3, 9, 2, 11, 5};
    int n = arr.size();
    minmax result = findminmax(arr, 0, n - 1);
    cout << "Nilai Minimum: " << result.minimum << endl;
    cout << "Nilai Maksimum: " << result.maximum << endl;
    return 0;
}
