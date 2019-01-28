#!/bin/bash
i=1
while [ $i -le $# ]
do
	enscript -C --margins=50:50:50:50 ${!i} -o ${!i}.ps
	ps2pdf ${!i}.ps
	rm ${!i}.ps
	i=$((i + 1))
done
