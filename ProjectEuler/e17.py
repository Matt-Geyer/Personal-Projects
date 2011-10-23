words = dict()
words[0] = ""
words[1] = "one"
words[2] = "two"
words[3] = "three"
words[4] = "four"
words[5] = "five"
words[6] = "six"
words[7] = "seven"
words[8] = "eight"
words[9] = "nine"
words[10] = "ten"
words[11] = "eleven"
words[12] = "twelve"
words[13] = "thirteen"
words[14] = "fourteen"
words[15] = "fifteen"
words[16] = "sixteen"
words[17] = "seventeen"
words[18] = "eighteen"
words[19] = "nineteen"
words[20] = "twenty"
words[21] = "just kidding"
words[30] = "thirty"
words[40] = "forty"
words[50] = "fifty"
words[60] = "sixty"
words[70] = "seventy"
words[80] = "eighty"
words[90] = "ninety"

def buildEnglishNumber( num ):
    engRep = ""
    sNum = str(num)
    if( num > 1000 ):
        return ""
    if( num == 1000 ):
        return "onethousand"
    if( num <= 20 ):
        engRep = words[num]
        return words[num]
    if( num >= 100 ):
        sub = int(sNum[1] + sNum[2])
        engRep = words[int(sNum[0])] + "hundred"
        if( sub != 0 ):
           engRep += "and" + buildEnglishNumber(sub)
    if( num < 100 ):
        engRep = words[int(sNum[0]) * 10]
        if( int(sNum[1]) != 0 ):
            engRep += words[int(sNum[1])]
    return engRep

charSum = 0
for x in range(1,1001,1):
    charSum += len(buildEnglishNumber( x ))
    print buildEnglishNumber( x )
#print buildEnglishNumber(999)
print charSum
