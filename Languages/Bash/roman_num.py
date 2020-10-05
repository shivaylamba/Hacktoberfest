#!/bin/bash

# *************************************************************************
#
#     This is a bash "Roman to number" code.
#
#     @ecwolf
#
# *************************************************************************

roman=$(echo $1)

[[ "${roman//[IVXLCDM]/}" == "" ]] || {
    echo invalid number;
    exit 1;
}

number=$(echo ${roman} |
    sed 's/CM/DCD/g' | sed 's/M/DD/g'    |
    sed 's/CD/CCCC/g'| sed 's/D/CCCCC/g' |
    sed 's/XC/LXL/g' | sed 's/C/LL/g'    |
    sed 's/XL/XXXX/g'| sed 's/L/XXXXX/g' |
    sed 's/IX/VIV/g' | sed 's/X/VV/g'    |
    sed 's/IV/IIII/g'| sed 's/V/IIIII/g' |
    tr -d '\n'       | wc -m
)

echo ${roman} is ${number}
