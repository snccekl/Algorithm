#include <bits/stdc++.h>
using namespace std;


#include<iostream>  
using namespace std;  
int main()  {  
    int n;
    int a,b,c,d,e,f,g,h,i,j,ans=0;  
    cin>>n;  
    for (a=1;a<=3;a++) {  
        for (b=1;b<=3;b++)  {  
            for (c=1;c<=3;c++)  {  
                for (d=1;d<=3;d++)  {  
                    for (e=1;e<=3;e++)  {  
                        for (f=1;f<=3;f++)  
                        {  
                            for (g=1;g<=3;g++)  
                            {  
                                for(h=1;h<=3;h++)  
                                {  
                                    for (i=1;i<=3;i++)  
                                    {  
                                        for (j=1;j<=3;j++)  
                                        {  
                                            if (a+b+c+d+e+f+g+h+i+j == n)  
                                            {  
                                                ans++;  
                                            }  
                                        }  
                                    }  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    cout<<ans<<endl;  
    for (a=1;a<=3;a++)  
    {  
        for (b=1;b<=3;b++)  
        {  
            for (c=1;c<=3;c++)  
            {  
                for (d=1;d<=3;d++)  
                {  
                    for (e=1;e<=3;e++)  
                    {  
                        for (f=1;f<=3;f++)  
                        {  
                            for (g=1;g<=3;g++)  
                            {  
                                for(h=1;h<=3;h++)  
                                {  
                                    for (i=1;i<=3;i++)  
                                    {  
                                        for (j=1;j<=3;j++)  
                                        {  
                                            if (a+b+c+d+e+f+g+h+i+j==n)  
                                            {  
                                                cout<<a<<" ";  
                                                cout<<b<<" ";  
                                                cout<<c<<" ";  
                                                cout<<d<<" ";  
                                                cout<<e<<" ";  
                                                cout<<f<<" ";  
                                                cout<<g<<" ";  
                                                cout<<h<<" ";  
                                                cout<<i<<" ";  
                                                cout<<j<<endl;  
                                            }  
                                        }  
                                    }  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
    }  
    return 0;
}  