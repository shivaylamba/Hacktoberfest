package main

import "fmt"

func main(){
	var a[5] int
	a[2] =94
	fmt.Println(a)

	b :=[5] string {"a","boy","went","missing"}
	fmt.Println(b)

	c :=[...] string {"and","a","girl","found","him by a lake"} // (...)  called  as ellipses, used when we don't know the size while declaring
	fmt.Println(c)
	
	d :=[...] int{99:-1} // assigning number at the 99th position which is the last element
	fmt.Println(d[0])
	fmt.Println(d[99])
	fmt.Println("Length of array d = ",len(d))

	// multidimensional arrays
	var twoD [4][10] int 
	for i:=0;i<4;i++{
		for j:=0;j<10;j++{
			twoD[i][j] =(i+1) * (j+1)
		}
		fmt.Println("Row",i,":",twoD[i])
	}
	fmt.Println("All at once: ",twoD)

	//slicers
	months :=[...]string{"jan","feb","mar","apr","may","jun","jul","aug","sept","oct","nov","dec"}
	fmt.Println("Length of month=",len(months),"Capacity=",cap(months))
	q1 := months[0:3]
	q2 := months[3:6]
	q3 := months[6:9]
	q4 := months[9:12]
	fmt.Println(q1,len(q1),cap(q1))
	fmt.Println(q2,len(q2),cap(q2))
	fmt.Println(q3,len(q3),cap(q3))
	fmt.Println(q4,len(q4),cap(q4))

	//extending slicer
	q2Extended := q2[:6]
	fmt.Println(q2Extended,len(q2Extended),cap(q2Extended))

	//appending
	var v[]int
	for i:=0;i<10;i++{
		v = append(v,i)
		fmt.Printf("%d\tcap=%d\t%v\n",i,cap(v),v)
	}

	//remove
	letters := []string{"a","b","c","d","e"}
	remove := 3

	if remove < len(letters){
		fmt.Println("Original",letters,"Remove",letters[remove])
		letters =append(letters[:remove],letters[remove+1:]...)
		fmt.Println("After",letters)

	}

	//not using copy
	fmt.Println("Before", letters)

    // slice1 := letters[0:2]
    slice2 := letters[1:4]

    // slice1[1] = "Z"

    fmt.Println("After", letters)
    fmt.Println("Slice2", slice2)

	//after using copy
	fmt.Println("\nAfter using copy")
	sl1 := letters[0:2]
	sl2 := make([]string, 3)
    copy(sl2, letters[1:4])

    sl1[1] = "Z"

    fmt.Println("After", letters)
    fmt.Println("Slice2", sl2)

	// map: hash table has key and value pairs
	students := map[string]int{ // another way is to create map is, students := make(map[string]int)
		"john": 21,
		"kane":44,
	}
	fmt.Println(students)

	fmt.Println(students["vilas"]) // go won't get panick, instead gives default values if key in not present

	age, exist := students["binod"]
	if exist{
		fmt.Println("Binod is exist, and he is",age)
	}else{
		fmt.Println("Who is binod?")
	}

	//deleting item from map
	delete(students,"john")
	fmt.Println(students)

	//looping over map
	students["bakshi"]=3
	for name, age := range students{
		fmt.Printf("%s\t%d\n",name,age)// i've written Printf not Println observe.
	}
	// if you don't want keys then

	for name := range students{
		fmt.Printf("%s\n",name)// i've written Printf not Println observe.
	}

	//Structure one entity consist of different data types   
	type Emp struct{
		id int
		name string 
		branch string
		role string
	}
	employee := Emp{name:"vilas",branch:"sirsi",role:"dev"} // or employee := Emp{101,"vilas","sirsi","dev"}
	employee.id = 101  
	fmt.Println(employee)

	empCopy := &employee
	fmt.Println(empCopy)
	empCopy.name = "akash"
	fmt.Println(employee)

	//embed structures

	type Person struct{
		info Emp
		country string
		isAlive bool
	}
	var human Person
	human.info.name = "swathi"
	human.info.id = 104
	human.country = "India"
	human.isAlive =false

	fmt.Println(human)

}