#Elizabeth Bruski
#I pledge my honor that I have abided by the Stevens Honor System.

opcode = ""

def numToBinary(n):
    """converts an integer value to binary"""
    if n == 0:
        return ''
    else:
        return str(numToBinary(n//2)) + str(n % 2)
   
def binaryToNum(s):
    """converts a binary value to a base 10 number"""
    if s == '':
        return 0
    return int (s[0]) * (2**(len(s)-1)) + binaryToNum(s[1:])


inst = open("instruction.txt", "r") 
im = open("image.txt", "w")
i = 0

print("hello")
for line in inst:
    s=line
    if s[0:3] == "ADD":
        opcode = "00"
        print("ADD")
    elif s[0:3] == "SUB":
     opcode = "01"
     print ("sub")
    
    else: 
     opcode = "10"
     print ("load")
    dest = ""
    op1 = ""
    op2 = ""
    if ((int(s[4:6])) == 0):
        dest = "00"
    elif ((int(s[4:6])) == 1):
        dest = "01"
    else:
        dest = numToBinary(s[4:6])
    if ((int(s[7:9])) == 0):
        op1 += "00"
    elif ((int(s[7:9])) == 1):
        op1 = "01"
    else:
        op1 += numToBinary(int(s[7:9]))
    if((int(s[10:12])) == 0):
        op2 += "00"
    elif((int(s[10:12])) == 1):
        op2 += "01"
    else:
        op2 += numToBinary(int(s[10:12]))

    
    opcode = opcode + dest + op1 + op2
    print("OPCODE: " + opcode + "\n")
    n = binaryToNum(opcode)
    print ("int is: " + str(n))
    t = hex(n)
    im.writelines(t) # writes the hexadecimal value of the opcode to the image file
    im.writelines("\n")
    i += 1

inst.close()
    

    
    