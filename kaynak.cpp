#include <iostream>
#include <Windows.h>

int main()
{
	HMODULE hModule = GetModuleHandle(NULL); 
	HRSRC hResource = FindResourceW(hModule, MAKEINTRESOURCEW(101), L"CPP"); // resource'a eklenmi� dosyam�z�n konumu


	HGLOBAL hMemory = LoadResource(hModule, hResource);   //resource' u y�klesin
	DWORD dwSize = SizeofResource(hModule, hResource);   //resource un boyutu
	LPVOID lpAddress = LockResource(hMemory);			//LockResource' un d�n�� de�eri,resourceumuzdaki dosyan�n ilk bayt�n�n i�aret�isidir.

	HANDLE hFile;
	DWORD dwBytesWritten = 0;
	std::string a = "hello.exe";
	hFile = CreateFileA((LPCSTR)a.c_str(),  // name of the write
		GENERIC_WRITE,          
		0,                     
		NULL,                   
		CREATE_NEW,           
		FILE_ATTRIBUTE_NORMAL, 
		NULL);
	BOOL ErrorWrite = WriteFile(
		hFile,           //olu�turdu�umuz dosyan�n handle' �
		lpAddress,       //dosyan�n ilk bayt�
		dwSize,			 //boyut
		&dwBytesWritten, 
		NULL);          
	CloseHandle(hFile);
	Sleep((DWORD)10000);
	FreeResource(hMemory);
}