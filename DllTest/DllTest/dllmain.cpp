// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

int HelloWorld() {
    return 114514;
}

float RetFloat() {
    return 114.514f;
}
double RetDouble() {
    return 114.514;
}
char RetChar() {
    return 'Q';
}

char* RetStr() {
    return (char*)"114514";
}

int arr[] = { 1,1,4,5,1,4 };
int* RetIntArr() {
    return arr;
}

int SqrInt(int num) {
    return num * num;
}

float SqrFloat(float num) {
    return num * num;
}

void OppositeInt(int* numPtr) {
    (*numPtr) = -(*numPtr);
}

int SumIntArr(int* arr, int len) {
    int sum = 0;
    for (int n = 0; n < len; n++) {
        sum += arr[n];
    }
    return sum;
}

void ReverseIntArr(int* arr, int len) {
    for (int n = 0; n < len / 2; n++) {
        int temp = arr[n];
        arr[n] = arr[len - 1 - n];
        arr[len - 1 - n] = temp;
    }
}

void ReverseStr(char* str) {
    int len = strlen(str);
    for (int n = 0; n < len / 2; n++) {
        int temp = str[n];
        str[n] = str[len - 1 - n];
        str[len - 1 - n] = temp;
    }
}

#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;
float VecMod(float* arr, int len) {
    VectorXf vec = Map<VectorXf>(arr, len, 1);
    return sqrt(vec.dot(vec));
}

void MatrixMul(float* arr1, float* arr2, float* arr_out, int r1, int c1, int c2) {
    MatrixXf matrix1 = Map<MatrixXf>(arr1, r1, c1);
    MatrixXf matrix2 = Map<MatrixXf>(arr2, c1, c2);
    MatrixXf matrix3 = matrix1 * matrix2;
    memcpy(arr_out, matrix3.data(), r1 * c2 * sizeof(float));
}

float CVecMod(float* arr, int len) {
    scomplex* carr = (scomplex*)arr;
    VectorXcf vec = Map<VectorXcf>(carr, len, 1);
    return sqrt(vec.dot(vec).real());
}