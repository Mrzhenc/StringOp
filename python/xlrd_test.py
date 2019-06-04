#!/usr/bin/python
# encoding=utf-8

import xlrd
FILE_PATH="/opt/test.xlsx"


def open_xls():
    return xlrd.open_workbook("/opt/test.xlsx")


def get_sheet_by_index(obj, index):
    return obj.sheets()[index]
    # return obj.sheet_by_index(index)


def get_sheet_by_name(obj, name):
    return obj.sheet_by_name(name)


def get_sheet_names():
    return obj.sheet_names()


if __name__ == "__main__":
    # 打开表格
    obj = open_xls()

    # 获取表格中的sheet。
    sheet = get_sheet_by_index(obj, 0)

    # 检测sheet十分加载完毕, 参数可以为下标或者sheet名称
    obj.sheet_loaded(0)

    # 获取当前sheet有效行列
    print sheet.ncols, sheet.nrows

    #获取单元格的内容
    print sheet.cell(1, 1).value

    # 获取表格的所有sheet name
    for name in get_sheet_names():
        print name

    # 获取某一行的内容
    print "============"
    for index in sheet.row(1):
        print index.value


