import pyperclip as pc
import keyboard
import time
while True:
    if keyboard.is_pressed('ctrl+c'):
        s = pc.paste()
        # print(s)
        s2 = ''
        for line in s.split("\n"):
            if line:
                s2+=line+'\n'
        print(s2)
        pc.copy(s2)