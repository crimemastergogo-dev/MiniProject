#!/bin/bash

PWD=`pwd`
MAX_ARGUMENT=1
MIN_ARGUMENT=0
args=("$@")


if (($MIN_ARGUMENT == $#)) 
then
    echo "Please Pass Argument"
    echo "Argument  -AS  : For Strict Alternating String App"
elif(($MAX_ARGUMENT != $#))
then
    echo "Please Pass only One Argument"
    echo "Argument  -AS  : For Strict Alternating String App"
else
    case ${args[0]} in
        "-AS")
            echo Generating FSM for Strict Alternating string
            cd $PWD/../
            #make clean
            #make
            cd $PWD/bin
            echo "--------------INITIATING FSM-----------------" 
            #./StrictAlternateSTring
            ;;
        *)
            echo "Wrong Argument is Passed Plese select from the below list"
            echo "Argument  -AS  : For Strict Alternating String App"
            ;;
    esac
fi
