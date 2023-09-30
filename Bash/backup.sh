#!/bin/bash

# this script backup all the files in the provided directory that are modified within the last week in /root/backup/ directory
# run this script as sudo
# for example: ./backup.sh /etc/ will backup all the files in the /etc/ directory that are modified within last week
find $1 -mtime -7 -type f -exec cp {} /root/backup \;