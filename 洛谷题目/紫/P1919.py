from decimal import *
import sys
setcontext(Context(prec=2000000, Emax=2000000, Emin=0)) 
print((Decimal(sys.stdin.readline())*Decimal(sys.stdin.readline())))