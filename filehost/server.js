const express = require(`express`);
const fs = require(`fs`);
// const { auth } = require(`./auth.json`)
const d = new Date()
const app = express();
const port = 3000; // you can change the port to whatever you would like!
// const files = fs.readdirSync(`./files`);
app.use(express.json());

function objToString(obj) {
    return Object.entries(obj).reduce((str, [p, val]) => {
        return `${val}`;
    }, '');
};

app.post('/upload', (req, res) => {
    const month = d.getMonth() + 1
    const date = d.getDate() + `-` + month + `-` + d.getFullYear()
    const r = Math.random().toString(36).slice(-8) + `-` + date;
    const b = objToString(req.body)
    const body = b.split(` `)
    const file = `./files/${r}.txt`
        console.log(`Writen "${body}" to ${file}.`);
        fs.appendFile(file, body[1], err => {
            if (err) {
                console.error(err);
            }
            else {
                res.send(`Writen to ${file}: ${body[1]}`);
            }
        });
    }
});

app.get('/upload', (req, res) => {
    res.send("This api endpoint is POST-ONLY.");
});

// app.get('/view', (req, res) => {
//     if (req.originalUrl !== `/view`) {
//         for (i = 0; 0 < files.length; i++) {
//             const link = req.originalUrl + files[i];
//             console.log(link);
//             if (req.originalUrl == link) {
//                 res.sendFile(link, { root: `./files` })
//             };
//         }
//     } else {
//         res.send(`You can view these files: ${files}`);
//     }
// }); it fills up your ram so dont uncomment and then go to localhost:3000/view :troll:

app.listen(port, () => {
    console.log(`Ready for use! Visit the page on localhost:${port}`);
});
