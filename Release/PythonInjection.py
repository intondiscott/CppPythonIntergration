import re
import string

from collections import Counter
from datetime import date

class Grocery_tracking_Program():
    def __init__(self, food: list):
        self.food = food

    def food_frequency(self) -> dict: 
        return Counter(self.food) # this creates a dictionary of keys and values

list_of_food = open("file.txt")
list_frequency = open("frequency.dat","w")
read = list_of_food.read()
list_of_food.close()
food_list = read.split()

def writing_to_file():
    food1 = Grocery_tracking_Program(food_list) # creates our object 
    
    for i in food1.food_frequency():
        #print(i, food1.food_frequency()[i] * "[+]") --> this was to test making a graph in python without using data tools 
        list_frequency.write(i + " " + str(food1.food_frequency()[i]) + "\n")
    list_frequency.close()



    
