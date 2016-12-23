from array import *
import re
import serial
import pyautogui
import math

arduino_serial_data = serial.Serial('/dev/ttyACM0',9600)


move_x = 0.0
move_y = 0.0

while (1==1):
    if(arduino_serial_data.inWaiting()>0):

        data = arduino_serial_data.readline()
        data  = data.decode("utf-8")
        data.strip()

        if(data[0] == 's'):
            # pyautogui.click(button='left')
            pyautogui.click(clicks=2)

        elif(data[0] == 'd'):
            pyautogui.click(button='right')

        elif(data[0] != 's' and data[0] != 'd'):
            data = data.split()
            move_x = data[0]
            move_y = data[1]



        # move_x = arduino_serial_data.readline()
        # move_y = arduino_serial_data.readline()
        #
        # move_x = move_x.decode("utf-8")
        # move_y = move_y.decode("utf-8")
        # move_x.strip()
        # move_y.strip()
        move_x = float(move_x)
        move_y = float(move_y)




        print (move_x)
        # print ("mid")
        print (move_y)

        # check if the list is full
        # if(len(list_x)<list_size):
        #     continue

        pyautogui.moveRel((move_x),(move_y))

        # if key == ord("q"):
            # break






#
