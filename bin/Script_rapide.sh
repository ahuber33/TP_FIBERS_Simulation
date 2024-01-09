 #!/bin/bash


for (( i=200 ; i<=1000 ; i++ ))
do
    while [[ $(pgrep -x TPSim | wc -l) -gt 7 ]]
    do
	sleep 10
    done
    ./TPSim a_${i} 100 vrml.mac &
    sleep 5
    done
