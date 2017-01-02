import threading
import time
import random

class thread(threading.Thread):
  def __init__(self,counter,nom):
    threading.Thread.__init__(self)
    self.c = counter
    self.id = nom
  def run(self):
    while self.c < 10:
      time.sleep(random.randint(0,2))
      print(self.c, end="")
      self.c += 1
    
t1 = thread(0,"t1")
t2 = thread(0,"t2")
t1.start()
t2.start()

t1.join()
t2.join()
