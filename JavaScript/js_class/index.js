class Animal {
  constructor(name = "", age = 0, isMammal = true) {
    this.name = name;
    this.age = age;
    this.isMammal = isMammal;
  }
}
class Rabbit extends Animal {
  constructor(name, age, isMammal) {
    super(name, age, (isMammal = true));
    this.isMammal = isMammal;
    this.age = age;
  }
  eat() {
    return `${this.name} is eating`;
  }
}
class Eagle extends Animal {
  constructor(name, age, isMammal) {
    super(name, age, (isMammal = false));
    this.isMammal = isMammal;
    this.age = age;
  }
  fly() {
    return `${this.name} is flying`;
  }
}
let myRabbit = new Rabbit("Labi", 2);
console.log(myRabbit.eat());

let myEagle = new Eagle("Elo", 4);
console.log(myEagle.fly());
