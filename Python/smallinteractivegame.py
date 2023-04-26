#First python project practicing if/else statements
print("Welcome to my first project!")
name = input("what is your name? ")
print("Hello", name + ", I am glad you are here")
print(name, "I would like to get to know you a little better")
age = int(input("What is your age? "))
print("Say you are going to fight a zombie, which would you choose...")
weapon = input("A katana or a spear ").lower()
health = 10

if age >= 16:
    print("Great, You are old enough to play")

    wants_to_play = input("Do you want to play? ").lower()
    if wants_to_play == "yes":
        print("Great! Lets move on")
        print("Welcome, you find yourself in an abandoned warehouse and start with", health,
              "health, you will be prompted with different paths to chose from which will dictate your destiny")

        direction = input("First choice... Left or Right? ").lower()
        if direction == "left":
            ans = input(
                "Nice, you chose wisely and lived... You then stumble across a ravine... Do your Jump or do you turn back (Jump/Turn?) ").lower()
            if ans == "jump":
                print("Nice! You made it")
            elif ans == "turn":
                print("Lol you turn back but encounter someone...")
            else:
                print("Oh no! You are now stuck in place")

            ans = input("You notice a house and a river, which do you go to (river/house?) ").lower()
            if ans == "house":
                print("You go to the house and are greeted by the owner, he kills you")
                health -= 1

                if health <= 0:
                    print("your health has fallen below 0, its Game Over")
                else:
                    print("Congratulations, You have made it this far")

            else:
                print("You go to a room and find a key")

        if direction == "right":
            print("You walk into a puddle of mud, oh no its quick sand now you are drowning...")
            health -= 1
            print("You took lung damage from all of the dirt in your system")
            print(health, "health remaining...")

            ans = int(input("You find yourself in a room with keypad on it, you must enter a number 1-10 "))
            if ans == 7:
                print("")
    else:
        print("Ok, have a good day...")



else:
    print("Sorry bud", age, "is not old enough")


