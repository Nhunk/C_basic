#include <iostream>
using namespace std;

int main() {
    int a[100], n;
    int test_cases;
    for(test_cases = 0; test_cases<10; test_cases++){
        cin>>n;
        for(int i = 0; i<100; i++){
            cin >> a[i];
        }
        for(int i = 0; i< n - 1; i++){
            int minIdx = i;
            for(int j = i+1; j<n; j++){
                if(a[j] < a[minIdx])
                    minIdx = j;
            }
            swap(a[i], a[minIdx]);

        }
    }
    
    cout<<endl<<"#"<<n;
    for(int i = 0; i<100; i++){
        cout<<a[i];
    }

    return 0;
}