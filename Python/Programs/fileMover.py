import shutil
import os
import random
import time
import sys

w = ["Waiting.  ","Waiting.. ","Waiting..."]

def move(path, pathList, sleep):

    lista_file = os.listdir(path)                                           # lista dei file presenti nella cartella
    nFile = len(lista_file)                                                 # lunghezza della lista, quindi numero di file
    count = 0


    while(nFile > -1):
        nFile -= 1
        st = str(lista_file[count])

        if st[0] == 'P':
            dest = pathList[1]
        elif st[0] == 'C' and st[1] == '+':
            dest = pathList[0]
        else:
            return

        filePath = path + "/" + lista_file[count]
        shutil.move(filePath, dest)

        del lista_file[count]
        count += 1

        time.sleep(sleep)
        if nFile == 0:
            return
    

path    = "/home/pam4k4/Scrivania/Dist"                                     # partenza
pathList = ["/home/pam4k4/Documenti/Mine_exe/C++","/home/pam4k4/Documenti/Mine_exe/Python"]   # arrivi

while True:
    try:
        print move(path, pathList, 3) + '\n'
    except:
        for item in w:
            sys.stdout.write('\r' + str(item))
            sys.stdout.flush()                                              # important
            time.sleep(0.5)

# os.rename('file.ext, 'file2.ext') per rinominare un file