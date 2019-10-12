const reverse = (integer) => {
    const newInt =  integer
        .toString()
        .split("")
        .reverse()
        .join("")
    return parseInt(newInt) * Math.sign(integer);
}
