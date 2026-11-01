from shlex import join

people={
    "a":["mon","tue"],
    "b":["tue","wen"],
    "c":["tue","tha"],
    "d":["tue","fri"],
    "e":["tue","sat"]
}
common=set(next(iter(people.values())))
for days in people.values():
    common&=set(days)
if common:
    print("meeting schedule on:",join(common),"at 10am,room no 101")
else:
    print("no common day available for the meeting")