#include <iostream>
using namespace std;

bool isValid(char a[9][9]) {
  for (int i = 0; i < 9; ++i) {
    bool row[10]={false}, col[10]={false};
    
    //hang va cot
    for (int j = 0; j<9; ++j) {
      if(a[i][j] !='.'){
        int num = a[i][j] - '0';//chuyen string sang integer
        if(row[num])
          return false;
        row[num]= true;
      }
      
      if(a[j][i] !='.'){
        int num = a[j][i] - '0';//chuyen string sang integer
        if(col[num])
          return false;
        col[num]= true;
      }
    }
  }
    
  //3x3
  for(int i = 0; i < 9; ++i){
    bool mark[10] = {false};
    int rowIdx = (i/3)*3;
    int colIdx = (i%3)*3;
    for(int j = 0; j<3; ++j){
      for(int k=0; k<3; ++k){
        char c = a[rowIdx + j][colIdx + k];
        if(c != '.'){
          int num = c - '0';
          if(mark[num])
            return false;
          mark[num]= true;
        }
      }
    }
  }
  return true;
}


int main() {
    int test_cases;
    cin>>test_cases;
    for(int T=1; T<=test_cases; T++){
          char source[9][9];
      for (int i = 0; i <9; ++i)
          for (int j = 0; j < 9; ++j) 
              cin>>source[i][j];
      cout<<"#"<<T<<" "<< (isValid(source)?1:0)<<endl;
    }
    return 0;
}