// Alexis Muñoz
// 17 December 2015
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <fstream>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void checkElf(string ary[][C], ofstream& A_out);

int main()
{
	ifstream fin;
	fin.open("northpole.txt");
	
	ofstream fout;
	fout.open("status.txt");

	string christmas[R][C];
	
	fillArray(fin, christmas);

	checkElf(christmas, fout);
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string temp;
	for (int ix = 0; ix < R; ix++){
		
		for (int i = 0; i < C; i++){
			A_in >> temp;
			S[ix][i] = temp; 
		}
	
	}
	
	return;
}//end fillArray
void checkElf(string ary[][C], ofstream& A_out){
	
	int count = 0;
	for (int i = 1; i < (R-1); i++){
		
		for (int ix = 1; ix < (C-1); ix++){
			if ( ary[i][ix] == "@"){
				if ( (ary[i - 1][ix] == "!") ){
					count++;
				}
				if ( (ary[i + 1][ix] == "!") ){
					count++;
				}
				if ( (ary[i][ix - 1] == "!") ){
					count++;
				}
				if ( (ary[i][ix + 1] == "!") ) {
					count++;
				}
//***************WRITING TO FILE************
				if (count == 3){
					A_out << "Elf[" << i << "] [" << ix <<"]: Run!" << endl;
				}
				if (count == 4){
					A_out << "Elf[" << i << "] [" << ix <<"]: Munch!" << endl;
				}
				count = 0;
			}
		}	
	}
	return;
}
