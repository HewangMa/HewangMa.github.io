import threading
import time


def sing(msg):
    while True:
        print(msg)
        time.sleep(2)


def dance(msg):
    while True:
        print(msg)
        time.sleep(2)


sing_thread = threading.Thread(target=sing, args=("我会唱歌。。。",))
dance_thread = threading.Thread(target=dance, kwargs={"msg": "awighba"})

sing_thread.start()
dance_thread.start()
