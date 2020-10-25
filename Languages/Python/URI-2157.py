# -*- coding: utf-8 -*-
# Question 2157 from https://www.urionlinejudge.com.br/
# https://www.urionlinejudge.com.br/judge/pt/problems/view/2157
# @GalatasXF

for i in range(int(input())):
	a,b = [int(i) for i in input().split()]
	s = ""
	for i in range(a,b+1):
		s += str(i)
	s += s[::-1]
	print(s)
