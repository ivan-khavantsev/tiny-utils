#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int win_error() {
    cout << "error" << endl;
    return 0;
}

int main() {
    HANDLE hDisk = ::CreateFile("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDisk == INVALID_HANDLE_VALUE) throw win_error();

    BYTE buf[62464];
    DWORD dwRead;

    // Offset и размер буфера должен быть кратен размеру сектора диска (например 512)

    // OVERLAPPED ol{}; // Можно использовать OVERLAPPED или ::SetFilePointer
    // ol.Offset = 825032704;
    // ol.Offset = 0;

    ::SetFilePointer(hDisk, 825032704, NULL, FILE_BEGIN);

    if (!::ReadFile(hDisk, buf, sizeof(buf), &dwRead, NULL) || dwRead != sizeof(buf)) throw win_error();
    ::CloseHandle(hDisk);

    //ofstream out("1.txt");
    for (int i = 0; i < sizeof(buf); i++) {
        //char f[3];
        //snprintf (f, sizeof(f), "%d", buf[i]);
        //out<<i<<"\t"<<f<<"\t"<<buf[i]<<'\n';
        //out << buf[i];
        cout << buf[i];
    }
    //out.close();
    //cin.get();
}