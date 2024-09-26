
#include <iostream>
using namespace std;

int trap(int *heights , int n)
{
    int leftmax[20000];
    leftmax[0]=heights[0];
    for(int i=1 ; i<n ; i++)
    {
        leftmax[i] = max(leftmax[i-1],heights[i-1]);
            // cout<<"left max = "<<leftmax[i]<<endl;
    }
    int rightmax[20000];
     rightmax[n-1]=heights[n-1];
     for(int i = n-2 ; i>=0 ; i--)
     {
        rightmax[i]= max(rightmax[i+1],heights[i+1]);
        // cout<<rightmax[i]<<",";
     }

     int watertrapped = 0;
     for(int i=0 ; i<n ;i++)
     {
        int currwater = min(rightmax[i],leftmax[i]) - heights[i];
        if (currwater>0)
        {
            watertrapped += currwater;
        }
        
     }
    cout<<"water trapped in the bars ="<<watertrapped<<endl;
    return watertrapped ;
}

int main()
{
    int heights[7]={5,2,0,6,3,2,5};
    int n  = sizeof(heights)/sizeof(int);

    trap(heights , n);
    return 0;
}
