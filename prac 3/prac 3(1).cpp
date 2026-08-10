#include<iostream>
using namespace std;
 intmain()
{
    int arr[]={8,5,1,3,7};
    int n=5;
    int i,j;
     for(i=0;i<4;i++)
     {
        for(j=0;j<4-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
               int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
     };
     cout<<"shorted array is : "<<endl;
     for(i=0;i<5;i++)
     {
        cout<<arr[i]<<endl;
     }
}
