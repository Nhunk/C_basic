#include<iostream>
using namespace std;

int main() {
    int a,b;
    int id;
    long long result = 1;
    while(cin>>id){
        cin>>a>>b;
        for(int i = 0; i < b; i++) {
            result *= a;
        }
        std::cout << "#" << id << ": " << result << std::endl;
    }
}