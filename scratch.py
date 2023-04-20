print("Welcome to my first project!")
name = input("what is your name? ")
print("Hello", name + ", I am glad you are here")
print(name, "I would like to get to know you a little better")
age = int(input("What is your age? "))

health = 10

if age <= 25:
    print("ok grandpa I guess you can play")

    wants_to_play = input("Do you want to play? ").lower()
    if wants_to_play == "yes":
        print("Great! Lets move on")
        print("Welcome, you find yourself in an abandoned warehouse and start with", health,
              "health, you will be prompted with different paths to chose from which will dictate your destiny")

        direction = input("First choice... Left or Right? ").lower()
        if direction == "left":
            ans = input(
                "Nice, you chose wisely and lived... You then stumble across a ravine... Do your Jump or do you Turn back(Jump/Turn?)")

            if ans == "Jump":
                print("Good shit bro you made it")

            elif ans == "Turn":
                print("Lol you turn back but encounter someone...")

            else:
                print("wow, you are now stuck in place dumbass")

            ans = input("You notice a house and a river, which do you go to (river/house?) ")
            if ans == "house":
                print("You go to the house and are greeted by the owner, he merks your bitch ass")
                health -= 1

                if health <= 0:
                    print("your health has fallen below 0, its Game Over")
                else:
                    print("Congradulations, You have made it this far")

            else:
                print("You go to a room and find a key")

        else:
            print("You walk into a puddle of mud, oh no its quick sand now you are drowning...")
            health -= 1
            print("Lol you died")
            health -= 1
            print(health, "health remaining...")

    else:
        print("Ok, have a good day...")



else:
    print("Sorry bud", age, "is not old enough")


