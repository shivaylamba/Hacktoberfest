let arr = [0, 1, 0, 1, 0, 1, 0, 1];

const checkNumber = function (arr = []) {
    let flag = true;
    arr.map((val) => {
        if ((val > 1) && (val < 0)) {
            flag = false;
        }
    })
    return flag;
}

const calculate = function (arr = []) {
    let arrNew = [];
    let decimal = 0;
    arr.map((val, index, arr) => {
        let temp = 1;
        for (let i = 0; i < (arr.length - index - 1); i++) {
            temp *= 2;
        }
        arrNew[index] = temp;
    })

    arrNew.map((val, i) => {
        decimal += val * arr[i];
    })
    return decimal;
}

const main = function (arr) {
    const flagNumber = checkNumber(arr);
    if (!flagNumber) {
        console.log("Nomor yang dimasukkan salah");
        return false;
    }
    const arrNew = calculate(arr);
    console.log(arrNew);

}

main(arr);