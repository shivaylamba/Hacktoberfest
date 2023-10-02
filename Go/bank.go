package main

import (
	"errors"
	"fmt"
)

type Account struct{
	Fname string
	Lname string
}
type Employee struct{
	Account 
	Credits float64
}

func (a *Account) changeName(newName string) {
	a.Fname = newName
}

func (e *Employee) String() string {
	return fmt.Sprintf("Name: %s\t%s\nCredits:\t%.2f\n",e.Fname,e.Lname,e.Credits) // Sprintf returns formatted strings
}

func createEmployee(firstName, lastName string,credits float64)(*Employee, error){
	return &Employee{Account{firstName,lastName},credits},nil
}

func (e *Employee) addCredits(amount float64)(float64, error){
	if amount>0.0{
			e.Credits += amount
			return e.Credits,nil
	}
	return 0.0, errors.New("Invalid credit amount!\nPlease give amount greater than 0.0\n\n")
}

func (e *Employee) removeCredits(amount float64)(float64, error){
	if amount > 0.0{
		if amount <= e.Credits{
			e.Credits -= amount
			return e.Credits, nil
		}
		return 0.0,errors.New("You can't draw more amount than your account has!\n")
	}
	return 0.0, errors.New("You can't give negative amounts to draw, please give amount in positive values:\n")
}

func (e *Employee) checkCredits ()(float64){
	return e.Credits
}



func main(){
	Wayne, _ := createEmployee("Bruce","Wayne",420)
	fmt.Println(Wayne.checkCredits())

	credits, error := Wayne.addCredits(180)
	if error!=nil{
		fmt.Println("Error while adding credits: ",error)
	}else{
		fmt.Println("Balance = ", credits)
	}
	_, err := Wayne.removeCredits(100)
	if err != nil{
		fmt.Println("Can't withdraw amount at the moment. Please try again later...",err)
	}
	Wayne.changeName("Batman")
	fmt.Println(Wayne)

}