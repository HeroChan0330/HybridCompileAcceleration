clc
clear

if ~libisloaded('DllTest')
    [notfound,warnings] = loadlibrary("DllTest","pch.h");
end

ret = calllib('DllTest','HelloWorld')

ret = calllib('DllTest','RetFloat')

ret = calllib('DllTest','RetDouble')

ret = calllib('DllTest','RetChar');
ret = char(ret)

ret = calllib('DllTest','RetStr')

ret = calllib('DllTest','SqrInt',11.4)

ret = calllib('DllTest','SqrFloat',11.4)


num_ptr = libpointer("int32Ptr",123);
calllib('DllTest','OppositeInt',num_ptr)
num = get(num_ptr).Value

arr = 1:6;
arr_ptr = libpointer("int32Ptr",arr);
ret = calllib('DllTest','SumIntArr',arr_ptr,length(arr))

calllib('DllTest','ReverseIntArr',arr_ptr,length(arr));
get(arr_ptr).Value
arr

v = 1:10;
v_ptr = libpointer("singlePtr",v);
ret = calllib('DllTest','VecMod',v_ptr,length(v))
sqrt(v*v')


% 定义矩阵
m1 = [[1,2,3];[4,5,6]];
m2 = [[7;8;9],[10;11;12]];
[r1,c1] = size(m1);
[~,c2] = size(m2);
% 重排乘向量并取指针
m1_ptr = libpointer("singlePtr",reshape(m1,[],1));
m2_ptr = libpointer("singlePtr",reshape(m2,[],1));
mo_ptr = libpointer("singlePtr",zeros(r1*c2,1));
% 调用DLL
calllib('DllTest','MatrixMul', m1_ptr, m2_ptr, mo_ptr, r1, c1, c2);
mo = get(mo_ptr).Value;
% 重排返回
mo = reshape(mo,r1,c2)
m1 * m2

% 定义复向量
v = [1+2i;3+4i];
len = length(v);
% 复向量重排
v = [real(v)';imag(v)'];
v = reshape(v,[],1);
% 计算返回
v_ptr = libpointer("singlePtr",v);
ret = calllib('DllTest','CVecMod',v_ptr,len)
sqrt(v'*v)



unloadlibrary DllTest
