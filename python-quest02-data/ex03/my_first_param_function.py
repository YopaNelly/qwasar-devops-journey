# function will print:
#("detonation in... "+str(seconds_left)+" seconds.")
def detonation_in(timer):
    print(f"detonation in...", timer, "seconds.")
timer = 10;

while (timer > 0 and timer <=10):
  detonation_in(timer)
  timer -= 1
