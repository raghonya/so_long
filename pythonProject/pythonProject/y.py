#  Create a function that takes the number of wins, draws and losses and calculates the number of points a football team has obtained so far.
# 	wins get 3 points
# 	draws get 1 point
# 	losses get 0 points

win=int(input("win"))
draws=int(input("draws"))
losse=int(input("losse"))
print(3*win+1*draws+0*losse)
