#!/usr/bin/python3

from copy import deepcopy

def compute_mul(x, y, mata, matb):
    ret = 0
    for i in range(3):
        ret += mata[x][i] * matb[i][y]
    return ret

def mul_mat(mata, matb):
    tmp = deepcopy(mata)
    for x in range(3):
        for y in range(len(mata[0])):
            tmp[x][y] = compute_mul(x, y, matb, mata)
    return tmp

def display_mat(mat):
    for y in range(len(mat[0])):
        for x in range(3):
            print(mat[x][y], "", end="")
    print("")