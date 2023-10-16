"""The previous script becomes very boring for the user as he has to keep on typing just numbers and of wants to interact using 
simple english language he is unable to do so. Also the program terminates after one execution and if the user wants to keep on 
performing operations it becomes difficult.
I have tried making a more simple and interactive calculator which allows the user to input any statement for performing the tasks. """




def Calculator(num_1,num_2):
    #Executing the loop infinite times as we donot know how many times the user will want to run
    while(True):
        choice= input("Enter what you want to perform: ")
        print()

        #For Addition user can type any Sentence containing word related to it and will get the output but here we are checking only for the common words
        if ("addition" in choice) or ("add" in choice) or ("sum" in choice) or ("plus" in choice):
            sum = (num_1) + (num_2)
            print("Output....")
            print("Adding {} and {} results to {}".format(num_1,num_2,sum))
            print()
        
        #For Subtraction user can type any Sentence containing word related to it and will get the output but here we are checking only for the common words
        elif ("subtraction" in choice) or ("minus" in choice) or ("difference" in choice) or ("subtract" in choice):
            if( num_1 > num_2 ):
                diff = (num_1) - (num_2)
                print("Output....")
                print("Subtracting {} from {} results to {}".format(num_2,num_1,diff))
                print()
            elif( num_2 > num_1 ):
                diff = (num_2) - (num_1)
                print("Output....")
                print("Subtracting {} from {} results to {}".format(num_1,num_2,diff)) 
                print()   
        
        #For Multiplication user can type any Sentence cpntaining word related to it and will get the output but here we are checking only for the common words
        elif ("multiplication" in choice) or ("product" in choice) or ("multiply" in choice):
            if(num_1==0 or num_2==0):
                print("Output....")
                print("Multiplying {} and {} results to 0".format(num_1,num_2))
                print()
            elif(num_1==1):
                print("Output....")
                print("Multiplying {} and {} results to {}".format(num_1,num_2,num_2))
                print()
            elif(num_2==1):
                print("Output....")
                print("Multiplying {} and {} results to {}".format(num_1,num_2,num_1))
                print()
            else:
                mul = (num_1) * (num_2)
                print("Output....")
                print("Multiplying {} and {} results to {}".format(num_1,num_2,mul))
                print()

        #For Division user can type any Sentence cpntaining word related to it and will get the output but here we are checking only for the common words
        elif("division" in choice) or ("divide" in choice) or ("quotient" in choice):
            if( num_1 > num_2 ):
                if(num_2==0):
                    print("Output....")
                    print("Error: Please try with some other values!")
                
                elif(num_1==0):
                    print("Output....")
                    print("Dividing {} from {} results to 0".format(num_1,num_2))
                    print()
                else:
                    div = (num_1) / (num_2)
                    print("Output....")
                    print("Dividing {} from {} results to {}".format(num_1,num_2,div))
                    print()
            elif(num_1==0 and num_2==0):
                print("Infinity!")
                print()
            elif( num_2 > num_1 ):
                if(num_1==0):
                    print("Output....")
                    print("Error: Please try with some other values!")
                    print()
                
                elif(num_2==0):
                    print("Output....")
                    print("Dividing {} from {} results to 0".format(num_1,num_2))
                    print()
                else:
                    div = (num_2) / (num_1)
                    print("Output....")
                    print("Dividing {} from {} results to {}".format(num_2,num_1,div))
                    print()
        
        #For exiting the loop user can type any Sentence containing word related to it and it will exit from the loop but here we are checking for the common words
        elif ("exit" in choice) or ("stop" in choice) or ("return" in choice):
            break 
        
        else:
            print()
            print("Operation not found: Please try again!")
            print()



def main():

    print()
    print("         THIS IS A BASIC USER FRIENDLY CALCULATOR!          ")
    print()
    
    print("The allowed actions are:")
    print(" 1) ADDITION \n 2) SUBTRACTION \n 3) MULTIPLICATION \n 4) DIVISION")
    print()
    print("You can type a sentence and interact.")
    print()

    #inputting two numbers at a time using the split function
    num_1,num_2 = input("Enter two numbers: ").split()
    num_1=float(num_1)
    num_2=float(num_2)


    #printing both the numbers
    print("Number 1 is: ",num_1)
    print("Number 2 is: ",num_2)
    print()

    Calculator(num_1,num_2)


if __name__ == "__main__":
    main()
