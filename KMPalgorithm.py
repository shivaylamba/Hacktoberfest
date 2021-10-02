def KMPSearch(pat: str, txt: str):
    M = len(pat)
    N = len(txt)
    lps = [] # To store computed Longest prefix suffix array
    t = -1
    lps.append(t)
    for k in range(M):
        while(t >= 0 and pat[t] != pat[k]):
            t = lps[t]
        t = t + 1
        lps.append(t)
    
    m = 0
    iarr = [] # To store index of pattern match
    for i in range(0, N):
        while (m >= 0 and pat[m] != txt[i]):
            m = lps[m]
        m = m + 1
        if m == M:
            iarr.append((i - m + 1, i))
            m = lps[m]
    # print(f"Text: {txt}")
    # print(f"Pattern: {pat}")
    return (lps,iarr)


if __name__ == "__main__":
    txt = str(input("input text string: "))
    pat = str(input("input pattern string: "))
    lps,matchArr = KMPSearch(pat, txt)
    print(f"lps array: {lps}")
    print(f"Found patter in text at indices: {matchArr}")
