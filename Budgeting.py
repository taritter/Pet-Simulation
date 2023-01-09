import cv2
import sys
import matplotlib.pyplot as plt
import os
import platform
import subprocess
from subprocess import Popen, PIPE, check_output

filename = "Pet_Expenses.txt"

money_vector = [0,0,0,0,0,0,0]
days = []
count = -1

with open(filename) as money_data:
    for line in money_data:
        num = 0.0
        #line = money_data.readline()
        if(line[0:3] == "Day"):
            days.append(line.rstrip())
            count+=1
        else:
            try:
                num = float(line.rstrip())
                money_vector[count] += num
            except ValueError:
                pass

money = plt.subplot(111)

money.bar(days, money_vector, width=0.5, color='g', align='center',linewidth=3, alpha=.5)

plt.gcf().canvas.manager.set_window_title('Money Graph')
plt.title('Spending')
plt.xlabel('Days')
plt.xticks(days)
plt.ylabel('Money Spent')
plt.savefig("Your_Spending.png", format = 'png')
plt.show()

plt.close()