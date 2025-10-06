// Day 27 : project 4 - Task Management APP
// Tasks/Activities:

// Activity 1: Setting Up the project
// Task 1: Initialize a new project directory and set up the basic HTML structure for the task management app
// Task 2: Add basic CSS file to style the task management app including a container for displaying tasks and aform for adding new tasks

// Activity 2: Creating Task
// Task 3: Add form to the HTML structure with fields for enterung task details (e.g, title description , due date), style the form using css
// Task 4: write a script to handle form submission creating a new task object and adding it to an array of tasks Display the new task in the task list
let tasks = [];
let currentTaskIndex = null;

document.getElementById('task-form').addEventListener('submit', (e) => {
    e.preventDefault();
    let title = document.getElementById('title').value;
    let description = document.getElementById('description').value;
    let dueDate = document.getElementById('due-date').value;

    if (currentTaskIndex !== null) {
        // Update the existing task
        tasks[currentTaskIndex] = {
            title,
            description,
            dueDate
        };
        currentTaskIndex = null; // Reset after updating
    } else {
        // Add a new task
        let newTask = {
            title,
            description,
            dueDate
        };
        tasks.push(newTask);
    }

    displayTasks();
    document.getElementById('task-form').reset();
});

// Activity 3: reading and Displaying Tasks
// Task 5: Write a function too iterate over the array of tasks and display each task in the task list . inlude task details when the Edit button is clicked
function displayTasks() {
    let taskList = document.getElementById('task-list');
    taskList.innerHTML = '';

    tasks.forEach((task, index) => {
        let taskItem = document.createElement('li');
        taskItem.className = 'task-item';
        taskItem.innerHTML = `
            <h2 class="task-title">${task.title}</h2>
            <p class="task-description">${task.description}</p>
            <p class="task-due-date">${task.dueDate}</p>
            <button class="edit-button" data-index="${index}">Edit</button>
            <button class="delete-button" data-index="${index}">Delete</button>
        `;
        taskList.appendChild(taskItem);
    });
}
// Task 6: Style the task list using CSS to make it visually appealing

// Activity 4: updating Tasks
// Task 7: Add an "Edit" button to each task item in the task list . write a function to populate the form with the task details when the "Edit" button is clicked
document.getElementById('task-list').addEventListener('click', (e) => {
    if (e.target.classList.contains('edit-button')) {
        // Edit functionality
        currentTaskIndex = e.target.getAttribute('data-index');
        let task = tasks[currentTaskIndex];
        document.getElementById('title').value = task.title;
        document.getElementById('description').value = task.description;
        document.getElementById('due-date').value = task.dueDate;
        document.getElementById('submit-button').textContent = 'Save Task'; // Change button text to "Save Task"
    } else if (e.target.classList.contains('delete-button')) {
        // Delete functionality
        let taskIndex = e.target.getAttribute('data-index');
        if (confirm("Are you sure you want to delete this task?")) {
            tasks.splice(taskIndex, 1);
            displayTasks();
        }
    }
});
// Task 8: write a function to update the task object in an array and refresh the task list display after edditing task
document.getElementById('task-form').addEventListener('submit', (e) => {
    e.preventDefault();
    let title = document.getElementById('title').value;
    let description = document.getElementById('description').value;
    let dueDate = document.getElementById('due-date').value;
    let taskIndex = tasks.findIndex((task) => task.title === document.getElementById('title').getAttribute('data-task-title'));
    if (taskIndex !== -1) {
        tasks[taskIndex].title = title;
        tasks[taskIndex].description = description;
        tasks[taskIndex].dueDate = dueDate;
        displayTasks();
		// Activity 5: Deleting Tasks
     // Task 9: Add a "Delete" button to each task item in the task list . write a function to remove the task from the array and refresh the task list display when the "Delete button clicked"
     // Task 10: Add a confirmation dialog before deleting a task to prevent accidental deletions

        document.getElementById('title').removeAttribute('data-task-title');
        document.getElementById('task-form').reset();
    }
});


