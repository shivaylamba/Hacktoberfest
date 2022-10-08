window.onload = () => {
    document.querySelector('input').value = '';
}

let qrCode = document.querySelector('#qrcode');
let userInput = document.querySelector('input');
let genButton = document.querySelector('button');

genButton.addEventListener("click", () => {
    let apiURL = `https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=${userInput.value}`;

    if (userInput.value.length == 0) {
        qrCode.style.display = "none";
        alert("Please input something!");
    } else {
        qrCode.src = apiURL;
        qrCode.style.display = "block";
    }
});