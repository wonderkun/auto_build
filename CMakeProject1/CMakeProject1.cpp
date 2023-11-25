// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <Windows.h>

using namespace std;

__forceinline int no_thing_do_func(){
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
	if(ReadFile){
		exist = 1;
	}
	if(WriteFile){
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
	
	return 0;
}
