# Define the class

class Car:
    def __init__(self, model, speed):
        self.model = model
        self.speed = speed

    def engine(self, on = False):
        print(f"Turning engine {'on' if on else 'off'}")

    def stop(self):
        print("Braking...")

    def drive(self):
        print(f"Driving at {self.speed} MPH")

# Create the object    
car = Car("SSC Tuatara", 316)
# Print the class variable
print("Car model: ", car.model)
# Call the class method
car.engine(True)
car.drive()
car.stop()
car.engine(False)
