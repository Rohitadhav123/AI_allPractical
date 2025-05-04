#include<iostream>
using namespace std;

void selection(int n, int array[])
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
                swap(array[i], array[minIndex]);
            }
        }
       
    }
}

void display(int n, int arr[])
{
    cout << "The sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int array[size];
    cout << "Enter the array elements: " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    selection(size, array);
    display(size, array);
    return 0;
}
