// The getElementsByTagName method returns an HTMLCollection, so we transform it into an array to make it iterable with a for loop
const tiles = Array.from(document.getElementsByTagName('td'));

// This variable allows us to alternate between players
let isX = true;

for (let tile of tiles) {
    // Make every <td> element clickable
    tile.addEventListener('click', () => {

        // We first check if the tile is empty
        if (!tile.innerHTML) {

            tile.innerHTML = isX ? 'X' : 'O';

            // Check if a player has won every time one of them takes a turn
            isX ? checkWin('X') : checkWin('O');

            isX = !isX;
        }
    });
}

// We store the indexes of all the possible win condtions for a given player in an array. This allows us to iterate over it
const winConditions = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
]

function checkWin(XorO) {
    for (let win of winConditions) {
        if (
            tiles[win[0]].innerHTML === XorO
            && tiles[win[1]].innerHTML === XorO
            && tiles[win[2]].innerHTML === XorO
        ) {
            document.body.innerHTML = `${XorO} has won!`;
            // Once a player has won, we don't need to continue iterating over the win conditions so we break out of the loop
            break;
        };
    }
}
