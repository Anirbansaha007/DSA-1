import math
import os
import random
import re
import sys

n = int(raw_input())
if n >= 1 & n <= 100:
    if (n%2 == 0):
        if n in range(6,21):
            print("Weird")
        elif (n >= 2 & n<= 5 ):
            print("Not Weird")
        elif (n > 20):
            print("Not Weird")
    elif (n%2 != 0):
        print("Weird")