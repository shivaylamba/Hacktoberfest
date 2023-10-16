// Simple To-Do List Application in JavaScript

const toDoList = [];

function addTask(task) {
  toDoList.push(task);
  console.log(`Task "${task}" has been added to the list.`);
}

function removeTask(task) {
  const taskIndex = toDoList.indexOf(task);
  if (taskIndex !== -1) {
    toDoList.splice(taskIndex, 1);
    console.log(`Task "${task}" has been removed from the list.`);
  } else {
    console.log(`Task "${task}" not found in the list.`);
  }
}

function displayTasks() {
  console.log("To-Do List:");
  toDoList.forEach((task, index) => {
    console.log(`${index + 1}. ${task}`);
  });
}

// Usage
addTask("Buy groceries");
addTask("Finish homework");
addTask("Go for a run");
displayTasks();

removeTask("Finish homework");
displayTasks();
