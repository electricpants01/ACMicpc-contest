import fileinput
def D(a):print(a)
def S(s,I):return int(s.split(" ")[I])
def main():
    MOD=1000000007
    for l in fileinput.input():
        A=S(l,0)
        B=S(l,1)
        K=S(l,2)
        C=S(l,3)
        if(A!=C and C!=B):return D(0)
        if(A==B):return D(K)
        if(K==0):return D(0)
        D(pow(2,K-1,MOD)*K%MOD)
main()
