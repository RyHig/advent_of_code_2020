import fileinput

def part_one(string):
    string = string.strip().split(" ")
    bounds = string[0].split("-")
    lower_bound = int(bounds[0])
    upper_bound = int(bounds[1])
    letter = string[1][0]
    password = string[2]
    counter = 0

    for i in password:
        if i == letter:
            counter = counter + 1
    
    if lower_bound <= counter <= upper_bound:
        return 1

    return 0


def part_two(string):
    string = string.strip().split(" ")
    bounds = string[0].split("-")
    lower_bound = int(bounds[0])
    upper_bound = int(bounds[1])
    letter = string[1][0]
    password = string[2]

    if (password[lower_bound-1] == letter) ^ (password[upper_bound-1] == letter):
        return 1
    
    return 0


if __name__ == "__main__":
    total_one = 0
    total_two = 0
    with fileinput.input(files=('input')) as f:
        for line in f:
            total_one = total_one + part_one(line)
            total_two = total_two + part_two(line)

    print(total_one)
    print(total_two)
