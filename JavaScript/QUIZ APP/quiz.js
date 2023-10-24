const quizcontainer=document.getElementById('quiz');
const  questionElement=document.getElementById('question');
const optionsElement=document.getElementById('options');
const nextBtn=document.getElementById('nextbutton');
const resetBtn=document.getElementById('resetbutton');
const results=document.getElementById('resultcontainer');
const timerElement = document.getElementById('timer');
const timerDuration = 10; // Timer duration in seconds
let remainingTime = timerDuration;
let timerInterval;

function startTimer() {
    timerInterval = setInterval(updateTimer, 1000);
  }
  function updateTimer() {
    if (remainingTime > 0) {
      remainingTime--;
      timerElement.textContent = `Time Left: ${remainingTime} seconds`;
    } else {
      clearInterval(timerInterval);
      timerElement.textContent = 'Times up!';
      results.innerText = 'Time\'s up!';
  
      // Delay moving to the next question by 3 seconds
      setTimeout(nextQuestion, 500);
    }
  }
const myquestions=[
    {
        question:'What does HTML stand for?',
        options:['(a) Hyper Text Markup Language',
            '(b) High-level Text Manipulation Language',
            '(c) Hyperlink and Text Markup Language',
            '(d) Hyper Transfer Markup Language'
            
            ],
        correctAnswer:'(a) Hyper Text Markup Language'
    },
    
    {
        question: 'Which of the following is NOT a programming language',
        options: ['(a) Java', '(b) HTML', '(c) Python', '(d) JavaScript'],
        correctAnswer: '(b) HTML'
      },
      {
        question: 'Which programming paradigm focuses on reusability and separating concerns into classes and objects?',
        options: ['(a) Imeerative', '(b) OOPS', '(c) Functional', '(d) Procedural'],
        correctAnswer: '(b) HTML'
      },
      {
        question: 'What does CSS stand for?',
       
        options: [
            '(a) Computer Style Sheets',
            '(b) Creative Styling System',
            '(c) Cascading Style Sheets',
            '(d) Colorful Styling Solutions'],
        correctAnswer: '(c) Cascading Style Sheets'
      },
      {
        question: 'In JavaScript, which keyword is used to declare a variable?',
        options: ['(a) var',
        '(b) int',
        '(c) string',
        '(d) declare'],
        correctAnswer: '(a) var'
      },
      {


question: 'What data type would you use to store whole numbers in Python?',
        options: ['(a) integer',
        '(b) double',
        '(c) char',
        '(d) boolean'],
        correctAnswer: '(a) integer'
      },
      {
        question: 'Which operator is used for exponentiation in many programming languages?',
        options: ['(a) +',
        '(b) *',
        '(c) ^',
        '(d) /'],
        correctAnswer: '(c) ^'
      },
      {
        question: 'Which of the following is an example of a backend programming language?',
        options: ['(a) HTML',
        '(b) CSS',
        '(c) Python',
        '(d) jQuery'],
        correctAnswer: '(c) Python'
      },
      {
        question: 'Which programming language is known for its speed and is often used in systems programming?',
        options: ['(a) Java',
        '(b) Ruby',
        '(c) C++',
        '(d) PHP'],
        correctAnswer: '(c) C++'
      },
      {
        question: 'What does SQL stand for?',
        options: ['(a) Structured Query Language',
        '(b) Simple Query Language',
        '(c) Standard Question Language',
        '(d) System Query Language'],
        correctAnswer: '(a) Structured Query Language'
      },
      {
        question: 'Which type of loop is executed at least once, even if the condition is false?',
        options: ['(a) for loop',
        '(b) while loop',
    
        '(c) do-while loop',
        '(d) repeat-until loop'
        ],
        correctAnswer: '(c) do-while loop'
      },
      {
        question: 'What is the result of 5 + "10" in JavaScript?',
        options: ['(b) 15',
        '(c) 510',
        '(d) 510 (as a string)',
        '(a) Error'
        ],
        correctAnswer: '(d) 510 (as a string)'
      },
      {
        question: 'Which data structure follows the Last-In-First-Out (LIFO) principle?',
        options: ['(a) Queue',
        '(b) Linked List',
        '(c) Stack',
        '(d) Array'],
        correctAnswer: '(c) Stack'
      },
      {
        question: 'What is the purpose of version control systems like Git?',
        options: ['(a) Managing databases',
        '(b) Tracking changes in source code',
        '(c) Optimizing website performance',
        '(d) Creating graphical user interfaces',],
        correctAnswer: '(b) Tracking changes in source code'
      },
      {
        question: 'What does API stand for?',
        options: ['(a) Application Protocol Interface',
        '(b) Application Programming Interface',
        '(c) Advanced Programming Interface',
        '(d) Algorithmic Programming Interface'],
        correctAnswer: '(b) Application Programming Interface'
      },
      {
        question: 'Which sorting algorithm has an average and worst-case time complexity of O(n log n)?',
        options: ['(a) Bubble sort',
        '(b) Insertion sort',
        '(c) Quick sort',
        '(d) Selection sort'],
        correctAnswer: '(c) Quick sort'
      },
      {
        question: 'What does DRY stand for in software development?',
        options: ['(a) Dont Reveal Yourself',
        '(b) Dont Repeat Yourself',
        '(c) Develop, Review, Yield',
        '(d) Debug, Refactor, Yield'],
        correctAnswer: '(c) Develop, Review, Yield'
      },
      {
        question: 'In object-oriented programming, what is the process of creating a new instance of a class called?',
        options: ['(a) Inheritance',
        '(b) Polymorphism',
        '(c) Encapsulation',
        '(d) Instantiation'],
        correctAnswer: '(d) Instantiation'
      },
      {
        question: 'Which keyword is used to define a function in Python?',
        options: ['(a) def',
        '(b) function',
        '(c) define',
        '(d) func'],
        correctAnswer: '(a) def'
      },
      {
        question: 'Which of the following is NOT a valid JavaScript variable name?',
        options: ['(a) myVariable',
        '(b) 123variable',
        '(c) _variable',
        '(d) $variable'
        ],
        correctAnswer: '(b) 123variable'
      }
];

let currentQuesindex=0;
function displayQuiz(index) {
    const currentQuestion=myquestions[index];
    const questionNumber=index+1;
    questionElement.textContent=`Question ${questionNumber}:${currentQuestion.question}`;
    optionsElement.innerHTML='';
    currentQuestion.options.forEach((option) => {
        const optionElement=document.createElement('button');
        optionElement.textContent=option;
        optionElement.addEventListener('click',()=>checkAnswer(option,currentQuestion.correctAnswer));
        optionsElement.appendChild(optionElement);
    });
    results.innerText=' ';
// setTimeout(nextQuestion,5000);
}

let numcorrect=0;

function checkAnswer(selectedOption,correctAnswer) {
// let numcorrect=0;

    if (selectedOption === correctAnswer) {
        numcorrect++;
        results.innerText="COREECT ANSWER MOVE TO NEXT";

        results.style.color="green";
     }
     else{
        results.innerText="WRONG ANSWER RETRY";
        results.style.color="red";

     }
     clearInterval(timerInterval); // Clear the timer interval
     timerElement.textContent = ''; // Clear the timer display
     setTimeout(nextQuestion, 3000); // Delay moving to the next question by 3 seconds
   }
    
    function nextQuestion() {
      
        currentQuesindex++;
        if (currentQuesindex<myquestions.length) {
            displayQuiz(currentQuesindex);

        }
        else{
            results.innerText=`QUIZ IS COMPLETED YOUR TOTAL SCORE IS ${numcorrect} out of ${myquestions.length}`
       results.style.color="white"
        }
       remainingTime = timerDuration; // Reset the timer
        displayQuiz(currentQuesindex);
        startTimer(); // Start the timer for the next question
    }
    function resetQuiz() {
        currentQuesindex=0;
        displayQuiz(currentQuesindex);

    }
    nextBtn.addEventListener('click',nextQuestion);
    resetBtn.addEventListener('click',resetQuiz);
    displayQuiz(currentQuesindex);