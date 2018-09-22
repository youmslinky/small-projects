#include <iostream>
#include <sstream>
using namespace std;

string pattern(int n)
{
	if(n==1){
		return "1";
	}
	else if(n>0){
		stringstream outString;
		
		for(int i=0;i<n;i++){

			for(int s=n-i-2;s>=0;s--){		//spaces
				outString << noskipws << ".";
			}
			int m = 1;
			for(int j=0;j<i+1;j++){
				outString << m++ % 10;
			}
			m -= 2;
			for(int j=0;j<i;j++){
				outString << m-- % 10;
			}
			for(int s=n-i-2;s>=0;s--){		//spaces
				outString << noskipws << ".";
			}
			if(i<n-1)
				outString << "n";
		}
		return outString.str();
	}
    return "";
}

int main(){
	cout << noskipws << pattern(4);
	return 0;
}

/*
   1   
  121  
 12321 
1234321


   1   
  121  
 12321 
1234321


   1   
  121  
 12321 
1234321
*/
//   1   \n  121  \n 12321 \n1234321