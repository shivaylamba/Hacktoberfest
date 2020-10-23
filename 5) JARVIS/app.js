const btn = document.querySelector('.talk');
const content = document.querySelector('.content');

//
const Hi = [
    'Hi Sir',
    'Hi, good to see you sir.'
];
const name = [
    'Hi, my name is Jarvis',
    'Im Jarvis.'
];
const more = [
    'Im Jarvis the creation of Devraj. Devraj is a web developer and a programmer if you want to know more about him visit his personal website, devrajchatribin.netlify.app'
];
const author = [
    'Im Jarvis the creation of Devraj.',
    'Sir Devraj made me'
];
const greetings = [
    'Hi! Im good',
    'Im good, Hope you are good too',
    'leave me alone',
    'why do you even care?'
];

const weather = [
    'weather is fine',
    'weather is fine but you need to stay home'
];

const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
const recognition = new SpeechRecognition();

recognition.onstart = function () {
    console.log('Jarvis is activated, you can speak to microphone.');
}

recognition.onresult = function (event) {
    const current = event.resultIndex;

    const transcript = event.results[current][0].transcript;
    content.textContent = transcript;
    readOutLoud(transcript);
};

//add the listener to the btn

btn.addEventListener('click', () => {
    recognition.start();
});

function readOutLoud(message) {
    const speech = new SpeechSynthesisUtterance();

    speech.text = 'i dont know what you said';

    if (message.includes('hi')) {
        const finalText = Hi[Math.floor(Math.random() * Hi.length)];
        speech.text = finalText;
    }
    if (message.includes('name')) {
        const finalText = name[Math.floor(Math.random() * name.length)];
        speech.text = finalText;
    }
    if (message.includes('who made you')) {
        const finalText = author[Math.floor(Math.random() * author.length)];
        speech.text = finalText;
    }
    if (message.includes('how are you')) {
        const finalText = greetings[Math.floor(Math.random() * greetings.length)];
        speech.text = finalText;
    }
    if (message.includes('weather')) {
        const finalText = weather[Math.floor(Math.random() * weather.length)];
        speech.text = finalText;
    }
    if (message.includes('about you')) {
        const finalText = more[Math.floor(Math.random() * more.length)];
        speech.text = finalText;
    }


    speech.volume = 10;
    speech.rate = 1;
    speech.pitch = 1;

    window.speechSynthesis.speak(speech);
}