#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int tc, T;
    	int n;
	
	cin >> T;
	for(tc = 1; tc <= T; tc++){		
        	cin>>n;
		int price[n];
        for(int i=0;i<n;++i) cin>>price[i];
		int max=0;
        	int profit=0;
        for (int i=n-1;i>=0;--i){
            if(price[i]>max) max=price[i];
            profit += max - price[i];
	}
        cout<< "#" << tc <<" "<< profit << endl;
}

	return 0;
}
