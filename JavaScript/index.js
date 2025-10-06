const tableBody = document.getElementById("tableBody");

const array = [
    {
        "name": "Jagarala Hammad Imran",
        "age": "19",
        "email": "jagralahammad00@gmail.com"
    },
    {
        "name": "Maknojiya Asrar Jabir",
        "age": "20",
        "email": "asrarjabir@gmail.com"
    },
    {
        "name": "Sunasara Alkama Imran",
        "age": "21",
        "email": "sunasaraalkama@gmail.com"
    }
]

tableBody.innerHTML = array.map((user) => 
    `<tr>
       <td>${user.name}</td>
       <td>${user.age}</td> 
       <td>${user.email}</td>
    </tr>`
).join("")