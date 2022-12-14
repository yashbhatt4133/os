#include <iostream>
#include <thread>
using namespace std;
int total_sum = 0, s = 1;
void sum(int *n)
{
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += n[i];
    }
    while (s == 0);
    s = 0;
    total_sum += ans;
    s = 1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 10, 20, 30, 40, 100, 200, 300, 400, 1000, 2000, 3000, 4000, 10000, 20000, 30000, 40000};
    int a[10];
    int b[10];
    for (int i = 0, j = 0; j < 20; i++, j += 2)
    {
        a[i] = arr[j];
        b[i] = arr[j + 1];
    }
    thread t1(sum, a);
    thread t2(sum, b);
    t1.join();
    t2.join();
    cout << "Sum = " << total_sum;
    return 0;
}