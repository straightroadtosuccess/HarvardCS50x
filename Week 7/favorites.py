import csv
# import re

# titles = {}
counter = 0
title = input("Title ").strip().upper()

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1
        # title = row["title"].strip().upper()
        # if title == "Scratch" or title == "Scratch":
        # if "scratch" in title:
        # if re.search("SCRATCH", title):
        #     counter += 1
        # if not title in titles:
        #      titles[title] = 0
        # titles[title] += 1

print(counter)
# print (f"Number of people who like Scratch: {counter}")

# def get_value(title):
#      return titles[title]

# for title in sorted(titles, key=lambda title: titles[title], reverse=True):
#         print(title, titles[title])
