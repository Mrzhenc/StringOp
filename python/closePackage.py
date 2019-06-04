#!/usr/bin/python
# encoding=utf-8

'''
必要条件：
    1. 闭包必须返回一个函数对象
    2. 闭包必须引用外部变量（一般不能是全局变量）
    3. 构成闭包的函数不一定有返回值
'''

a = 10 # 定义一个全局变量

def closure_test1():
    def sub(x):
        return x - 1;
    return sub


def closure_test2(a, b):
    def line(x):
        return a * x + b;
    return line


def closure_test3():
    i = 1
    def add():
        # error
        # i = i + 1
        print(i)
    return add


def closure_test4():
    i = 1
    def modify():
        j = i + 1
    return modify


# 普通函数无法保存环境变量
def common_func():
    f = []
    for i in range(3):
        def foo(x): return x + i
        f.append(foo)

    for foo in f:
        print(foo(1))

def closure_func():
    # 闭包的使用
    f1 = []
    for i in range(3):
        def foo(i):
            def __closure(x):
                return i + x
            return __closure
        f1.append(foo(i))

    for foo in f1:
        print(foo(1))

if __name__ == "__main__":
    # func = closure_test1()
    # print(func(3))

    # func = closure_test2(3, 4)
    # func1 = closure_test2(1, 2)
    # print(func(2))
    # print(func1(2))

    func = closure_test4()
    func()
    print(a)

    # add = closure_test3()
    # add()
    # common_func()
    # closure_func()
