const socket = io(`http://localhost:80`);

const form  = document.getElementById('send-cotainer')
const messageInput = document.getElementById('messageinp')
const messageContainer = document.querySelector('.container')
let alert = document.getElementById('alert')
var audio = new Audio('essentials/tone.mp3')

 
const append = (message,postiton) =>{
    const messageElement = document.createElement('div');
    messageElement.innerText = message;
    messageElement.classList.add('message');
    messageElement.classList.add(postiton);
    messageContainer.append(messageElement);
    if(postiton=='left')
    {
        audio.play()
    }

}

btn.addEventListener('click',(e)=>{
    e.preventDefault();
    const message = messageInput.value;
    append(`${message}`,'right');
    socket.emit('send',message);
    messageInput.value = ''
})

const name = prompt('Enter Your Name To Join');
socket.emit('new-user-joined',name);

socket.on('user-joined', name=>{
    alert.innerText = `${name} joined the chat`
    $('alert').alert('show')
});

socket.on('recieve', data=>{
    append(`${data.name} : ${data.message}`,'left')  
});


