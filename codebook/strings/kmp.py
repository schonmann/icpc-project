def buscaKMP(pat, txt):
    ocs = 0
    m, n = len(pat), len(txt)
    lps = [0]*m 
    j = 0
    preProcessa(pat, m, lps)
    print(lps)
    i = 0 
    while i < n: 
        if pat[j] == txt[i]: 
            print(f"Ocorrencia no índice! {i-m}")
            i += 1
            j += 1
        if j == m: 
            ocs += 1
            j = lps[j-1] 
        elif i < n and pat[j] != txt[i]:
            if j != 0: 
                j = lps[j-1] 
            else: 
                i += 1

def preProcessa(pat, m, lps): 
    len = 0 
    lps[0]
    i = 1
    while i < m: 
        if pat[i]== pat[len]: 
            len += 1
            lps[i] = len
            i += 1
        else:
            if len != 0: 
                len = lps[len-1]              
            else: 
                lps[i] = 0
                i += 1
    return lps
