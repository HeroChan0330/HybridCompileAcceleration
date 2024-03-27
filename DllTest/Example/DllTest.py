
from ctypes import *
import os
import sys
p = os.path.dirname(__file__)
if sys.version_info>=(3,8):
    CDLL("%s/DllTest.dll"%p, winmode=0)
else:
    CDLL("%s/DllTest.dll"%p)
dll = cdll.LoadLibrary("DllTest")

# return with differnt basic types
ret = dll.HelloWorld()
print(ret)

dll.RetFloat.restype = c_float
ret = dll.RetFloat()
print(ret)

dll.RetDouble.restype = c_double
ret = dll.RetDouble()
print(ret)

dll.RetChar.restype = c_char
ret = dll.RetChar()
print(ret)

dll.RetStr.restype = c_char_p
ret = dll.RetStr()
print(ret)

dll.SqrInt.restype = c_int
ret = dll.SqrInt(11)
print(ret)

dll.SqrFloat.restype = c_float
ret = dll.SqrFloat(c_float(11))
print(ret)

dll.RetIntArr.restype = POINTER(c_int * 6)
ret = dll.RetIntArr()
ret = list(ret.contents)
print(ret)

from numpy.ctypeslib import ndpointer
dll.RetIntArr.restype = ndpointer(dtype=c_int, shape=(6,1))
ret = dll.RetIntArr()
print(ret)

num = c_int(123)
dll.OppositeInt(byref(num))
print(num.value)

arr = [1,2,3,4,5,6]
InArrType = c_int32*len(arr)
arr_ptr = InArrType(*arr)
ret = dll.SumIntArr(arr_ptr,c_int(len(arr)))
print(ret)
dll.ReverseIntArr(arr_ptr,c_int(len(arr)))
print(list(arr_ptr))

s = 'Hello'
s_in_ptr = c_char_p(s.encode())
dll.ReverseStr(s_in_ptr)
print(s_in_ptr.value.decode('utf-8'))

