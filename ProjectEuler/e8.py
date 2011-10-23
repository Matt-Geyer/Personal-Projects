# Brute Force problem 8

# Open file where I stored the numbers
numFile = open("e8nums.txt")

# Read in the entire file..
nums = numFile.read()

# Get rid of the newlines
nums = nums.replace('\n',"")

maximum = 0
prod = 1
count = 0

# Loop through for every digit
for digit in nums:
    if( count >= 5 ):
        # Starting at the current digit
        prod = int(nums[count])
        # get the product
        for index in range( count - 1 , count - 5 , -1 ):
            prod *= int(nums[index])
        #print prod
        if( prod > maximum ):
            maximum = prod
    count += 1

print maximum
