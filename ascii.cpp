#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ascii{
public:
	Ascii();
	char digit[7][5];
	int n;
	int parsing();
};
Ascii::Ascii() {
	n=0;
}
int Ascii::parsing() {
	//if n=-1, then this Ascii is + operator.
	if(digit[1][2]=='x'){//+
		n=-1;
	}
	if(digit[3][1]=='.'){//0,1,7
		if(digit[0][0]=='.')//1
			n=1;
		else if(digit[1][0]=='x')//0
			n=0;
		else
			n=7;
	}
	else{//2,3,4,5,6,8,9
		if(digit[6][0]=='.')//4
			n=4;
		else if(digit[1][4]=='x'&&digit[5][4]=='x')//3,8,9
		{
			if(digit[1][0]=='.')//3
				n=3;
			else if(digit[5][0]=='.')//9
				n=9;
			else//8
				n=8;
		}
		else{//2,5,6
			if(digit[5][4]=='.')//2
				n=2;
			else if(digit[5][0]=='.')//5
				n=5;
			else//6
				n=6;
		}
	}
	return n;
}
int main() {	
	int itr=0;
	int a[2];
	a[0]=0,a[1]=0;
	int b=0,m=1;
	string arr[7];
	int count=0;
	for(int i=0;i<7;i++){
		cin >> arr[i];
	}
	count = (arr[0].length()-1)/6;
	cout << count;
	Ascii* input = new Ascii[count];
	for(int k=0;k<7;k++){
		itr=0;
		for(int i=0;i<arr[k].length();i++){				
			int j=i+5;			
			while(i<j){
				input[itr].digit[k][i]=arr[k][i];							
				i++;			
			}
			itr++;			
		}		
	}
	for(int i=0;i<count;i++){
		cout << "parsed result: " << input[i].n;
		for(int k=0;k<7;k++){
			for(int j=0;j<5;j++){
				cout << input[i].digit[k][j];
			}
			cout <<endl;
		}	
		cout << endl;
	}
	
	for(int k=0;k<count;k++){
		cout << "parsing result: " << input[k].parsing() << endl;
			if(input[k].n==-1){//+ operator.
				b=1;m=1;					
			}
			else {
				a[b]*=m;
				a[b]+=input[k].n;
				m*=10;
			}
	}

	int result = a[0]+a[1];
	cout << "result" << " a=" << a[0] << ", b=" << a[1] << ", a+b=" << result;
	
	cout <<endl;
	delete[] input;
	input=NULL;
	return 0;
}