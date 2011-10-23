# Project Euler 13

# Open file containing numbers
nums = open("e13nums.txt")


summ = 0

# Read and sum up each line in the file
for x in range(0,100):
    summ += int(nums.readline().replace('\n',''))

# Convert to make displaying the first 10 digits easy
summ = str(summ)

# Initialize empty string that will contain the first 10 digits
firstTen = ""

# Add the first 10 digits to the string then print
for x in range ( 0 , 10 ):
    firstTen += summ[x]

print firstTen


