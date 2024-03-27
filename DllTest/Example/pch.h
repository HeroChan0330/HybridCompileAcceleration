// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"


#ifdef __cplusplus 
extern "C" {
#endif

	__declspec(dllexport) int HelloWorld();
	__declspec(dllexport) float RetFloat();
	__declspec(dllexport) double RetDouble();
	__declspec(dllexport) char RetChar();
	__declspec(dllexport) char* RetStr();
	__declspec(dllexport) int* RetIntArr();
	__declspec(dllexport) int SqrInt(int num);
	__declspec(dllexport) float SqrFloat(float num);
	__declspec(dllexport) void OppositeInt(int* numPtr);
	__declspec(dllexport) int SumIntArr(int* arr, int len);
	__declspec(dllexport) void ReverseIntArr(int* arr, int len);
	__declspec(dllexport) void ReverseStr(char* str);
	
	__declspec(dllexport) float VecMod(float* arr,int len);

	__declspec(dllexport) void MatrixMul(float* arr1, float* arr2, float* arr_out, int r1, int c1, int c2);

	__declspec(dllexport) float CVecMod(float* arr, int len);
#ifdef __cplusplus 
}
#endif



#endif //PCH_H
