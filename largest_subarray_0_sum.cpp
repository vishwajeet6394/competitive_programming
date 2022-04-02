 #include<bits/stdc++.h>
 #include<iostream>
 using namespace std;
 int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxi=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum=sum+A[i];
            if(sum==0)
            {
                maxi=i+1;
            }
            else{
                if(mp.find(sum) != mp.end())
                  {
                      maxi=max(maxi,i-mp[sum]);
                  }
                  else 
                  mp[sum]=i;
            }
        }
        return maxi;
    }

     int main()
     {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            vector<int> v(n);
            for(int i=0; i<n; i++)
            {
                cin>>v[i];
            }
            cout<<maxLen(v,n)<<endl;
        } 
     }