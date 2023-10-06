interface Params{
    arr:number[],
    target:number,
}

const arr:number[] = [2,4,6,8];
const target:number = 6;



function binarySearch({arr,target}:Params){
    var start:number = 0;
    var mid:number = 0;
    var end:number = arr.length -1;

    while(start<end){
        mid = (start+end)/2;
        if(arr[mid] === target){
            return mid;
        }

        if(arr[mid] > target){
            end = mid;
        }else{
            start = mid +1;
        }
    }
    return start;
}

console.log(binarySearch({arr,target}));