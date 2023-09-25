// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <Windows.h>

using namespace std;

int no_thing_do_func(){
	int exist = 0;
	if(MessageBoxW){
		exist = 1;
	}
	if(SetSecurityDescriptorOwner){
		exist = 1;
	}
	if(CreateFileA){
		exist = 1;
	}
	if(ReadFileA){
		exist = 1;
	}
	if(WriteFileA){
		exist = 1;
	}
	if(GetProcAddress){
		exist = 1;
	}
	return exist;
}

int main()
{	
	cout << "Hello World!" << endl;
	return no_thing_do_func();
}
