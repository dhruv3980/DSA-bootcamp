#include <iostream>
#include <vector>
using namespace std;
void inplacemerge(vector<int> &v, int start, int end)
{
    int total_len = end - start + 1;

    // how to calc ceil

    int gap = total_len / 2 + total_len % 2;

    while (gap > 0)
    {
        int i = start;
        int j = start + gap;
        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
                
                
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : gap / 2 + gap % 2;
    }
}
void mergesort(vector<int> &v, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start < end)
    {
        mergesort(v, start, mid);
        mergesort(v, mid + 1, end);
        inplacemerge(v, start, end);
    }
}
int main()
{
    vector<int> v{5, 14, 3, 2, 1, 0};

    mergesort(v, 0, 5);
    for (int i : v)
    {
        cout << i << " ";
    }
}