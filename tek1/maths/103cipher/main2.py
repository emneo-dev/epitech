#!/usr/bin/python3

from matrix import *
from sys import argv, exit
from load_matrix import load_to_mat
from decrypt import *
from math import ceil

def helper():
    print("USAGE")
    print("\t./cipher message key flag")
    print("")
    print("DESCRIPTION")
    print("\tmessage\t\ta message, made of ASCII characters")
    print("\tkey\t\tthe encryption key, made of ASCII characters")
    print("\tflag\t\t0 for the message to be encrypted, 1 to be decrypted")

def main_0():
    arr = load_to_mat(argv[1])
    key = load_to_mat(argv[2])
    arr = mul_mat(arr, key)
    print("Key matrix:")
    for i in range(3):
        print("%-8d%-8d%d" % (key[0][i], key[1][i], key[2][i]))
    print("")
    print("Encrypted message:")
    display_mat(arr)

def det_mul(det, adj):
    for i in range(len(adj)):
        for y in range(len(adj[0])):
            adj[i][y] *= det
    return adj

def main_1():
    arr = load_encrypt_matrix(argv[1]) #not sure
    key = load_to_mat(argv[2])
    det = determinant(key)
    adj = adjugate_mat(key)
    inv_key = det_mul(det, adj)
    print("Key matrix:")
    for i in range(3):
        print("%-8.2f%-8.2f%.2f" % (inv_key[0][i], inv_key[1][i], inv_key[2][i]))
    print("")
    arr = mul_mat(arr, inv_key)
    for i in range(len(arr)):
        for y in range(len(arr[0])):
            arr[i][y] = ceil(arr[i][y] % 26)
    msg = decryption(arr)
    print("Decrypted message:")
    #How do I freaking display the message...
    for i in range(len(msg)):
        for y in range(len(msg[0])):
            print(msg[i][y], end="")
    print("")


def main():
    if len(argv) != 4:
        exit(84)
    if argv[1] == "-h":
        helper()
        exit(0)
    if len(argv[2]) > 9 or (argv[3] != "1" and argv[3] != "0"):
        exit(84)
    if (argv[3] == "0"):
        main_0()
    if (argv[3] == "1"):
        main_1()