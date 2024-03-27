#!/bin/bash
PID=$(lsusb)
if [ -z "$PID" ];
then
echo "lusb"
fi