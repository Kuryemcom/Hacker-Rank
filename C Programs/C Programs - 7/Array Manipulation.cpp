#include <cstdio>
#include <vector>

#define max(a, b) (a > b ? a : b)
using namespace std;

int main()
{
    int no_of_elements, no_of_operations;
    scanf("%d %d", &no_of_elements, &no_of_operations);

    vector <long long> starting(no_of_elements + 2, 0);
    while(no_of_operations--)
    {
        int left, right, k;
        scanf("%d %d %d", &left, &right, &k);

        starting[left] += k;
        starting[right + 1] -= k;
    }

    vector <long long> value(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        value[i] = value[i - 1] + starting[i];
    }

    long long maximum = 0;
    for(int i = 1; i <= no_of_elements; i++)
        maximum = max(maximum, value[i]);

    printf("%lld\n", maximum);

    return 0;
}

