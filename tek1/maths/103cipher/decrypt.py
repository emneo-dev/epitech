#!/usr/bin/python3

from load_matrix import add_rows
from matrix import *
from math import floor
from copy import deepcopy

def determinant(key):
    det1 = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % 26
    det2 = key[0][1] * (key[0][2] * key[2][2] - key[1][2] * key[2][0]) % 26
    det3 = key[0][2] * (key[0][2] * key[2][1] - key[1][1] * key[2][0]) % 26
    det = 1 / (det1 - det2 + det3)
    return det

def adjugate_mat(key):#j'ai hardcode...
    adj = [[0, 0, 0] , [0, 0, 0], [0, 0, 0]]
    adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % 26
    adj[0][1] = -(key[0][1] * key[2][2] - key[0][2] * key[2][1]) % 26
    adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]) % 26
    adj[1][0] = -(key[1][1] * key[2][2] - key[1][2] * key[2][0]) % 26
    adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]) % 26
    adj[1][2] = -(key[0][0] * key[1][2] - key[0][2] * key[1][0]) % 26
    adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]) % 26
    adj[2][1] = -(key[0][0] * key[2][1] - key[0][1] * key[2][0]) % 26
    adj[2][2] = (key[0][0] * key[1][0] - key[0][1] * key[1][0]) % 26
    return adj

def load_encrypt_matrix(str):#pas du tout sure de la fonction
    temp = str.split() #suppose rendre la chaine de chara en liste
    arr = [[0, 0, 0], [0, 0, 0], [0, 0, 0]] #j ai essaye de refaire la meme chose que load_to _mat
    length = floor(len(temp) / 3) + 1 #par contre j'ai aucune idée si ca marche
    if (len(temp) % 3 == 0):
        length -= 1
    if (len(temp) > 9):
        arr = add_rows(arr, temp, length)
    for i in range(length):
        for j in range(3):
            if i * 3 + j < len(temp):
                arr[j][i] = int(temp[i * 3 + j])
    return arr

def decryption(arr):
    decrypt = deepcopy(arr)
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            decrypt[i][j] = chr(arr[i][j]+ 97)#je sais pas si ca rend bien une lettre
    return decrypt