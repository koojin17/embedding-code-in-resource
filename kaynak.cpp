#include <iostream>
#include <Windows.h>

int main()
{
	HMODULE hModule = GetModuleHandle(NULL); 
	HRSRC hResource = FindResourceW(hModule, MAKEINTRESOURCEW(101), L"CPP"); // resource'a eklenmis dosyamizin adi


	HGLOBAL hMemory = LoadResource(hModule, hResource);   //resource' u y�klesin
	DWORD dwSize = SizeofResource(hModule, hResource);   //resource' un boyutu
	LPVOID lpAddress = LockResource(hMemory);			//LockResource' un d�n�s degeri, resourceumuzdaki dosyanin ilk baytinin isaret�isidir.

	HANDLE hFile;
	DWORD dwBytesWritten = 0;
	std::string a = "hello.exe";
	hFile = CreateFileA((LPCSTR)a.c_str(),  //isim ve yol belirle
		GENERIC_WRITE,          
		0,                     
		NULL,                   
		CREATE_NEW,           
		FILE_ATTRIBUTE_NORMAL, 
		NULL);
	BOOL ErrorWrite = WriteFile(
		hFile,           //olusturdugumuz dosyanin handle' i
		lpAddress,       //dosyanin ilk bayti
		dwSize,			 //boyut
		&dwBytesWritten, 
		NULL);          
	CloseHandle(hFile);
	Sleep((DWORD)10000);
	FreeResource(hMemory);
}