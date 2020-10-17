const https = require('https')
const API_URL = 'https://api.chucknorris.io/jokes/random'

/**
 * To run this you will need node installed
 * Run by executing `node chuck-norris-jokes.js`
 * @author milos5593
 */
function GET_JOKES() {
    const req = https.get(API_URL, (res) => {
        res.on('data', (d) => {
            console.log(JSON.parse(d.toString()).value)
        })
    })

    req.on('error', (error) => {
        console.error(error)
    })

    req.end()
}

GET_JOKES()
