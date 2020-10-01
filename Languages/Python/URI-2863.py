# -*- coding: utf-8 -*-
# Question 2863 from https://www.urionlinejudge.com.br/
# https://www.urionlinejudge.com.br/judge/pt/problems/view/2863
# @GalatasXF
while True:
    menor = 100
    try:
        for _ in range(int(input())):
            a = float(input())
            if a < menor:
                menor = a
    except:
        break
    print(menor)
