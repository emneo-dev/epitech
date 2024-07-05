#!/usr/bin/python3

from math import floor

def add_rows(arr, str, length):
    for i in range(length - 3):
        for j in range(3):
            arr[j].append(0)
    return arr

def load_to_mat(str):
    arr = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    length = floor(len(str) / 3) + 1
    if (len(str) % 3 == 0):
        length -= 1
    if (len(str) > 9):
        arr = add_rows(arr, str, length)
    for i in range(length):
        for j in range(3):
            if i * 3 + j < len(str):
                arr[j][i] = ord(str[i * 3 + j])
    return arr