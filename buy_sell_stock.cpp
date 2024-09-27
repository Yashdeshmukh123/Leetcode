#include <iostream>
using namespace std;

void maxProfit(int *prices, int n)
{
    int bestbuy[100000];
    bestbuy[0] = INT32_MAX;

    for (int i = 1; i < n; i++)
    {
        bestbuy[i] = min(bestbuy[i - 1], prices[i - 1]);
    }

    int maxProfit = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        int currprofit = prices[i]- bestbuy[i];
        maxProfit = max(maxProfit , currprofit);
    }
    cout<<"maxprofit = "<<maxProfit<<endl;
}

int main()
{
    int prices[6] = {7,6,1,4,3,2};
    int n = sizeof(prices) / sizeof(int);

    maxProfit(prices, n);
    return 0;
}