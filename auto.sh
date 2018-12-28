make
./geninput
for program in fgetc
do
	echo -e "START: ${program}"
	./${program} input.txt
	echo -e "FINISH: ${program}\n\n"
done
